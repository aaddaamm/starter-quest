#include "Warrior.h"
#include <iostream>

Warrior::Warrior() : Wanderer() {}

void Warrior::vocation() {
  std::cout << "Character has chosen the vocation of Warrior!" << std::endl;
}

void Warrior::attack() {
  std::cout << "Character attacks with a sword!" << std::endl;
}

void Warrior::defend() {
  std::cout << "Character defends with a shield!" << std::endl;
}
