#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Stats.h"

class Character {
public:
  Character(
    int age,
    int health,
    const std::string& name,
    const std::string& race,
    const std::string& origin,
    const std::string& height,
    const std::string& weight
  );

  int getAge() const;
  int getHealth() const;
  const std::string& getName() const;
  void setName(const std::string& name);
  const std::string& getRace() const;
  const std::string& getOrigin() const;
  const std::string& getHeight() const;
  const std::string& getWeight() const;

private:
  int age;
  int health;
  std::string name;
  std::string race;
  std::string origin;
  std::string height;
  std::string weight;
  Stats stats;
};

#endif