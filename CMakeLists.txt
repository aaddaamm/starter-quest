cmake_minimum_required(VERSION 3.11)
project(Quest)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- Source File Management ---
# Collect all project source files (except main.cpp) into a static library.
# This promotes modularity and allows both the main executable and the test
# runner to link against the same compiled code base without duplication.
set(QUEST_SOURCES
    baseClasses/Character.cpp
    baseClasses/Creature.cpp
    baseClasses/Item.cpp
    baseClasses/Stats.cpp
    baseClasses/Weapon.cpp
    characterClasses/Cleric.cpp
    characterClasses/Rogue.cpp
    characterClasses/Wanderer.cpp
    characterClasses/Warrior.cpp
    characterClasses/Wizard.cpp
    ui/Menu.cpp
    utils/DiceRoller.cpp
)

add_library(QuestLib STATIC ${QUEST_SOURCES})

# --- Include Directories ---
# Add include directories required by the library.
# PUBLIC propagation ensures that any target linking against QuestLib
# will also have these include directories set up correctly.
target_include_directories(QuestLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# --- Dependency Management (OpenSSL) ---
# Find the OpenSSL library package and link it to our core library.
find_package(OpenSSL REQUIRED)
target_link_libraries(QuestLib PRIVATE OpenSSL::SSL OpenSSL::Crypto)

# --- Main Executable Definition ---
add_executable(Quest main.cpp)
target_link_libraries(Quest PRIVATE QuestLib)


# ====================================================================
# Testing Setup with Catch2
# ====================================================================

# Enable testing for the project. This is required for CTest to discover tests.
enable_testing()
include(CTest)

# --- Test Executable ---
# Define the test executable target, including all our test files and the
# downloaded Catch2 implementation file.
add_executable(QuestTests
    tests/main.test.cpp
    tests/character.test.cpp
    tests/catch_amalgamated.cpp
)

# Link the test executable against our QuestLib to get access to our project's code.
target_link_libraries(QuestTests PRIVATE QuestLib)

# Add the 'tests' directory to the include path for the test target. This is
# crucial so that the test files can find `#include "catch_amalgamated.hpp"`.
target_include_directories(QuestTests PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests"
)

# Register the test executable with CTest.
add_test(NAME UnitTests COMMAND QuestTests)
