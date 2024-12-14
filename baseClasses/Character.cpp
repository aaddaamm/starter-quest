#include <iostream>
#include <string>
#include "Character.h"
#include "Stats.h"

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
