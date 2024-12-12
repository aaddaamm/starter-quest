#include <string>
#include "Character.h"
#include "Stats.h"

Character::Character(
  int age,
  int health,
  const std::string& name,
  const std::string& race,
  const std::string& origin,
  const std::string& height,
  const std::string& weight
) :
  age(age),
  health(health),
  name(name),
  race(race),
  origin(origin),
  height(height),
  weight(weight),
  stats() {
    // Add validation here,
    // e.g., check if age is non-negative
}

int Character::getAge() const { return age; }
int Character::getHealth() const { return health; }

const std::string& Character::getName() const { return name; }
const std::string& Character::getRace() const { return race; }
const std::string& Character::getOrigin() const { return origin; }
const std::string& Character::getHeight() const { return height; }
const std::string& Character::getWeight() const { return weight; }
