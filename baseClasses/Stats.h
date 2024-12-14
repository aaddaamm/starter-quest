#ifndef STATS_H
#define STATS_H

#include <string>

/**
 * @class Stats
 * @brief A class to represent character statistics.
 *
 * This class encapsulates the primary attributes of a character,
 * including strength, dexterity, constitution, intelligence, wisdom, and charisma.
 *
 * @param strength The strength attribute of the character.
 * @param dexterity The dexterity attribute of the character.
 * @param constitution The constitution attribute of the character.
 * @param intelligence The intelligence attribute of the character.
 * @param wisdom The wisdom attribute of the character.
 * @param charisma The charisma attribute of the character.
 */
class Stats {
public:
  Stats();
  Stats(
    int strength,
    int dexterity,
    int constitution,
    int intelligence,
    int wisdom,
    int charisma
  );

private:
  const int strength;
  const int dexterity;
  const int constitution;
  const int intelligence;
  const int wisdom;
  const int charisma;
};

#endif
