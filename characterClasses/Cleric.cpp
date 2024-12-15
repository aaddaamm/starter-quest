#include "Cleric.h"
#include <iostream>

// TODO: a cleric should have unique stats
// TODO: a cleric should have unique abilities
// TODO: a cleric should have unique spells
Cleric::Cleric(
  const std::string& name,
  int age,
  int health,
  const std::string &race,
  const std::string &origin,
  const std::string &height,
  const std::string &weight
) : Character(name, age, 210, race, origin, height, weight) {}

void Cleric::chooseVocation() {
  std::cout << name << " has chosen the vocation of Cleric!" << std::endl;
}

void Cleric::attack() {
  std::cout << name << " casts a healing spell!" << std::endl;
}
