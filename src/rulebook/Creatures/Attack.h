/*
 * Attack.h
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#ifndef ATTACK_H_
#define ATTACK_H_

struct damage_struct
{
    bf type;
    int amount;
};

class Attack
{
  public:
    Attack(const Abilities* abilityPointer);
    ~Attack(void);

  private:
    const Abilities* abilities;
};


#endif /* ATTACK_H_ */
