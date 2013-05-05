//-------------------------------------------------------------------------------------------------
// Project:     SRPG
// Created:     2013-03-28
// Author:      Juho Lepisto
//
// Filename:    Attack.cpp
// Description: This is an attack class that generates hit and damage rolls according to the
//              creature's stats and equipment.
// Notes:       -
//-------------------------------------------------------------------------------------------------

// 1. Internal header files

#include "../../Errors.h"
#include "Attack.h"

// 2. Local enums, constants and macross


// 3. Local global data structs and variables


// 4. Constructor and destructor

Attack::Attack(const Abilities* abilityPointer) : abilities(abilityPointer)
{
  return;
}

Attack::~Attack(void)
{
  return;
}

// 5. Public functions


// 6. Protected functions


// 7. Private functions

