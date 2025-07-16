# CLI Game Implementation Plan

This document outlines the implementation plan and application skeleton for completing the Command-Line Interface (CLI) game, "Starter Quest."

## 1. High-Level Goal

The objective is to build a functional, text-based RPG adventure game. The player will be able to create a character, navigate a simple world, interact with scenarios, engage in combat, and progress through a story.

## 2. Current State

The project currently has a solid foundation for characters:
- A `Character` base class.
- A `CharacterClass` system with multiple implemented classes (`Warrior`, `Wizard`, `Rogue`, `Cleric`).
- A `main.cpp` file that handles initial character creation but lacks a game loop or story progression.
- A `GameScenario` struct that is defined but not used.

## 3. Proposed Application Skeleton

To create a playable game, we need to introduce a more structured architecture. The following classes and modules should be created to manage the game's state and logic.

### New Directory Structure

It is recommended to create a new `game` directory to house the core game logic files:

```
starter-quest/
├── game/
│   ├── Game.h
│   ├── Game.cpp
│   ├── StoryManager.h
│   ├── StoryManager.cpp
│   ├── EncounterManager.h
│   ├── EncounterManager.cpp
│   ├── InputHandler.h
│   ├── InputHandler.cpp
│   └── World.h
│   └── World.cpp
├── baseClasses/
├── characterClasses/
...
```

### Core Components

- **`Game` Class (`game/Game.h`, `game/Game.cpp`)**
  - **Purpose:** The central engine of the game. It will own the main game loop and manage the overall game state.
  - **Responsibilities:**
    - Initialize all game systems.
    - Contain the main `run()` method, which loops until the game ends.
    - Hold the player object and current game world state.
    - Process player input and delegate to other managers.
    - Check for win/loss conditions.

- **`World` Class (`game/World.h`, `game/World.cpp`)**
  - **Purpose:** Manages the game world, which is composed of interconnected locations.
  - **Responsibilities:**
    - Define a `Location` struct/class with a description, possible encounters, and connections to other locations (e.g., `north`, `south`).
    - Load the world map (from a file or hardcoded).
    - Keep track of the player's current location.
    - Handle player movement between locations.

- **`StoryManager` Class (`game/StoryManager.h`, `game/StoryManager.cpp`)**
  - **Purpose:** Manages quests, scenarios, and narrative progression.
  - **Responsibilities:**
    - Load `GameScenario` data (e.g., from hardcoded data, JSON, or text files).
    - Trigger scenarios based on the player's location or game state.
    - Present the player with story text and choices.
    - Process player choices and provide outcomes, including rewards.

- **`EncounterManager` Class (`game/EncounterManager.h`, `game/EncounterManager.cpp`)**
  - **Purpose:** Manages combat encounters.
  - **Responsibilities:**
    - Initiate combat between the player and one or more enemies (`Creature` objects).
    - Implement a turn-based combat loop.
    - Get player actions for combat (attack, defend, use item).
    - Control enemy AI (e.g., basic attacks).
    - Determine the outcome of combat (victory, defeat) and grant rewards (experience, items).

- **`InputHandler` Class (`game/InputHandler.h`, `game/InputHandler.cpp`)**
  - **Purpose:** A dedicated utility for parsing raw user input into game commands.
  - **Responsibilities:**
    - Read input from the console (`cin`).
    - Sanitize and parse the input into a standard command format (e.g., verb + noun).
    - Examples: `move north`, `attack goblin`, `take potion`, `look`.

## 4. Implementation Steps (What's Left)

Here is a step-by-step plan to build out the game.

### Milestone 1: Core Game Loop & Refactoring

1.  **Create `game` Directory:** Set up the new directory and empty `.h`/`.cpp` files for the classes listed above.
2.  **Refactor `main.cpp`:**
    - Move the character creation logic from `main()` into a new function, e.g., `setupPlayer()`.
    - The `main()` function should become very simple:
      ```cpp
      #include "game/Game.h"

      int main() {
        Game myGame;
        myGame.initialize();
        myGame.run();
        return 0;
      }
      ```
3.  **Implement the `Game` Class:**
    - Create the `initialize()` method to set up the game (e.g., call `setupPlayer()`).
    - Create the `run()` method with a simple loop: `while (isRunning) { ... }`.
    - Implement a basic input prompt inside the loop that takes a command and can exit the game (e.g., on "quit").

### Milestone 2: World Traversal

1.  **Implement `World` and `Location`:**
    - Define the `Location` struct inside `World.h`.
    - In `World.cpp`, create a small, hardcoded map of 2-3 locations (e.g., "Town Square," "Forest Path," "Cave Entrance").
    - Link them together (e.g., from Town Square, you can go `north` to Forest Path).
2.  **Integrate with `Game`:**
    - The `Game` class should have a `World` member object.
    - The game loop should print the description of the player's current location.
    - Implement `move <direction>` command parsing in the `InputHandler`.
    - Update the `Game` loop to call the `World` to change the player's location.

### Milestone 3: Story Scenarios

1.  **Flesh out `GameScenario`:** Add any necessary fields to the `GameScenario` struct in `main.cpp` (or move it to a more appropriate header).
2.  **Implement `StoryManager`:**
    - Create a hardcoded list of a few `GameScenario` objects.
    - Create a `triggerScenario()` method that the `Game` class can call when the player enters a specific location.
    - Implement the logic to display the scenario description and choices, and process the outcome.
3.  **Integrate with `Game`:**
    - In the `Game` loop, after moving, check if the new location has a scenario to trigger.

### Milestone 4: Combat

1.  **Implement `EncounterManager`:**
    - Design the `startCombat()` method, which takes the player and a vector of enemies.
    - Implement the turn-based loop: Player turn, then Enemy turn.
    - For the player's turn, prompt for "attack" or "defend."
    - For the enemy's turn, have it perform a basic attack against the player.
2.  **Integrate with `Game` and `World`:**
    - Add a list of possible encounters to the `Location` struct.
    - Modify the `Game` loop to have a chance of starting an encounter upon entering certain locations.
    - When an encounter is triggered, hand control over to the `EncounterManager`. Once combat is over, control returns to the main game loop.

This implementation plan provides a clear path forward for building out the "Starter Quest" CLI game. By tackling it in these milestones, you can incrementally build and test each part of the game.