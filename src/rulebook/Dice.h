/*
 * Dice.h
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#ifndef DICE_H_
#define DICE_H_

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
