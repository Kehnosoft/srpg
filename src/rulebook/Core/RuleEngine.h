/*
 * RuleEngine.h
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#ifndef RULEENGINE_H_
#define RULEENGINE_H_

#include "../TypeDefs.h"
#include <string>
#include "../Creatures/RuleCreature.h"
#include "../Creatures/RuleCharacter.h"
#include "../Items/Item.h"

enum attack_result
{
  miss = 0,
  hit,
  critical_miss,
  critical_hit,
  death
};

struct direction_struct
{
    int N;
    int NE;
    int E;
    int SE;
    int S;
    int SW;
    int W;
    int NW;
};

class RuleEngine
{
  public:
    RuleEngine(void);
    ~RuleEngine(void);

    void createEntity(int entityID, char* filename, int fileID);  // TODO: Fix the char* to string* later.
    void destroyEntity(int ID);

    attack_result attack(int attackerID, int defenderID, bf conditions);
    attack_result attack(int attackerID, int defenderID, int range, bf conditions);
    attack_result attackAOO(int attackerID, int defenderID, bf conditions);
    attack_result attackAOO(int attackerID, int defenderID, int range, bf conditions);

    direction_struct move(int moverID, direction_struct neighbourIDs, int visibleIDs);

    // TODO: Trap sense, trap trip

  private:
    //NA
};

#endif /* RULEENGINE_H_ */
