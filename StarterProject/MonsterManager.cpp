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


void MonsterManager::GetMonsterTypes()
{
	_monsterTypes = new std::vector<MonsterType>;

	std::vector<std::string>* parsedMonsters = ParseConstsFromFile("monster");

	for (int i = 0; i < parsedMonsters->size(); i++)
	{
		size_t split = parsedMonsters->at(i).find(" ");

		MonsterType monsterType;
		monsterType.monsterName = parsedMonsters->at(i).substr(0, split).c_str();
		monsterType.attackStyle = parsedMonsters->at(i).substr(split + 1, parsedMonsters->at(i).length()).c_str();

		_monsterTypes->push_back(monsterType);
	}
}


void MonsterManager::CreateMonsterInstances()
{
	_monsters = new std::vector<Monster>;

	for (int i = 0; i < _numberOfMonsters; i++)
	{
		float randomIndex = GetRandomNumberInt(0, _monsterTypes->size() - 1);
		Monster monster = Monster(_monsterTypes->at(randomIndex), _weaponManager->GetRandomWeapon(), i + 1);
		_monsters->push_back(monster);
	}
}

std::vector<Monster>* MonsterManager::GetMonsters()
{
	return _monsters;
}
