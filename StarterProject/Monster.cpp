#include "Monster.h"

// Creates a monster object and recieves various parameters. The rest of the attributes are randomly generated
Monster::Monster(const MonsterType monsterType, const Weapon weapon, const int contestantNumber)
{
	_startHitpoints = GetRandomNumberFloat(600, 1000);
	_currentHitpoints = _startHitpoints;

	_attackAccuracy = GetRandomNumberFloat(50, 80);
	_defenceBonus = GetRandomNumberFloat(30, 80);

	_monsterType = monsterType;
	_weapon = weapon;

	_contestantNumber = contestantNumber;

	_isDead = false;
}

Monster::~Monster()
{
}

// Calculates how much damage to deal to the enemy. This monster has to successfully hit the monster (calculated through _attackAccuracy) 
// and the enemy can't block it (calculated through enemyDefenceBonus).
// If both are successful a random damage number is generated and then multiplied based on the monsters weapon's damage
float Monster::CalculateDamageToDeal(const float enemyDefenceBonus) const
{
	auto rand = GetRandomNumberFloat(0, 100);

	if (rand > _attackAccuracy) // Unsuccessful hit
		return 0;

	rand = GetRandomNumberFloat(0, 100);

	if (rand < enemyDefenceBonus) // Enemy blocked it
		return 0;

	rand = GetRandomNumberFloat(1, 10); // Calculate damage
	rand = rand * _weapon.Damage; // Multiply it by the weapons damage
	
	return rand;
}

// Remove an amount of hitpoints from this monsters current hitpoints
void Monster::ReceiveDamage(const float damage)
{
	_currentHitpoints = _currentHitpoints - damage;
}

// Set this monster to dead
void Monster::SetDead()
{
	_isDead = true;
}

// Return the current hitpoints of this monster
float Monster::GetCurrentHitPoints() const
{
	return _currentHitpoints;
}

std::string Monster::GetVictoryText() const
{
	std::stringstream ss;
	ss << _monsterType.MonsterName << ", used a " << _weapon.WeaponName << " to " << _monsterType.AttackStyle;

	return ss.str();
}

std::string Monster::GetMonsterType() const
{
	return _monsterType.MonsterName;
}

std::string Monster::GetContestantDetails() const
{
	std::stringstream ss;

	if (DISPLAY_MONSTER_STATS)
	{
		ss << _contestantNumber << "(A" << _attackAccuracy << ",D" << _defenceBonus << ",H" << _startHitpoints << ")";
	}
	else 
	{
		ss << _contestantNumber;
	}

	return ss.str();
}

float Monster::GetDefenceBonus() const
{
	return _defenceBonus;
}

bool Monster::GetDeadStatus() const
{
	return _isDead;
}
