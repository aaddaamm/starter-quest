#include "Cleric.h"
#include <iostream>
#include <cstdlib>

Cleric::Cleric() : Wanderer() {}

// High WIS and CON — durable support fighter
Stats Cleric::getBaseStats() {
  return Stats(10, 10, 12, 10, 16, 10);
}

// WIS-based holy strike: moderate damage
int Cleric::rollAttack(const Stats& stats) {
  return stats.getWisdom() / 3 + (rand() % 4 + 1);
}

// CON-based: sturdy but not a tank
int Cleric::getDefense(const Stats& stats) {
  return stats.getConstitution() / 3 + 1;
}

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
