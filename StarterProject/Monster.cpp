#include "Monster.h"



Monster::Monster(MonsterType monsterTyp, Weapon weapon, int contestantNumber)
{
	_startHitpoints = GetRandomNumberFloat(600, 1000);
	_hitpoints = _startHitpoints;

	_attackAccuracy = GetRandomNumberFloat(50, 80); // 0 TO 100
	_defenceBonus = GetRandomNumberFloat(30, 80); // 0 TO 100

	_monsterType = monsterTyp;
	_weapon = weapon;

	_contestantNumber = contestantNumber;

	_isDead = false;
}


Monster::~Monster()
{
}

float Monster::CalculateDamageToGive(float enemyDefenceBonus)
{
	float rand = GetRandomNumberFloat(0, 100);

	if (rand > _attackAccuracy) // Unsuccessful hit
		return 0;

	rand = GetRandomNumberFloat(0, 100);

	if (rand < enemyDefenceBonus) // Enemy blocked it
		return 0;

	rand = GetRandomNumberFloat(1, 10); // Calculate damage
	rand = rand * _weapon.damage; // Multiply it by the weapons damage
	
	return rand;
}

float Monster::GetCurrentHitPoints()
{
	return _hitpoints;
}

void Monster::ReceiveDamage(float damage)
{
	_hitpoints = _hitpoints - damage;
}

void Monster::SetDead()
{
	_isDead = true;
}

std::string Monster::GetVictoryText()
{
	std::stringstream ss;
	ss << _monsterType.monsterName << ", used a " << _weapon.weaponName << " to " << _monsterType.attackStyle;

	return ss.str();
}

std::string Monster::GetDeathText()
{
	return _monsterType.monsterName;
}

int Monster::GetContestantNumber()
{
	return _contestantNumber;
}

float Monster::GetDefenceBonus()
{
	return _defenceBonus;
}

bool Monster::CheckDead()
{
	return _isDead;
}
