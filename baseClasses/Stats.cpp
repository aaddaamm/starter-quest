#include "Stats.h"

Stats::Stats() :
  strength(0),
  dexterity(0),
  constitution(0),
  intelligence(0),
  wisdom(0),
  charisma(0) {};

Stats::Stats(
  int strength,
  int dexterity,
  int constitution,
  int intelligence,
  int wisdom,
  int charisma
  ) :
  strength(strength),
  dexterity(dexterity),
  constitution(constitution),
  intelligence(intelligence),
  wisdom(wisdom),
  charisma(charisma) {};

int Stats::getStrength() const     { return strength; }
int Stats::getDexterity() const    { return dexterity; }
int Stats::getConstitution() const { return constitution; }
int Stats::getIntelligence() const { return intelligence; }
int Stats::getWisdom() const       { return wisdom; }
int Stats::getCharisma() const     { return charisma; }
