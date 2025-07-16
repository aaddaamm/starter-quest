cmake_minimum_required(VERSION 3.10)
project(Quest)

# Set the C++ standard for the project
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- Source File Management ---
# Manually and explicitly list all source files.
# This is the most robust method and avoids linker errors from
# accidentally discovering temporary or unwanted .cpp files.
set(SOURCES
    main.cpp
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

# --- Executable Definition ---
# Define the executable target with our collected source files
add_executable(Quest ${SOURCES})

# --- Include Directories ---
# Add include directories required by the target.
# This ensures that #include directives work correctly from any source file.
target_include_directories(Quest PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

# --- Dependency Management (OpenSSL) ---
# Find the OpenSSL library package
find_package(OpenSSL REQUIRED)

# Link the OpenSSL libraries to our executable target.
# This adds the necessary include directories and linker flags.
# Using the modern imported targets (OpenSSL::SSL, OpenSSL::Crypto) is preferred.
target_link_libraries(Quest PRIVATE OpenSSL::SSL OpenSSL::Crypto)
