/*
 * Character.h
 *
 *  Created on: 13.3.2013
 *      Author: Juho L
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

enum character_profession
{
  battle_unit = 0
};

enum character_race
{
  eagle = 0
};

typedef struct
{
  character_profession profession;
  character_race race;
} character_type;

class Character
{
  public:
    //NA

  private:
    //NA
};

#endif /* CHARACTER_H_ */
