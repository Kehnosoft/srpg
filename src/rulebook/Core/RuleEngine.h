/*
 * RuleEngine.h
 *
 *  Created on: Mar 23, 2013
 *      Author: juhol
 */

#ifndef RULEENGINE_H_
#define RULEENGINE_H_

enum attack_result
{
  miss = 0,
  hit,
  critical_miss,
  critical_hit,
  death
};

struct vicinity_struct
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

    attack_result attack(int attackerID, int defenderID);
    vicinity_struct move(int moverID, vicinity_struct neighbourIDs);

  private:
    //NA
};

#endif /* RULEENGINE_H_ */
