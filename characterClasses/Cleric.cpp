#include "Cleric.h"
#include <iostream>

// TODO: a cleric should have unique stats
// TODO: a cleric should have unique abilities
// TODO: a cleric should have unique spells
Cleric::Cleric() : Wanderer() {}

void Cleric::vocation() {
  std::cout << "Character has chosen the vocation of Cleric!" << std::endl;
}

void Cleric::attack() {
  std::cout << "Character casts a holy spell!" << std::endl;
}

void Cleric::defend() {
  std::cout << "Character defends with a shield!" << std::endl;
}

void Cleric::heal() {
  std::cout << "Character heals a target!" << std::endl;
}

void Cleric::castSpell() {
  std::cout << "Character casts a spell!" << std::endl;
}
