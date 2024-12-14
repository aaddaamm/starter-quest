#include "Rogue.h"
#include <iostream>

Rogue::Rogue(
  const std::string& name,
  int age,
  int health,
  const std::string &race,
  const std::string &origin,
  const std::string &height,
  const std::string &weight
) : Character(name, age, 160, race, origin, height, weight) {}

void Rogue::chooseVocation() {
  std::cout << name << " has chosen the vocation of Rogue!" << std::endl;
}

void Rogue::attack() {
  std::cout << name << " attacks with a dagger!" << std::endl;
}
