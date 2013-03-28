/*
 * Creature.cpp
 *
 *  Created on: Mar 28, 2013
 *      Author: juhol
 */

#include "../Errors.h"
#include "../TypeDefs.h"
#include "Abilities.h"
#include "Attack.h"
#include "Defence.h"
#include "SaveThrows.h"
#include "HitPoints.h"
#include "../Items/Inventory.h"
#include "Creature.h"

Creature::Creature(const init_stats initStats) :
health(initStats.hitPoints, &defence),
inventory(&abilities),
saves(&abilities),
defence(&abilities),
attack(&abilities),
abilities(initStats.abilityScores)
{

  return;
}
