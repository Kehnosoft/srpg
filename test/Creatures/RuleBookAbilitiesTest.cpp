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
  int zeroAbilityScores[6] = {0, 0, 0, 0, 0, 0};
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

TEST(Abilities, AbilityModifiers)
{
  Abilities* testAbilities;
  testAbilities = new Abilities();
  
  testAbilities->setScore(strength, 4);
  LONGS_EQUAL(-2, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 5);
  LONGS_EQUAL(-1, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 7);
  LONGS_EQUAL(-1, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 8);
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 12);
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 13);
  LONGS_EQUAL(1, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 15);
  LONGS_EQUAL(1, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 16);
  LONGS_EQUAL(2, testAbilities->getModifier(strength));
  
  testAbilities->setScore(strength, 25);
  LONGS_EQUAL(5, testAbilities->getModifier(strength));
  
  delete testAbilities;
}

TEST(Abilities, AbilitiesSetScoreLimits)
{
  Abilities* testAbilities;
  testAbilities = new Abilities();
  
  CHECK_NO_THROWS(testAbilities->setScore(strength, 0));
  CHECK_THROWS(ErrorInvalidData, testAbilities->setScore(strength, -1));
  CHECK_THROWS(ErrorInvalidData, testAbilities->setScore(charisma, -1));
  
  delete testAbilities;
}

TEST(Abilities, AbilitiesLimits)
{
  Abilities* testAbilities;
  
  CHECK_NO_THROWS(testAbilities = new Abilities(zeroAbilityScores));
  delete testAbilities;
  
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
    CHECK_THROWS(ErrorInvalidData, testAbilities = new Abilities(abilityScores));
  }
}

TEST(Abilities, AbilitiesAdjustments)
{
  Abilities* testAbilities;
  testAbilities = new Abilities();
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(10, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(0, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->addTempAdjustment(strength, 3));
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(13, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(1, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->addTempModifier(strength, 1));
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(13, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(2, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->removeTempAdjustment(strength, 3));
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(10, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(1, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->removeTempModifier(strength, 1));
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(10, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(0, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->addTempModifier(strength, -2));
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(10, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(-2, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->addTempAdjustment(strength, -3));
  
  LONGS_EQUAL(10, testAbilities->getScore(strength));
  LONGS_EQUAL(0, testAbilities->getModifier(strength));
  LONGS_EQUAL(7, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(-3, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->setScore(strength, 13));
  
  LONGS_EQUAL(13, testAbilities->getScore(strength));
  LONGS_EQUAL(1, testAbilities->getModifier(strength));
  LONGS_EQUAL(10, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(-2, testAbilities->getTotalModifier(strength));
  
  CHECK_NO_THROWS(testAbilities->removeTempAdjustment(strength, -3));
  CHECK_NO_THROWS(testAbilities->removeTempModifier(strength, -2));
  
  LONGS_EQUAL(13, testAbilities->getScore(strength));
  LONGS_EQUAL(1, testAbilities->getModifier(strength));
  LONGS_EQUAL(13, testAbilities->getTotalScore(strength));
  LONGS_EQUAL(1, testAbilities->getTotalModifier(strength));
  
  delete testAbilities;
}