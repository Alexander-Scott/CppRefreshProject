#include "Monster.h"



Monster::Monster(MonsterType monsterTyp, Weapon weapon)
{
	_hitpoints = GetRandomNumberFloat(600, 1000);
	_attackAccuracy = GetRandomNumberFloat(50, 80); // 0 TO 100
	_defenceBonus = GetRandomNumberFloat(30, 80); // 0 TO 100

	_monsterType = monsterTyp;
	_weapon = weapon;

	_isDead = false;
}


Monster::~Monster()
{
}

void Monster::Die()
{
}

float Monster::CalculateDamageToGive()
{
	return 10;
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

bool Monster::CheckDead()
{
	return _isDead;
}
