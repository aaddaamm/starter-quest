#include "Wizard.h"
#include <iostream>

Wizard::Wizard() : Wanderer() {}

void Wizard::vocation() {
  std::cout << "Character has chosen the vocation of Wizard!" << std::endl;
}

void Wizard::attack() {
  std::cout << "Character casts a powerful spell!" << std::endl;
}

void Wizard::defend() {
  std::cout << "Character defends with a magical barrier!" << std::endl;
}
