#!/bin/zsh

# This script compiles the C++ project to WebAssembly using Emscripten.

# Create the output directory for the WebAssembly files.
echo "Creating wasm directory..."
mkdir -p wasm

# Define the C++ source files to be compiled.
SOURCES=" \
  baseClasses/Character.cpp \
  baseClasses/Creature.cpp \
  baseClasses/Item.cpp \
  baseClasses/Stats.cpp \
  baseClasses/Weapon.cpp \
  characterClasses/Cleric.cpp \
  characterClasses/Rogue.cpp \
  characterClasses/Wanderer.cpp \
  characterClasses/Warrior.cpp \
  characterClasses/Wizard.cpp \
  utils/DiceRoller.cpp \
  main.cpp \
"

# Define the include directories for the header files.
INCLUDES=" \
  -I baseClasses \
  -I characterClasses \
  -I utils \
"

# Set the output file for the compiled WebAssembly module.
OUTPUT_FILE="wasm/quest.js"

# Use Emscripten (emcc) to compile the C++ source to WebAssembly.
# -O3 is an optimization flag for performance.
# -s WASM=1 specifies that we want WebAssembly output.
# -s "EXPORTED_RUNTIME_METHODS" makes C++ functions available to JavaScript.
echo "Compiling C++ to WebAssembly..."
emcc $SOURCES $INCLUDES -o $OUTPUT_FILE -O3 -s WASM=1 \
  -s "EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"

# Check the exit code of the compilation process.
if [ $? -eq 0 ]; then
  echo "\nCompilation successful!"
  echo "Copying custom HTML file..."
  cp index.html wasm/index.html
  echo "Your WebAssembly application has been created in the 'wasm' directory."
else
  echo "\nCompilation failed. Please check the error messages above."
  exit 1
fi
