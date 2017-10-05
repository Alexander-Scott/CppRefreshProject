#pragma once

#include "Consts.h"
#include <sstream>

class Monster
{
public:
	Monster(MonsterType monsterType, Weapon weapon, int contestantNumber);
	~Monster();

	float CalculateDamageToDeal(float enemyDefenceBonus);
	float GetCurrentHitPoints();
	float GetDefenceBonus();

	bool GetDeadStatus();

	std::string GetVictoryText();
	std::string GetMonsterType();
	std::string GetContestantDetails();

	void ReceiveDamage(float damage);
	void SetDead();

private:
	MonsterType				_monsterType;
	Weapon					_weapon;

	int						_contestantNumber;

	float					_startHitpoints;
	float					_currentHitpoints;
	float					_attackAccuracy;
	float					_defenceBonus;

	bool					_isDead;
};

