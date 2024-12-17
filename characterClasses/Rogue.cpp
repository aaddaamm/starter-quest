#include "Rogue.h"
#include <iostream>

Rogue::Rogue() : Wanderer() {}

void Rogue::vocation() {
  std::cout << "Character has chosen the vocation of Rogue!" << std::endl;
}

void Rogue::attack() {
  std::cout << "Character attacks with a dagger!" << std::endl;
}

void Rogue::defend() {
  std::cout << "Character defends with a parry!" << std::endl;
}
