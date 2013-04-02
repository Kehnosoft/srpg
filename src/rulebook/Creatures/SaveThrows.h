/*
 * SaveThrows.h
 *
 *  Created on: 20.3.2013
 *      Author: Juho L
 */

#ifndef SAVETHROWS_H_
#define SAVETHROWS_H_

#include "../Core/Dice.h"
#include "Abilities.h"

class SaveThrows
{
  public:
    enum save_enum
    {
      fort = 0,
      reflex,
      will,
      saves
    };

    SaveThrows(const Abilities* abilityPointer);
    ~SaveThrows();

    void setBase(save_enum type, int base);
    void addAttuneMod(save_enum type, int attuneMod);
    void removeAttuneMod(save_enum type, int attuneMod);
    void addMiscMod(save_enum type, int miscMod);
    void removeMiscMod(save_enum type, int miscMod);
    void addTempMod(save_enum type, int tempMod);
    void removeTempMod(save_enum type, int tempMod);

    int getSave(save_enum type) const;

  private:
    struct saveThrow_struct
    {
      int base;
      int attunement;
      int miscMod;
      int tempMod;
    };

    saveThrow_struct saveThrowMods[saves];
    const Dice saveDie;
    const Abilities* abilities;
};

#endif /* SAVETHROWS_H_ */
