#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Stats.h"

class Character {
protected:
  int age;
  int health;
  std::string name;
  std::string race;
  std::string origin;
  std::string height;
  std::string weight;
  Stats stats;

public:
  Character(
    const std::string& name,
    int age,
    int health,
    const std::string& race,
    const std::string& origin,
    const std::string& height,
    const std::string& weight
  );

  virtual void chooseVocation();
  virtual void attack();

  int getAge() const;
  int getHealth() const;
  const std::string& getName() const;
  void setName(const std::string& name);
  const std::string& getRace() const;
  const std::string& getOrigin() const;
  const std::string& getHeight() const;
  const std::string& getWeight() const;

  virtual ~Character() = default;
};

#endif
