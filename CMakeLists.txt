cmake_minimum_required(VERSION 3.20)
project(2024_project_skipmare LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

find_package(SFML COMPONENTS graphics audio QUIET)
if (NOT SFML_FOUND)
    include(FetchContent)
    FetchContent_Declare(SFML
            GIT_REPOSITORY https://github.com/SFML/SFML.git
            GIT_TAG 2.6.2
            GIT_SHALLOW ON)
    FetchContent_MakeAvailable(SFML)
endif()

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
        src/Logic/Entities/Score.cpp
        src/GameRepresentation/View/ScoreView.cpp
        src/Logic/DifficultySettings/DifficultySettings.cpp
        src/Logic/DifficultySettings/MEDIUM.cpp
        src/Logic/DifficultySettings/HARD.cpp
        src/Logic/DifficultySettings/EASY.cpp
)

target_link_libraries(2024_project_skipmare PRIVATE sfml-graphics sfml-audio)
target_compile_features(2024_project_skipmare PRIVATE cxx_std_17)

target_include_directories(2024_project_skipmare PRIVATE
        src/GameRepresentation
        src/GameRepresentation/Camera
        src/GameRepresentation/Factory
        src/GameRepresentation/View
        src/Logic/Entities
        src/Logic/GameLogic
        src/Logic/Patterns
        src/Logic/Utilities
)

if (MSVC)
    target_compile_options(2024_project_skipmare PRIVATE /W4)
else()
    target_compile_options(2024_project_skipmare PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_custom_command(TARGET 2024_project_skipmare POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/Assets"
        "$<TARGET_FILE_DIR:2024_project_skipmare>/Assets")

install(TARGETS 2024_project_skipmare RUNTIME DESTINATION .)
install(DIRECTORY Assets DESTINATION .)

include(CTest)
if (BUILD_TESTING)
    add_executable(doodle_jump_logic_tests
            tests/LogicTests.cpp
            src/GameRepresentation/Camera/Camera.cpp
            src/Logic/Entities/Entity.cpp
            src/Logic/Entities/BGtile.cpp
            src/Logic/Entities/Bonuses/Bonus.cpp
            src/Logic/Entities/Bonuses/Jetpack.cpp
            src/Logic/Entities/Bonuses/Spring.cpp
            src/Logic/Entities/Player.cpp
            src/Logic/Entities/Score.cpp
            src/Logic/Entities/Platforms/Platform.cpp
            src/Logic/Entities/Platforms/StaticPlatform.cpp
            src/Logic/Entities/Platforms/DisappearingPlatform.cpp
            src/Logic/Entities/Platforms/HorizontalPlatform.cpp
            src/Logic/Entities/Platforms/VerticalPlatform.cpp
            src/Logic/GameLogic/World.cpp
            src/Logic/Patterns/Observer.cpp
            src/Logic/Patterns/Subject.cpp
            src/Logic/Utilities/Random.cpp
    )
    target_include_directories(doodle_jump_logic_tests PRIVATE
            src/GameRepresentation
            src/GameRepresentation/Camera
            src/Logic/Entities
            src/Logic/Entities/Bonuses
            src/Logic/Entities/Platforms
            src/Logic/GameLogic
            src/Logic/Patterns
            src/Logic/Utilities
    )
    target_compile_features(doodle_jump_logic_tests PRIVATE cxx_std_17)
    add_test(NAME logic_regressions COMMAND doodle_jump_logic_tests)
endif()
