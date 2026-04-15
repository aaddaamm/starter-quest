#include <iostream>
#include <string>
#include "Character.h"
#include "../characterClasses/Wanderer.h"

//TODO: Add validation for the constructor
//TODO: A character should be able to level up
//TODO: A character should be able to gain experience
//TODO: a character should be able to equip armor
//TODO: a character should be able to equip a weapon
//TODO: a character should be able to use items
//TODO: a character should be able to use abilities
//TODO: a character should be able to use spells
//TODO: a character should be able to use magic items

Character::Character(const std::string& name, int health) :
  name(name),
  health(health),
  characterClass(new Wanderer()),
  stats() {
    characterClass->setCharacter(this);
    stats = characterClass->getBaseStats();
  }

void Character::setCharacterClass(CharacterClass* newClass) {
  if (newClass == this->characterClass) return;

  if (this->characterClass != nullptr) {
    delete this->characterClass;
  }

  this->characterClass = newClass;

  if (this->characterClass != nullptr) {
    this->characterClass->setCharacter(this);
    stats = this->characterClass->getBaseStats();
  } else {
    stats = Stats();
  }
}

std::string Character::getName() const {
  return this->name;
}

int Character::getHealth() const {
  return this->health;
}

bool Character::isAlive() const {
  return this->health > 0;
}

void Character::takeDamage(int amount) {
  if (amount <= 0) return;
  this->health -= amount;
  if (this->health < 0) this->health = 0;
}

int Character::rollAttack() const {
  return this->characterClass->rollAttack(this->stats);
}

int Character::getDefense() const {
  return this->characterClass->getDefense(this->stats);
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
