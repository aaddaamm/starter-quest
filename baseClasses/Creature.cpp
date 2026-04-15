#include "Creature.h"
#include <cstdlib>

Creature::Creature(const std::string& name, int health, int attackPower, int defense)
  : name(name), health(health), attackPower(attackPower), defense(defense) {}

std::string Creature::getName() const { return name; }
int Creature::getHealth() const       { return health; }
bool Creature::isAlive() const        { return health > 0; }

// attackPower + small random roll (1-4)
int Creature::rollAttack() const {
  return attackPower + (rand() % 4 + 1);
}

// Defense absorbs a flat portion of incoming damage
void Creature::takeDamage(int amount) {
  int net = amount - defense;
  if (net > 0) health -= net;
  if (health < 0) health = 0;
}
