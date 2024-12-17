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

Character::Character(const std::string& name, int health) :
  name(name),
  health(health),
  characterClass(new Wanderer()) {}

void Character::setCharacterClass(CharacterClass* newClass) {
  if (newClass != nullptr) {
    delete this->characterClass;
  }

  this->characterClass = newClass;
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
