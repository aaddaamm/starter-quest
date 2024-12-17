#include "Rogue.h"
#include <iostream>

Rogue::Rogue() : Wanderer() {}

void Rogue::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Rogue!" << std::endl;
}

void Rogue::attack() {
  std::cout << character->getName() << " attacks with a dagger!" << std::endl;
}

void Rogue::defend() {
  std::cout << character->getName() << " defends with a parry!" << std::endl;
}
