#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
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

bool isValidClass(std::string selectedClass) {
  std::vector<std::string> validClasses = {"Warrior", "Mage", "Rogue", "Cleric"};

  for (const auto& className : validClasses) {
    if (selectedClass == className) {
      return true;
    }
  }
  return false;
}

std::string promptForClass() {
  std::vector<std::string> validClasses = {"Warrior", "Mage", "Rogue", "Cleric"};
  std::string userInput;
  bool validSelection = false;

  while (!validSelection) {
    std::cout << "Choose your class: " << std::endl;

    for (const auto& className : validClasses) {
      std::cout << className << std::endl;
    }

    std::cin >> userInput;

    if (isValidClass(userInput)) {
      validSelection = true;
      return userInput;
    } else {
      std::cout << "Invalid class. Please try again." << std::endl;
    }
  }

  return userInput;
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

void welcome() {
  std::cout << "Welcome to the game!" << std::endl;
}

Character* start_game() {
  std::string heroName;
  std::string heroClass;

  std::cout << "Enter your hero's name: ";
  std::cin >> heroName;

  Character* myCharacter = new Character(heroName, 100);
  Wanderer* character = dynamic_cast<Wanderer*>(myCharacter->getCharacterClass());

  std::cout << "Welcome, " << heroName << "!" << std::endl;

  heroClass = promptForClass();

  std::cout << "You have chosen the " << heroClass << " class." << std::endl;

  if (heroClass == "Warrior") {
    myCharacter->setCharacterClass(new Warrior());
  } else if (heroClass == "Wizard") {
    myCharacter->setCharacterClass(new Wizard());
  } else if (heroClass == "Cleric") {
    myCharacter->setCharacterClass(new Cleric());
  } else if (heroClass == "Rogue") {
    myCharacter->setCharacterClass(new Rogue());
  }

  myCharacter->vocation();
  myCharacter->attack();
  myCharacter->defend();

  return myCharacter;
}

// game scenario structure
struct GameScenario {
  std::string scenarioId;
  std::string scenarioName;
  std::string scenarioDescription;
  std::vector<std::string> scenarioChoices;
  std::vector<std::string> scenarioOutcomes;
  std::vector<std::string> completionCriteria;
  std::vector<std::string> rewards;
  std::function<void()> onStart;
  std::function<void()> onCompletion;
};

GameScenario getScenario(std::string scenarioName) {
  // TODO: Implement scenario retrieval from database
  return GameScenario();
}

// Main function
int main() {
  welcome();

  Character* myCharacter = start_game();

  std::cout << "Goodbye!" << std::endl;

  return 0;
}
