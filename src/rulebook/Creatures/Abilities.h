/*
 * Abilities.h
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#ifndef ABILITIES_H_
#define ABILITIES_H_

enum ability_type
{
  strength = 0,
  dexterity,
  constitution,
  intelligence,
  attunement,
  charisma
};

static const int ability_array_size = 6;

class Abilities
{
  public:
    Abilities(void);
    Abilities(const int abilityArray[]);
    ~Abilities(void);

    void setScore(ability_type type, int score);
    unsigned int getScore(ability_type type) const;
    int getModifier(ability_type type) const;
    unsigned int getTotalScore(ability_type type) const;
    int getTotalModifier(ability_type type) const;

    void addTempAdjustment(ability_type type, int value);
    void removeTempAdjustment(ability_type type, int value);
    void resetTempAdjustment(ability_type type);

    void addTempModifier(ability_type type, int value);
    void removeTempModifier(ability_type type, int value);
    void resetTempModifier(ability_type type);

  private:
    struct ability_struct
    {
      int score;
      int tempAdjustment;
      int tempModifier;
    };

    ability_struct abilities[ability_array_size];
};

#endif /* ABILITIES_H_ */
