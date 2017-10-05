#pragma once

#include "Consts.h"
#include <sstream>

class Monster
{
public:
	Monster(MonsterType monsterType, Weapon weapon);
	~Monster();

	float CalculateDamageToGive();
	float GetCurrentHitPoints();
	bool CheckDead();

	void ReceiveDamage(float damage);
	void SetDead();
	std::string GetVictoryText();
	std::string GetDeathText();

private:
	
	void Die();

private:
	MonsterType				_monsterType;
	Weapon					_weapon;

	float					_hitpoints;
	float					_attackAccuracy;
	float					_defenceBonus;

	bool					_isDead;
};

