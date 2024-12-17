#include "Cleric.h"
#include <iostream>

// TODO: a cleric should have unique stats
// TODO: a cleric should have unique abilities
// TODO: a cleric should have unique spells
Cleric::Cleric() : Wanderer() {}

void Cleric::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Cleric!" << std::endl;
}

void Cleric::attack() {
  std::cout << character->getName() << " casts a holy spell!" << std::endl;
}

void Cleric::defend() {
  std::cout << character->getName() << " defends with a shield!" << std::endl;
}

void Cleric::heal() {
  std::cout << character->getName() << " heals a target!" << std::endl;
}

void Cleric::castSpell() {
  std::cout << character->getName() << " casts a spell!" << std::endl;
}
