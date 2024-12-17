#include "Wizard.h"
#include <iostream>

Wizard::Wizard() : Wanderer() {}

void Wizard::vocation() {
  std::cout << character->getName() << " has chosen the vocation of Wizard!" << std::endl;
}

void Wizard::attack() {
  std::cout << character->getName() << " casts a powerful spell!" << std::endl;
}

void Wizard::defend() {
  std::cout << character->getName() << " defends with a magical barrier!" << std::endl;
}
