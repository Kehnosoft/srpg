//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-20
// Author:      Juho Lepisto
//
// Filename:    Dice.h
// Description: This is a dice class, which generates random numbers according to given dice. Max dice is 100d100.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef DICE_H_
#define DICE_H_

// 1. External header files


// 2. Global enums, constants and macross


// 3. Global data structs


// 4. Class definition

class Dice
{
  public:
    Dice(int numberOfDice, int diceValue);
    ~Dice(void);
    int roll(void) const;

  private:
    int value;
    int dice;
    int compensation;
};

#endif /* DICE_H_ */
