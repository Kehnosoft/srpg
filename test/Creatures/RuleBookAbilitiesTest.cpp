/*
 * RuleBookAbilitiesTest.cpp
 *
 *  Created on: 29.4.2013
 *      Author: Juho L
 */

#include "../../src/rulebook/Errors.h"
#include "../../src/rulebook/Creatures/Abilities.h"
#include "RuleBookAbilitiesTest.h"

TEST_GROUP(Abilities)
{
  void setup()
  {
    
  }
  
  void teardown()
  {
    
  }
};

TEST(Abilities, AbilitiesDefaultValues)
{
  Abilities* defaultAbility;
  defaultAbility = new Abilities();
  
  LONGS_EQUAL(10, defaultAbility->getScore(strength));
  LONGS_EQUAL(10, defaultAbility->getScore(dexterity));
  LONGS_EQUAL(10, defaultAbility->getScore(constitution));
  LONGS_EQUAL(10, defaultAbility->getScore(intelligence));
  LONGS_EQUAL(10, defaultAbility->getScore(attunement));
  LONGS_EQUAL(10, defaultAbility->getScore(charisma));
  
  LONGS_EQUAL(10, defaultAbility->getTotalScore(strength));
  LONGS_EQUAL(10, defaultAbility->getTotalScore(dexterity));
  LONGS_EQUAL(10, defaultAbility->getTotalScore(constitution));
  LONGS_EQUAL(10, defaultAbility->getTotalScore(intelligence));
  LONGS_EQUAL(10, defaultAbility->getTotalScore(attunement));
  LONGS_EQUAL(10, defaultAbility->getTotalScore(charisma));
  
  LONGS_EQUAL(0, defaultAbility->getModifier(strength));
  LONGS_EQUAL(0, defaultAbility->getModifier(dexterity));
  LONGS_EQUAL(0, defaultAbility->getModifier(constitution));
  LONGS_EQUAL(0, defaultAbility->getModifier(intelligence));
  LONGS_EQUAL(0, defaultAbility->getModifier(attunement));
  LONGS_EQUAL(0, defaultAbility->getModifier(charisma));
  
  LONGS_EQUAL(0, defaultAbility->getTotalModifier(strength));
  LONGS_EQUAL(0, defaultAbility->getTotalModifier(dexterity));
  LONGS_EQUAL(0, defaultAbility->getTotalModifier(constitution));
  LONGS_EQUAL(0, defaultAbility->getTotalModifier(intelligence));
  LONGS_EQUAL(0, defaultAbility->getTotalModifier(attunement));
  LONGS_EQUAL(0, defaultAbility->getTotalModifier(charisma));
  
  delete defaultAbility;
}

TEST(Abilities, AbilitiesLimits)
{
  Abilities* customAbilities;
  bool isError = false;
  
  int zeroAbilityScores[] = {0, 0, 0, 0, 0, 0};
  CHECK_NO_THROWS(customAbilities = new Abilities(zeroAbilityScores));
  delete customAbilities;
  
  for(int i = 0; i < ability_array_size; i++)
  {
    int abilityScores[ability_array_size];
    for(int j = 0; j < ability_array_size; j++)
    {
      if(i == j)
      {
	abilityScores[j] = -1;
      }
      else
      {
	abilityScores[j] = 0;
      }
    }
    CHECK_THROWS(ErrorInvalidData, customAbilities = new Abilities(abilityScores));
  }
}