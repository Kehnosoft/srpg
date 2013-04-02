/*
 * Defence.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "Defence.h"

Defence::Defence(const Abilities* abilityPointer) : abilities(abilityPointer)
{
  if(abilityPointer != 0)
  {
    for(int i = armor; i < bonus_type_max; i++)
    {
      defenceBonuses[i] = 0;
    }

    for(int i = piercing_damage; i < damage_resistance_array_max; i++)
    {
      damageResistances[i] = 0;
    }
  }
  else
  {
    throw ErrorNullPointer();
  }
  return;
}

Defence::~Defence(void)
{
  return;
}

void Defence::addBonus(defence_bonus_type type, int bonus)
{
  defenceBonuses[type] += bonus;
  return;
}

void Defence::decreaseBonus(defence_bonus_type type, int bonus)
{
  defenceBonuses[type] -= bonus;
  return;
}

int Defence::getAC(AC_type type, const piercing_type* piercing) const
{
  int total = 10;
  int tempBonuses[piercing_array_max];
  for(int i = armor; i <= attunement_protection; i++)
  {
    switch(piercing[i])
    {
      case no_piercing:
        tempBonuses[i] = defenceBonuses[i];
        break;

      case half_piercing:
        tempBonuses[i] = defenceBonuses[i]/2;
        break;

      case full_piercing:
        tempBonuses[i] = 0;
        break;

      default:
        throw ErrorUnexpectedValue();
        break;
    }
  }

  switch(type)
  {
    case normal:
      total += tempBonuses[armor] + tempBonuses[shield] + tempBonuses[attunement_protection]
               + defenceBonuses[natural] + defenceBonuses[deflection] +
               + abilities->getModifier(dexterity);
      break;

    case touch:
      total += defenceBonuses[deflection] + abilities->getModifier(dexterity);
      break;

    case flatFooted:
      total += tempBonuses[armor] + tempBonuses[shield] + tempBonuses[attunement_protection]
               + defenceBonuses[natural];
      break;

    default:
      throw ErrorUnexpectedValue();
      break;
  }
  return total;
}

int Defence::getDamageResistance(damage_type type) const
{
  int resistance;
  resistance = damageResistances[type];
  return resistance;
}

void Defence::addDamageResistance(damage_type type, int resistance)
{
  damageResistances[type] += resistance;
  return;
}

void Defence::decreaseDamageResistance(damage_type type, int resistance)
{
  damageResistances[type] -= resistance;
  return;
}
