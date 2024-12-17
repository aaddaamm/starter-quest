// a common class for all characters to start as before
// they are specialized into their own classes.
#include "Wanderer.h"
#include <iostream>

Wanderer::Wanderer() : CharacterClass() {}

void Wanderer::vocation() {
  std::cout << character->getName() << " has no class" << std::endl;
}

void Wanderer::attack() {
  std::cout << character->getName() << " attacks with a basic attack!" << std::endl;
}

void Wanderer::defend() {
  std::cout << character->getName() << " defends with a basic defense!" << std::endl;
}
