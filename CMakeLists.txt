cmake_minimum_required(VERSION 3.28)
project(2024_project_skipmare LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

find_package(Freetype REQUIRED)
target_link_libraries(sfml-graphics PRIVATE Freetype::Freetype)


include_directories(
        src/GameRepresentation
        src/GameRepresentation/Camera
        src/GameRepresentation/Factory
        src/GameRepresentation/View
        src/Logic/Entities
        src/Logic/GameLogic
        src/Logic/Patterns
        src/Logic/Utilities
)

add_executable(2024_project_skipmare
        src/GameRepresentation/Camera/Camera.cpp
        src/GameRepresentation/Factory/ConcreteFactory.cpp
        src/GameRepresentation/View/BonusView.cpp
        src/GameRepresentation/View/EntityView.cpp
        src/GameRepresentation/View/PlatformView.cpp
        src/GameRepresentation/View/PlayerView.cpp
        src/GameRepresentation/Game.cpp
        src/Logic/Entities/BGtile.cpp
        src/Logic/Entities/Bonuses/Bonus.cpp
        src/Logic/Entities/Entity.cpp
        src/Logic/Entities/Platforms/Platform.cpp
        src/Logic/Entities/Player.cpp
        src/Logic/GameLogic/World.cpp
        src/Logic/Patterns/AbstractFactory.cpp
        src/Logic/Patterns/Observer.cpp
        src/Logic/Utilities/Random.cpp
        src/Logic/Utilities/Stopwatch.cpp
        main.cpp
        src/Logic/Entities/Platforms/StaticPlatform.cpp
        src/Logic/Entities/Platforms/VerticalPlatform.cpp
        src/Logic/Entities/Platforms/DisappearingPlatform.cpp
        src/Logic/Entities/Platforms/HorizontalPlatform.cpp
        src/Logic/Entities/Bonuses/Jetpack.cpp
        src/Logic/Entities/Bonuses/Spring.cpp
        src/Logic/Patterns/Subject.cpp
        src/GameRepresentation/View/BGtileView.cpp
        src/Logic/Entities/score.cpp
        src/GameRepresentation/View/ScoreView.cpp
)

target_link_libraries(2024_project_skipmare PRIVATE sfml-graphics)
target_compile_features(2024_project_skipmare PRIVATE cxx_std_17)