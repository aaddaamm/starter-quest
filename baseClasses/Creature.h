#ifndef CREATURE_H
#define CREATURE_H

#include <string>

// A Creature is a non-player combatant. Unlike Character, it uses flat
// attack and defense values rather than a Stats/vocation system.
class Creature {
public:
  Creature(const std::string& name, int health, int attackPower, int defense);

  std::string getName() const;
  int getHealth() const;
  bool isAlive() const;

  // Returns damage dealt this turn (attackPower + small random roll)
  int rollAttack() const;

  void takeDamage(int amount);

private:
  std::string name;
  int health;
  int attackPower;
  int defense;
};

#endif
