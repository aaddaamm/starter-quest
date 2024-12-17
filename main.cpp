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

// Main function
// TODO: a user should be able to pick a class for their character
int main() {
  std::string heroName;
  std::string heroClass;

  std::cout << "Enter your hero's name: ";
  std::cin >> heroName;

  Character* myCharacter = new Character(heroName, 100);

  myCharacter->vocation();
  myCharacter->attack();

  Wanderer* wanderer = dynamic_cast<Wanderer*>(myCharacter->getCharacterClass());

  if (wanderer){
    wanderer->defend();
  }

  myCharacter->setCharacterClass(new Warrior());
  myCharacter->vocation();
  myCharacter->attack();



  myCharacter->setCharacterClass(new Wizard());
  myCharacter->vocation();
  myCharacter->attack();

  delete myCharacter;

  return 0;
}
