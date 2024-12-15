#include <iostream>
#include <string>
#include "Character.h"
#include "Stats.h"

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
Character::Character(
  const std::string& name,
  int age = 25,
  int health = 100,
  const std::string& race = "Human",
  const std::string& origin = "Earth",
  const std::string& height = "6'0\"",
  const std::string& weight = "180 lbs"
) :
  name(name),
  age(age),
  health(health),
  race(race),
  origin(origin),
  height(height),
  weight(weight),
  stats() {
    // Add validation here,
    // e.g., check if age is non-negative
}

void Character::chooseVocation() {
  std::cout << name << " is undecided about their vocation" << std::endl;
}

void Character::attack() {
  std::cout << name << " attacks with the basic attack!" << std::endl;
}

void Character::setName(const std::string& name) {
  this->name = name;
}

int Character::getAge() const { return age; }
int Character::getHealth() const { return health; }

const std::string& Character::getName() const { return name; }
const std::string& Character::getRace() const { return race; }
const std::string& Character::getOrigin() const { return origin; }
const std::string& Character::getHeight() const { return height; }
const std::string& Character::getWeight() const { return weight; }
