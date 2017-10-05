#include "MonsterManager.h"

MonsterManager::MonsterManager(int numberOfMonsters)
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

	std::vector<std::string>* parsedMonsters = ParseConstsFromFile("monster");

	for (int iMonster = 0; iMonster < parsedMonsters->size(); iMonster++)
	{
		size_t split = parsedMonsters->at(iMonster).find(",");

		MonsterType monsterType;
		monsterType.monsterName = parsedMonsters->at(iMonster).substr(0, split).c_str();
		monsterType.attackStyle = parsedMonsters->at(iMonster).substr(split + 1, parsedMonsters->at(iMonster).length()).c_str();

		_monsterTypes->push_back(monsterType);
	}

	delete parsedMonsters;
	parsedMonsters = nullptr;
}

// Instantiate a number of monsters and store them in a vector
void MonsterManager::CreateMonsterInstances()
{
	_monsters = new std::vector<Monster>;

	for (int iMonster = 0; iMonster < _numberOfMonsters; iMonster++)
	{
		Monster monster = Monster(GetRandomMonsterType(), _weaponManager->GetRandomWeapon(), iMonster + 1);
		_monsters->push_back(monster);
	}
}

// Returns a random monster type
MonsterType MonsterManager::GetRandomMonsterType()
{
	float randomMonsterTypeIndex = GetRandomNumberInt(0, _monsterTypes->size() - 1);
	return _monsterTypes->at(randomMonsterTypeIndex);
}

// Returns a pointer to the vector containing all the monsters
std::vector<Monster>* MonsterManager::GetMonsters()
{
	return _monsters;
}


