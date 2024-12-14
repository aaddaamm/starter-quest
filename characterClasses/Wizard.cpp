#include "Wizard.h"
#include <iostream>

Wizard::Wizard(
  const std::string& name,
  int age,
  int health,
  const std::string &race,
  const std::string &origin,
  const std::string &height,
  const std::string &weight
) : Character(name, age, 120, race, origin, height, weight) {}

void Wizard::chooseVocation() {
  std::cout << name << " has chosen the vocation of Wizard!" << std::endl;
}

void Wizard::attack() {
  std::cout << name << " casts a powerful spell!" << std::endl;
}
