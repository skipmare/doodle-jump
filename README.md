# Doodle Jump

A C++17/SFML arcade platformer inspired by Doodle Jump. The project separates
gameplay logic from rendering, generates reachable platform layouts, and ships
with regression tests for the systems that matter most during play.

## Features

- Static, horizontal, vertical, and disappearing platforms
- Spring and jetpack power-ups
- Responsive arcade movement with automatic jumping
- A mathematically reachable climbing path with optional challenge platforms
- Gradually increasing difficulty based on score
- Sound effects, sprites, and a persistent best score during a session
- A CMake build that can use an installed SFML or fetch SFML 2.6.2 automatically

## Quick Start

Requirements:

- CMake 3.20 or newer
- A C++17 compiler
- Git and an internet connection when SFML is not already installed

```bash
git clone https://github.com/skipmare/doodle-jump.git
cd doodle-jump
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
```

Run the game on macOS or Linux:

```bash
./build/bin/2024_project_skipmare
```

With a multi-config generator such as Visual Studio, build with
`--config Release` and run
`build/bin/Release/2024_project_skipmare.exe`.

The build copies `Assets/` next to the executable, so run the built copy rather
than moving the executable by itself.

## Controls

- `A` or `Left Arrow`: move left
- `D` or `Right Arrow`: move right
- Close the window to quit

The character jumps automatically when landing on a platform.

## How It Works

The project is split into two main layers:

```text
src/Logic/                 Entities, world generation, difficulty, and utilities
src/GameRepresentation/    SFML views, camera, factories, and game orchestration
Assets/                    Sprites, sound effects, and font files
tests/                     Headless gameplay regression tests
html/                      Generated Doxygen reference documentation
```

The logic layer owns movement, collisions, platform generation, scoring, and
difficulty. The representation layer observes those objects and translates
their state into SFML graphics and audio. Keeping those responsibilities apart
makes the core behavior testable without opening a game window.

## Tests

```bash
cmake -S . -B build -DBUILD_TESTING=ON
cmake --build build --parallel
ctest --test-dir build --output-on-failure
```

The regression suite exercises camera behavior, collision handling, platform
generation, bonuses, player state, and difficulty progression.

## Troubleshooting

- **CMake is downloading SFML:** this is expected when SFML 2 is not installed
  locally. Install your platform's SFML development package to avoid the fetch.
- **Assets fail to load:** launch the executable from its generated `build/bin`
  location and confirm that an `Assets` directory exists beside it.
- **No audio on Linux:** install your distribution's OpenAL development/runtime
  package, then configure the build again.

Generated API documentation is available by opening `html/index.html` locally.
