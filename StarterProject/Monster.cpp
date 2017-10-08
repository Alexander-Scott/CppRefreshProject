#include "Monster.h"

// Creates a monster object and recieves various parameters. The rest of the attributes are randomly generated
Monster::Monster(MonsterType monsterType, Weapon weapon, int contestantNumber)
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
float Monster::CalculateDamageToDeal(float enemyDefenceBonus)
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

// Remove an amount of hitpoints from this monsters current hitpoints
void Monster::ReceiveDamage(float damage)
{
	_currentHitpoints = _currentHitpoints - damage;
}

// Return a string built from name, weapon and attack style
std::string Monster::GetVictoryText()
{
	std::stringstream ss;
	ss << _monsterType.monsterName << ", used a " << _weapon.weaponName << " to " << _monsterType.attackStyle;

	return ss.str();
}

// Return a string containing the contestants details and optionally stats
std::string Monster::GetContestantDetails()
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