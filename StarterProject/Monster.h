#pragma once

#include "Consts.h"
#include <sstream>

class Monster
{
public:
	Monster(MonsterType monsterType, Weapon weapon, int contestantNumber);
	~Monster();

	float CalculateDamageToDeal(float enemyDefenceBonus) const;
	float GetCurrentHitPoints() const;
	float GetDefenceBonus() const;

	bool GetDeadStatus() const;

	std::string GetVictoryText() const;
	std::string GetMonsterType() const;
	std::string GetContestantDetails() const;

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

