// a common class for all characters to start as before
// they are specialized into their own classes.
#include "Wanderer.h"
#include <iostream>

Wanderer::Wanderer() : CharacterClass() {}

void Wanderer::vocation() {
  std::cout << "Wanderer has no class" << std::endl;
}

void Wanderer::attack() {
  std::cout << "Wanderer attacks with a basic attack!" << std::endl;
}

void Wanderer::defend() {
  std::cout << "Wanderer defends with a basic defense!" << std::endl;
}
