#include "Warrior.h"
#include <iostream>

Warrior::Warrior(
  const std::string& name,
  int age,
  int health,
  const std::string& race,
  const std::string& origin,
  const std::string& height,
  const std::string& weight
) : Character(name, age, 200, race, origin, height, weight) {}

void Warrior::chooseVocation() {
  std::cout << name << " has chosen the vocation of Warrior!" << std::endl;
}

void Warrior::attack() {
  std::cout << name << " attacks with a sword!" << std::endl;
}
