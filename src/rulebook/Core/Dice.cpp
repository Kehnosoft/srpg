/*
 * Dice.cpp
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#include <cstdlib>
#include <ctime>
#include "../Errors.h"
#include "Dice.h"

static const int maxDice = 100;
static const int maxDiceValue = 100;
bool isSeeded = false;

Dice::Dice(int numberOfDice, int diceValue)
{
  if((numberOfDice > 0) && (diceValue > 0) &&
     (numberOfDice <= maxDice) && (diceValue <= maxDiceValue))
  {
    dice = numberOfDice;
    value = diceValue;
    compensation = RAND_MAX - (RAND_MAX % value);
    if(!isSeeded)
    {
      srand(time(0));
      isSeeded = true;
    }
  }
  else
  {
    throw ErrorInvalidData();
  }
  return;
}

Dice::~Dice(void)
{
  return;
}

int Dice::roll(void) const
{
  int sum = 0;
  int roll = 0;
  for(int i = 0; i < dice; i++)
  {
    do {
      roll = rand();
    } while(roll > compensation);
    sum += (roll % value) + 1;
  }
  return sum;
}


