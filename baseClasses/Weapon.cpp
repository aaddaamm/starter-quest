#include "Weapon.h"

Weapon::Weapon(const std::string& name, int damage, int statBonus)
  : name(name), damage(damage), statBonus(statBonus) {}

std::string Weapon::getName() const { return name; }
int Weapon::getDamage() const       { return damage; }
int Weapon::getStatBonus() const    { return statBonus; }
