//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-20
// Author:      Juho Lepisto
//
// Filename:    Dice.cpp
// Description: This is a dice class, which generates random numbers according to given dice. Max dice is 100d100.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include <cstdlib>
#include <ctime>
#include "../../Errors.h"
#include "Dice.h"

// 2. Local enums, constants and macross

static const int maxDice = 100;
static const int maxDiceValue = 100;

// 3. Local global data structs and variables

bool isSeeded = false;

// 4. Constructor and destructor

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

// 5. Public functions

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

// 6. Protected functions


// 7. Private functions


