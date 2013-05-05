/*
 * RuleBookDiceTest.cpp
 *
 *  Created on: Apr 28, 2013
 *      Author: juhol
 */

#include <iostream>

#include "../../src/Errors.h"
#include "../../src/rulebook/Core/Dice.h"
#include "RuleBookDiceTest.h"

using namespace std;

TEST_GROUP(Dice)
{
  Dice* singleDie;
  static const int repeats = 10000000;
  
  static const int singleDieValue = 20;
  
  static const int minimumOneDie = 1;
  static const int maximumOneDie = singleDieValue;
  
  // The deviation must be less than 1%
  static const int expectedSingleMinimum = (99 * repeats)/(100 * maximumOneDie);
  static const int expectedSingleMaximum = (101 * repeats)/(100 * maximumOneDie);

  void setup()
  {
    singleDie = new Dice(1, singleDieValue);
  }
  
  void teardown()
  {
    delete singleDie;
  }
};

TEST(Dice, EvenRollDeviationOnOneDie)
{
  int rolls[maximumOneDie+2] = {0};
  
  for(int i = 0; i < repeats; i++)
  {
    int value = singleDie->roll();
    rolls[value]++;
  }
  
  LONGS_EQUAL(0, rolls[0]);
  LONGS_EQUAL(0, rolls[maximumOneDie+1]);
  
  for(int i = minimumOneDie; i <= maximumOneDie; i++)
  {
    CHECK_FALSE(rolls[i] < expectedSingleMinimum);
    CHECK_FALSE(rolls[i] > expectedSingleMaximum);
  }
}

TEST(Dice, ExceptionOnInvalidParameters)
{
  Dice* invalidDie;
  CHECK_THROWS(ErrorInvalidData, invalidDie = new Dice(0, 10));
  CHECK_THROWS(ErrorInvalidData, invalidDie = new Dice(-1, 10));
  CHECK_THROWS(ErrorInvalidData, invalidDie = new Dice(1, 0));
  CHECK_THROWS(ErrorInvalidData, invalidDie = new Dice(1, -1));
  CHECK_THROWS(ErrorInvalidData, invalidDie = new Dice(101, 100));
  CHECK_THROWS(ErrorInvalidData, invalidDie = new Dice(100, 101));
  CHECK_NO_THROWS(invalidDie = new Dice(100, 100));
  delete invalidDie;
}