#include "Warrior.h"
#include <iostream>
#include <cstdlib>

Warrior::Warrior() : Wanderer() {}

// High STR and CON — frontline fighter
Stats Warrior::getBaseStats() {
  return Stats(16, 12, 14, 8, 8, 10);
}

// STR-based melee: hits hard, low variance
int Warrior::rollAttack(const Stats& stats) {
  return stats.getStrength() / 3 + (rand() % 4 + 1);
}

// CON-based defense: tanks hits well
int Warrior::getDefense(const Stats& stats) {
  return stats.getConstitution() / 3;
}

void Warrior::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Warrior!" << std::endl;
}

void Warrior::attack() {
  std::cout << character->getName() << " attacks with a sword!" << std::endl;
}

void Warrior::defend() {
  std::cout << character->getName() << " defends with a shield!" << std::endl;
}
