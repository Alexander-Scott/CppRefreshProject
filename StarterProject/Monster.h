#pragma once

#include "Consts.h"
#include <sstream>

class Monster
{
public:
	Monster(MonsterType monsterType, Weapon weapon, int contestantNumber);
	~Monster();

	float CalculateDamageToGive(float enemyDefenceBonus);
	float GetCurrentHitPoints();
	bool CheckDead();

	void ReceiveDamage(float damage);
	void SetDead();

	std::string GetVictoryText();
	std::string GetDeathText();
	int GetContestantNumber();
	float GetDefenceBonus();

private:
	MonsterType				_monsterType;
	Weapon					_weapon;

	float					_startHitpoints;
	float					_hitpoints;
	float					_attackAccuracy;
	float					_defenceBonus;

	bool					_isDead;

	int						_contestantNumber;
};

