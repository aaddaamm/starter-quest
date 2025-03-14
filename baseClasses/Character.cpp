#include <iostream>
#include <string>
#include "Character.h"
#include "../characterClasses/Wanderer.h"

//TODO: Add validation for the constructor
//TODO: Add validation for the age
//TODO: A character should be able to level up
//TODO: A character should be able to gain experience
//TODO: a character should be able to equip armor
//TODO: a character's defense should be modified by the armor they have equipped
//TODO: a character should be able to equip a weapon
//TODO: a character's attack should be modified by the weapon they have equipped
//TODO: a character should be able to use items
//TODO: a character should be able to use abilities
//TODO: a character should be able to use spells
//TODO: a character should be able to use magic items
//TODO: a character should have base stats that are modified by their class.

const int maxNameLength = 20;

Character::Character(const std::string& name, int health) :
  name(name),
  health(health),
  baseStats(Stats()),
  experience(0),
  level(1),
  characterClass(new Wanderer()) {
    characterClass->setCharacter(this);
  }

void Character::setCharacterClass(CharacterClass* newClass) {
  if (newClass != nullptr) {
    delete this->characterClass;
  }

  this->characterClass = newClass;
  characterClass->setCharacter(this);
}

void Character::addExperience(int experience) {
  this->experience += experience;
  // update level based on experience thresholds
  // common RPG pattern level = 1 + floor(sqrt(experience/100))
  int newLevel = 1 + floor(sqrt(this->experience / 100));
  if (newLevel > this->level) {
    this->level = newLevel;
    std::cout << "Level up! " << this->name << " is now level " << this->level << std::endl;
    this->experience = 0;
  }
}

void Character::renameCharacter(const std::string& newName) {
  if (newName.empty()) {
    std::cout << "Name cannot be empty." << std::endl;
    return;
  }

  if (newName.length() > maxNameLength) {
    std::cout << "Name cannot be longer than " << maxNameLength << " characters." << std::endl;
    return;
  }

  std::cout << "Renaming " << getName() << " to " << newName;

  this->name = newName;
}

std::string Character::getName() const {
  return this->name;
}

CharacterClass* Character::getCharacterClass() const {
  return this->characterClass;
}

void Character::vocation() {
  if (this->characterClass != nullptr) {
    this->characterClass->vocation();
  } else {
    std::cout << name << " has not chosen a vocation yet." << std::endl;
  }
}

void Character::attack() {
  if (this->characterClass != nullptr) {
    this->characterClass->attack();
  } else {
    std::cout << name << " attacks with a basic attack." << std::endl;
  }
}

void Character::defend() {
  if (this->characterClass != nullptr) {
    this->characterClass->defend();
  } else {
    std::cout << name << " defends with a basic shield." << std::endl;
  }
}

Character::~Character() {
  delete this->characterClass;
}
