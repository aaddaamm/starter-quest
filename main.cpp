#include <iostream>
#include <string>
#include "baseClasses/Character.h"

const char* quest() {
  return "Quest!";
}

int main() {
  std::string heroName;
  std::string heroClass;
  std::string heroRace;
  int heroLevel = 1;

  std::cout << "Enter your hero's name: ";
  std::cin >> heroName;
  std::cout << "Enter your hero's class: ";

  std::cin >> heroClass;

  Character character(20, 100, heroName, heroRace, "Earth", "6'2\"", "180 lbs");

  std::cout << "Your hero's name is " << character.getName() << "\n" << std::endl;
  std::cout << "Your hero's class is " << heroClass << "\n" << std::endl;

  return 0;
}
