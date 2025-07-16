# Starter Quest

Welcome to Starter Quest, a simple text-based role-playing game! This project is a demonstration of object-oriented programming in C++ and serves as a foundation for a more complex RPG.

## About the Project

Starter Quest allows you to create a character, choose a vocation, and embark on an adventure. It's built with C++ and uses a class-based system to define character types and their abilities.

## Getting Started

To get the project up and running on your local machine, follow these simple steps.

### Prerequisites

You will need a C++ compiler and CMake installed on your system.

*   g++ (or another C++ compiler)
*   CMake

### Installation & Running

1.  Clone the repository:
    ```sh
    git clone https://github.com/your_username/starter-quest.git
    ```
2.  Navigate to the project directory:
    ```sh
    cd starter-quest
    ```
3.  Run the build script. This will compile the project and create an executable in the `bin/` directory.
    ```sh
    ./build.sh
    ```
4.  Run the game:
    ```sh
    ./bin/main
    ```

## Gameplay

When you start the game, you will be prompted to:

1.  **Enter your hero's name.**
2.  **Choose a class** from the following options:
    *   Warrior
    *   Wizard
    *   Cleric
    *   Rogue

Once you've chosen your class, your character will perform a series of actions to demonstrate their new abilities, and the game will conclude.

## Project Structure

The project is organized into several directories to separate concerns:

```
.
├── baseClasses/      # Core classes like Character, Creature, Stats
├── bin/              # Compiled binary output
├── characterClasses/ # Playable character classes (Warrior, Rogue, etc.)
├── docs/             # Documentation
├── utils/            # Utility functions
├── build.sh          # Build script
├── CMakeLists.txt    # CMake configuration
├── main.cpp          # Main application entry point
└── README.md         # This file
```

-   `baseClasses/`: Contains the fundamental building blocks of the game's characters and world. `Character.h` is the cornerstone of the player's avatar.
-   `characterClasses/`: Defines the specific vocations a player can choose. Each class inherits from a base class and has its own unique actions.
-   `main.cpp`: The entry point for the application. It contains the main game loop and player interaction logic.
-   `build.sh`: A convenience script for compiling the project using CMake.

## Contributing

Contributions are what make the open-source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".

1.  Fork the Project
2.  Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3.  Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4.  Push to the Branch (`git push origin feature/AmazingFeature`)
5.  Open a Pull Request

There are many `// TODO:` comments throughout the codebase that point to areas for improvement and new features. Feel free to tackle one of them!