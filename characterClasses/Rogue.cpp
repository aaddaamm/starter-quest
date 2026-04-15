#include "Rogue.h"
#include <iostream>
#include <cstdlib>

Rogue::Rogue() : Wanderer() {}

// High DEX and CHA — fast, accurate, agile
Stats Rogue::getBaseStats() {
  return Stats(10, 16, 10, 10, 10, 14);
}

// DEX-based strike: consistent damage
int Rogue::rollAttack(const Stats& stats) {
  return stats.getDexterity() / 3 + (rand() % 6 + 1);
}

// DEX-based evasion: parries instead of blocking
int Rogue::getDefense(const Stats& stats) {
  return stats.getDexterity() / 4;
}

void Rogue::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Rogue!" << std::endl;
}

void Rogue::attack() {
  std::cout << character->getName() << " attacks with a dagger!" << std::endl;
}

void Rogue::defend() {
  std::cout << character->getName() << " defends with a parry!" << std::endl;
}
