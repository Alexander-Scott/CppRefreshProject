#include "MonsterManager.h"

MonsterManager::MonsterManager(const int numberOfMonsters)
{
	GetMonsterTypes();

	_weaponManager = new WeaponManager;
	_numberOfMonsters = numberOfMonsters;

	CreateMonsterInstances();
}

MonsterManager::~MonsterManager()
{
	_weaponManager->~WeaponManager();

	delete _monsterTypes;
	delete _monsters;
}

// Read from a file, all the types of monster and their respective attack styles, to be used in the tournament
void MonsterManager::GetMonsterTypes()
{
	_monsterTypes = new std::vector<MonsterType>;

	auto parsedMonsters = ParseConstsFromFile("monster");

	for (auto iMonster = 0; iMonster < parsedMonsters->size(); iMonster++)
	{
		const auto split = parsedMonsters->at(iMonster).find(",");

		MonsterType monsterType;
		monsterType.MonsterName = parsedMonsters->at(iMonster).substr(0, split).c_str();
		monsterType.AttackStyle = parsedMonsters->at(iMonster).substr(split + 1, parsedMonsters->at(iMonster).length()).c_str();

		_monsterTypes->push_back(monsterType);
	}

	delete parsedMonsters;
}

// Instantiate a number of monsters and store them in a vector
void MonsterManager::CreateMonsterInstances()
{
	_monsters = new std::vector<Monster>;

	for (auto iMonster = 0; iMonster < _numberOfMonsters; iMonster++)
	{
		const auto monster = Monster(GetRandomMonsterType(), _weaponManager->GetRandomWeapon(), iMonster + 1);
		_monsters->push_back(monster);
	}
}

// Returns a random monster type
MonsterType MonsterManager::GetRandomMonsterType() const
{
	const float randomMonsterTypeIndex = GetRandomNumberInt(0, _monsterTypes->size() - 1);
	return _monsterTypes->at(randomMonsterTypeIndex);
}

// Returns a pointer to the vector containing all the monsters
std::vector<Monster>* MonsterManager::GetMonsters() const
{
	return _monsters;
}


