# Doodle Jump 🎮
*A C++ implementation of the classic Doodle Jump game with sprites, sounds, and multiple platform types.*  

⚠️ **Note:** This project was developed for educational purposes and may still contain bugs or incomplete features.  

---

## 📖 Overview
This project is a recreation of the popular **Doodle Jump** game, built in C++ as part of an advanced programming course.  
The player controls a character that continuously jumps upward, avoiding falling while landing on platforms, collecting power-ups, and achieving the highest possible score.  

---

## Features
- Playable Doodle Jump clone in C++  
- Multiple platform types (static, disappearing, moving, vertical/horizontal)  
- Power-ups: springs, jetpacks, etc.  
- Sound effects (jump, break, spring, jetpack)  
- Sprites and animations for platforms, bonuses, and the player  
- Includes assets (sprites, sounds, fonts)  

---

## Getting Started

### 1. Prerequisites
- C++17 or later  
- [CMake](https://cmake.org/)  
- [SFML library](https://www.sfml-dev.org/) (for graphics, audio, and window handling)  

### 2. Build
```bash
git clone https://github.com/skipmare/doodle-jump.git
cd doodle-jump-master
mkdir build && cd build
cmake ..
make
