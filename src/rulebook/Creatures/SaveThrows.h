//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-20
// Author:      Juho Lepisto
//
// Filename:    SaveThrows.h
// Description: This is a save throws class that rolls save throws according to stats and other
//              bonuses.
// Notes:       -
//-------------------------------------------------------------------------------------------------

#ifndef SAVETHROWS_H_
#define SAVETHROWS_H_

// 1. External header files

#include "../Core/Dice.h"
#include "Abilities.h"

// 2. Global enums, constants and macross


// 3. Global data structs


// 4. Class definition

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
