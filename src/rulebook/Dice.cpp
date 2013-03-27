/*
 * Dice.cpp
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#include <cstdlib>
#include <ctime>
#include "Errors.h"
#include "Dice.h"

bool isSeeded = false;

Dice::Dice(int numberOfDice, int diceValue)
{
  if((numberOfDice > 0) && (diceValue > 0))
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


