#pragma once

#include "Consts.h"
#include <sstream>

class Monster
{
public:
	Monster(MonsterType monsterType, Weapon weapon, int contestantNumber);
	~Monster();

	float CalculateDamageToDeal(float enemyDefenceBonus);
	void ReceiveDamage(float damage);
	void SetDead()									{ _isDead = true; }

	std::string GetVictoryText();
	std::string GetContestantDetails();
	float GetCurrentHitPoints()						{ return _currentHitpoints; }
	float GetDefenceBonus()							{ return _defenceBonus; }
	bool GetDeadStatus()							{ return _isDead; }
	std::string GetMonsterType()					{ return _monsterType.monsterName; }

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

