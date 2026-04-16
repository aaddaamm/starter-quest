#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon {
public:
  Weapon(const std::string& name, int damage, int statBonus);

  std::string getName() const;
  int getDamage() const;

  // Flat bonus applied on top of the class's base attack roll
  int getStatBonus() const;

private:
  std::string name;
  int damage;
  int statBonus;
};

#endif
