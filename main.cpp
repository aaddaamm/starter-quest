#include <iostream>
#include <string>
#include <filesystem>
#include "baseClasses/Character.h"
#include "characterClasses/Wanderer.h"
#include "characterClasses/Cleric.h"
#include "characterClasses/Rogue.h"
#include "characterClasses/Warrior.h"
#include "characterClasses/Wizard.h"

namespace fs = std::filesystem;

const char* quest() {
  return "Quest!";
}

bool continue_quest() {
  char response;
  std::cout << "Do you want to continue your quest? (y/n): ";
  std::cin >> response;

  return response == 'y';
}

void renameCharacter(Character* character) {
  std::string newName;
  std::cout << "Enter a new name for your character: ";
  std::cin >> newName;
  character->renameCharacter(newName);
}

void testCharacter(Character* character, CharacterClass* newClass) {
  character->setCharacterClass(newClass);
  character->vocation();
  character->attack();
  character->defend();
}

// Main function
// TODO: a user should be able to pick a class for their character
int main() {
  std::string heroName;
  std::string heroClass;
  Character* myCharacter = nullptr;

  do {
    std::cout << "Enter your hero's name: ";
    std::cin >> heroName;

    if (myCharacter != nullptr) {
      delete myCharacter;
    }

    myCharacter = new Character(heroName, 100);

    Wanderer* wanderer = dynamic_cast<Wanderer*>(myCharacter->getCharacterClass());

    if (wanderer){
      wanderer->defend();
    }

    CharacterClass* warrior = new Warrior();
    testCharacter(myCharacter, warrior);

    CharacterClass* wizard = new Wizard();
    testCharacter(myCharacter, wizard);

  } while (continue_quest());

  std::cout << "Goodbye!" << std::endl;

  delete myCharacter;

  return 0;
}
