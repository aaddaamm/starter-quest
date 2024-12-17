#include "Warrior.h"
#include <iostream>

Warrior::Warrior() : Wanderer() {}

void Warrior::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Warrior!" << std::endl;
}

void Warrior::attack() {
  std::cout << character->getName() << " attacks with a sword!" << std::endl;
}

void Warrior::defend() {
  std::cout << character->getName() << " defends with a shield!" << std::endl;
}
