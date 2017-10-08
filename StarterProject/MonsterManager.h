#pragma once

#include "Monster.h"
#include "Consts.h"
#include "WeaponManager.h"

class MonsterManager
{
public:
	MonsterManager(int numberOfMonsters);
	~MonsterManager();

	std::vector<Monster>* GetMonsters();

private:
	void GetMonsterTypes();
	void CreateMonsterInstances();
	MonsterType GetRandomMonsterType();

private:
	std::vector<MonsterType>*		_monsterTypes;
	std::vector<Monster>*			_monsters;

	WeaponManager*					_weaponManager;

	int								_numberOfMonsters;
};

