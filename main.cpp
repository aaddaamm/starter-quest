#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include "baseClasses/Character.h"
#include "characterClasses/Wanderer.h"
#include "characterClasses/Cleric.h"
#include "characterClasses/Rogue.h"
#include "characterClasses/Warrior.h"
#include "characterClasses/Wizard.h"

using namespace std;

vector<string> validClasses = {"Warrior", "Mage", "Rogue", "Cleric", "Wizard"};

const char* quest() {
  return "Quest!";
}

bool isValidClass(string selectedClass) {
  for (const auto& className : validClasses) {
    if (selectedClass == className) {
      return true;
    }
  }
  return false;
}

string promptForClass() {
  string userInput;
  bool validSelection = false;

  while (!validSelection) {
    cout << "Choose your class: " << endl;

    for (const auto& className : validClasses) {
      cout << className << endl;
    }

    cin >> userInput;

    if (isValidClass(userInput)) {
      validSelection = true;
      return userInput;
    } else {
      cout << "Invalid class. Please try again." << endl;
    }
  }

  return userInput;
}

bool continue_quest() {
  char response;
  cout << "Do you want to continue your quest? (y/n): ";
  cin >> response;

  return response == 'y';
}

void renameCharacter(Character* character) {
  string newName;
  cout << "Enter a new name for your character: ";
  cin >> newName;
  character->renameCharacter(newName);
}

void testCharacter(Character* character, CharacterClass* newClass) {
  character->setCharacterClass(newClass);
  character->vocation();
  character->attack();
  character->defend();
}

void welcome() {
    // TODO: For WebAssembly builds, this file loading will not work.
    // We need to use Emscripten's file packaging system (`--preload-file assets/title.txt@assets/title.txt`)
    // and then read the file from the virtual file system.
    ifstream titleFile("assets/title.txt");
    if (titleFile.is_open()) {
        stringstream buffer;
        buffer << titleFile.rdbuf();
        cout << buffer.str() << endl;
        titleFile.close();
    } else {
        // Fallback if the file can't be opened
        cout << "=================" << endl;
        cout << "  STARTER QUEST  " << endl;
        cout << "=================" << endl;
    }

    cout << "\n\nWelcome to your adventure..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
}

Character* start_game() {
  string heroName;
  string heroClass;

  cout << "Enter your hero's name: ";
  cin >> heroName;

  Character* myCharacter = new Character(heroName, 100);
  Wanderer* character = dynamic_cast<Wanderer*>(myCharacter->getCharacterClass());

  cout << "Welcome, " << heroName << "!" << endl;

  heroClass = promptForClass();

  cout << "You have chosen the " << heroClass << " class." << endl;

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
  string scenarioId;
  string scenarioName;
  string scenarioDescription;
  vector<string> scenarioChoices;
  vector<string> scenarioOutcomes;
  vector<string> completionCriteria;
  vector<string> rewards;
  function<void()> onStart;
  function<void()> onCompletion;
};

GameScenario getScenario(string scenarioName) {
  // TODO: Implement scenario retrieval from database
  return GameScenario();
}

// Main function
int main() {
  welcome();

  Character* myCharacter = start_game();

  cout << "Goodbye!" << endl;

  return 0;
}
