#include "Wizard.h"
#include <iostream>
#include <cstdlib>

Wizard::Wizard() : Wanderer() {}

// High INT and WIS — fragile but hits hard with spells
Stats Wizard::getBaseStats() {
  return Stats(6, 12, 8, 16, 14, 12);
}

// INT-based magic: high ceiling, high variance
int Wizard::rollAttack(const Stats& stats) {
  return stats.getIntelligence() / 3 + (rand() % 8 + 1);
}

// Low physical defense — relies on staying out of range
int Wizard::getDefense(const Stats& stats) {
  return stats.getConstitution() / 6;
}

void Wizard::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Wizard!" << std::endl;
}

void Wizard::attack() {
  std::cout << character->getName() << " casts a powerful spell!" << std::endl;
}

void Wizard::defend() {
  std::cout << character->getName() << " defends with a magical barrier!" << std::endl;
}
