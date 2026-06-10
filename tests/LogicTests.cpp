#include "Camera.h"
#include "DisappearingPlatform.h"
#include "HorizontalPlatform.h"
#include "Jetpack.h"
#include "Player.h"
#include "Score.h"
#include "Spring.h"
#include "VerticalPlatform.h"
#include "World.h"
#include "Observer.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

namespace {
int failures = 0;

void expect(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << '\n';
        ++failures;
    }
}

template <typename PlatformRecords>
void expectReachableGeneration(const PlatformRecords& platforms, const std::string& context) {
    for (std::size_t i = 1; i < platforms.size(); ++i) {
        const auto& target = platforms[i];
        const bool reachableFromEarlierPlatform = std::any_of(
            platforms.begin(), platforms.begin() + static_cast<std::ptrdiff_t>(i),
            [&](const auto& source) {
                return World::isPlatformReachable(source.x, source.y, target.x, target.y);
            });
        expect(reachableFromEarlierPlatform, context + ": every platform should be reachable");
    }
}

class LogicFactory final : public AbstractFactory {
public:
    struct PlatformRecord {
        float x;
        float y;
        PlatformType type;
    };

    std::shared_ptr<Player> createPlayer(float x, float y) override {
        return std::make_shared<Player>(x, y);
    }

    std::shared_ptr<Platform> createPlatform(float x, float y, PlatformType type) override {
        platformYPositions.push_back(y);
        platforms.push_back({x, y, type});
        switch (type) {
            case PlatformType::STATIC:
                return std::make_shared<StaticPlatform>(x, y);
            case PlatformType::VERTICAL:
                return std::make_shared<VerticalPlatform>(x, y);
            case PlatformType::HORIZONTAL:
                return std::make_shared<HorizontalPlatform>(x, y);
            case PlatformType::DISAPPEARING:
                return std::make_shared<DisappearingPlatform>(x, y);
        }
        return nullptr;
    }

    std::shared_ptr<Bonus> createBonus(
        float x, float y, BonusType type, std::shared_ptr<Platform> platform) override {
        if (type == BonusType::SPRING) {
            return std::make_shared<Spring>(x, y, platform);
        }
        return std::make_shared<Jetpack>(x, y, platform);
    }

    std::shared_ptr<BGtile> createBGtile(float x, float y) override {
        return std::make_shared<BGtile>(x, y);
    }

    std::shared_ptr<Score> createScore(float x, float y) override {
        return std::make_shared<Score>(x, y);
    }

    std::vector<float> platformYPositions;
    std::vector<PlatformRecord> platforms;
};

class CountingObserver final : public Observer {
public:
    void update() override {
        ++updates;
    }

    int updates = 0;
};
}

int main() {
    Camera camera(500.0f, 800.0f);
    const auto screenPosition = camera.transform(120.0f, 350.0f);
    const auto worldPosition = camera.undotransform(screenPosition.first, screenPosition.second);
    expect(std::abs(worldPosition.first - 120.0f) < 0.001f, "camera x transform should round-trip");
    expect(std::abs(worldPosition.second - 350.0f) < 0.001f, "camera y transform should round-trip");

    Player player60Hz(100.0f, 0.0f);
    Player player120Hz(100.0f, 0.0f);
    for (int i = 0; i < 60; ++i) {
        player60Hz.update(1.0f / 60.0f);
    }
    for (int i = 0; i < 120; ++i) {
        player120Hz.update(1.0f / 120.0f);
    }
    expect(std::abs(player60Hz.getY() - player120Hz.getY()) < 3.0f,
           "gravity should be approximately frame-rate independent");

    Player movingPlayer60Hz(100.0f, 0.0f);
    Player movingPlayer120Hz(100.0f, 0.0f);
    for (int i = 0; i < 60; ++i) {
        movingPlayer60Hz.move(1, 1.0f / 60.0f);
    }
    for (int i = 0; i < 120; ++i) {
        movingPlayer120Hz.move(1, 1.0f / 120.0f);
    }
    expect(std::abs(movingPlayer60Hz.getX() - movingPlayer120Hz.getX()) < 2.0f,
           "horizontal movement should be frame-rate independent");

    Player responsivePlayer(100.0f, 0.0f);
    responsivePlayer.setMoveDirection(1);
    for (int i = 0; i < 6; ++i) {
        responsivePlayer.update(1.0f / 60.0f);
    }
    expect(responsivePlayer.getVelocityX() > 250.0f,
           "horizontal movement should accelerate quickly");
    expect(responsivePlayer.getX() > 112.0f,
           "horizontal input should move the player responsively");
    responsivePlayer.setMoveDirection(0);
    for (int i = 0; i < 8; ++i) {
        responsivePlayer.update(1.0f / 60.0f);
    }
    expect(std::abs(responsivePlayer.getVelocityX()) < 0.001f,
           "horizontal movement should stop quickly after releasing input");

    Player wrappingPlayer(531.0f, 0.0f);
    wrappingPlayer.setMoveDirection(1);
    wrappingPlayer.update(1.0f / 60.0f);
    expect(wrappingPlayer.getX() == -30.0f,
           "player should wrap cleanly after fully crossing the screen edge");

    Player jumpingPlayer(100.0f, 0.0f);
    jumpingPlayer.jump();
    float apexY = jumpingPlayer.getY();
    for (int i = 0; i < 120 && jumpingPlayer.getY() < 1.0f; ++i) {
        jumpingPlayer.update(1.0f / 120.0f);
        apexY = std::min(apexY, jumpingPlayer.getY());
    }
    expect(apexY < -195.0f && apexY > -220.0f,
           "normal jump height should stay near the tuned 210 pixel envelope");
    expect(jumpingPlayer.getVelocityY() <= Player::MaximumFallSpeed,
           "falling speed should be capped");

    Player boostedPlayer(100.0f, 100.0f);
    boostedPlayer.applyBonusEffect(BonusType::SPRING);
    expect(boostedPlayer.getVelocityY() == -1120.0f, "spring should boost the current jump immediately");
    expect(boostedPlayer.isJumping(), "spring should put the player in the jumping state");

    auto collisionFactory = std::make_shared<LogicFactory>();
    World collisionWorld(collisionFactory, 500.0f, 800.0f);
    auto collisionPlayer = collisionWorld.getPlayer();
    auto landingPlatform = std::make_shared<StaticPlatform>(100.0f, 200.0f);

    collisionPlayer->setPosition(163.0f, 140.0f);
    collisionPlayer->setVelocityY(300.0f);
    collisionPlayer->setFalling();
    collisionPlayer->update(1.0f / 30.0f);
    expect(!collisionWorld.checkCollision_player(landingPlatform),
           "the player's body should not land when the visible feet miss the platform");

    collisionPlayer->setPosition(161.0f, 140.0f);
    collisionPlayer->setVelocityY(300.0f);
    collisionPlayer->setFalling();
    collisionPlayer->update(1.0f / 30.0f);
    expect(collisionWorld.checkCollision_player(landingPlatform),
           "a visible foot touching the platform edge should still land");

    Player directionalFeet(200.0f, 100.0f);
    const BoundingBox rightFacingFeet = directionalFeet.getLandingBox();
    directionalFeet.setMoveDirection(-1);
    const BoundingBox leftFacingFeet = directionalFeet.getLandingBox();
    expect((rightFacingFeet.left + rightFacingFeet.right) / 2.0f < directionalFeet.getX() &&
               (leftFacingFeet.left + leftFacingFeet.right) / 2.0f > directionalFeet.getX(),
           "the landing box should follow the visible feet when the sprite turns");

    DisappearingPlatform platform(100.0f, 200.0f);
    platform.setHasCollided(true);
    platform.update(1.0f / 60.0f);
    expect(platform.isDisappeared(), "disappearing platform should record its disappeared state");
    expect(platform.getOutOfView(), "disappearing platform should be removed after a collision");
    expect(!platform.getCollidable(), "disappearing platform should stop colliding after it disappears");

    auto observedPlatform = std::make_shared<StaticPlatform>(100.0f, 200.0f);
    auto countingObserver = std::make_shared<CountingObserver>();
    observedPlatform->attach(countingObserver);
    observedPlatform->setPosition(120.0f, 180.0f);
    observedPlatform->update(1.0f / 60.0f);
    expect(countingObserver->updates == 0,
           "logic updates should not render entities before the frame is complete");
    observedPlatform->notify();
    expect(countingObserver->updates == 1,
           "an explicit render notification should draw an entity once");

    auto factory = std::make_shared<LogicFactory>();
    World world(factory, 500.0f, 800.0f);
    world.generateNewPlatforms();
    const bool generatedAboveInitialWorld = std::any_of(
        factory->platformYPositions.begin(), factory->platformYPositions.end(),
        [](float y) { return y < 0.0f; });
    expect(generatedAboveInitialWorld, "world should continuously generate platforms above the initial area");

    expectReachableGeneration(factory->platforms, "easy generation");

    std::vector<LogicFactory::PlatformRecord> safePath;
    std::copy_if(
        factory->platforms.begin(), factory->platforms.end(), std::back_inserter(safePath),
        [](const auto& platformRecord) { return platformRecord.type == PlatformType::STATIC; });
    for (std::size_t i = 1; i < safePath.size(); ++i) {
        expect(World::isPlatformReachable(
                   safePath[i - 1].x, safePath[i - 1].y, safePath[i].x, safePath[i].y),
               "the guaranteed static climbing path should remain continuously reachable");
    }
    expect(World::maximumReachableHorizontalDistance(220.0f) == 0.0f,
           "platforms above the normal jump apex should be rejected");

    auto difficultyFactory = std::make_shared<LogicFactory>();
    World difficultyWorld(difficultyFactory, 500.0f, 800.0f);
    difficultyWorld.setDifficulty(Difficulty::MEDIUM);
    difficultyWorld.genPlats(-400.0f, -1400.0f);
    difficultyWorld.setDifficulty(Difficulty::HARD);
    difficultyWorld.genPlats(-1400.0f, -2600.0f);
    expectReachableGeneration(difficultyFactory->platforms, "progressive difficulty generation");
    expect(difficultyWorld.getDifficulty().maxDistance <
               Player::NormalJumpSpeed * Player::NormalJumpSpeed / (2.0f * Player::NormalGravity),
           "hard mode vertical gaps should remain below the normal jump apex");
    expect(difficultyWorld.getDifficulty().maxHorizontalDistance <
               World::maximumReachableHorizontalDistance(difficultyWorld.getDifficulty().maxDistance),
           "hard mode horizontal gaps should remain inside the physical reach envelope");

    bool generatedChallengePlatform = false;
    for (int iteration = 0; iteration < 25; ++iteration) {
        auto randomizedFactory = std::make_shared<LogicFactory>();
        World randomizedWorld(randomizedFactory, 500.0f, 800.0f);
        randomizedWorld.setDifficulty(
            iteration % 2 == 0 ? Difficulty::MEDIUM : Difficulty::HARD);
        randomizedWorld.genPlats(-400.0f, -3000.0f);
        expectReachableGeneration(randomizedFactory->platforms, "randomized generation");
        generatedChallengePlatform = generatedChallengePlatform || std::any_of(
            randomizedFactory->platforms.begin(), randomizedFactory->platforms.end(),
            [](const auto& platformRecord) {
                return platformRecord.type != PlatformType::STATIC;
            });
    }
    expect(generatedChallengePlatform,
           "progressive difficulty should add reachable challenge platform variety");
    const auto generatedPlatformCount = factory->platformYPositions.size();
    for (int i = 0; i < 120; ++i) {
        world.generateNewPlatforms();
    }
    expect(factory->platformYPositions.size() == generatedPlatformCount,
           "platform generation should not grow while the camera is stationary");

    for (int i = 0; i < 600; ++i) {
        world.update(1.0f / 60.0f);
    }
    expect(world.getPlayer() != nullptr, "world should remain valid through repeated updates and restarts");

    if (failures == 0) {
        std::cout << "All logic regression tests passed\n";
    }
    return failures == 0 ? 0 : 1;
}
