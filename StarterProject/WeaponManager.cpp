#include "WeaponManager.h"

WeaponManager::WeaponManager()
{
	_weapons = new std::vector<Weapon>;

	std::vector<std::string>* parsedWeapons = ParseConstsFromFile("weapon");

	for (int i = 0; i < parsedWeapons->size(); i++)
	{
		size_t split = parsedWeapons->at(i).find(" ");

		Weapon weapon;
		weapon.weaponName = parsedWeapons->at(i).substr(0, split).c_str();
		weapon.damage = std::stof(parsedWeapons->at(i).substr(split + 1, parsedWeapons->at(i).length()).c_str());

		_weapons->push_back(weapon);
	}
}


WeaponManager::~WeaponManager()
{
	delete _weapons;
}


Weapon WeaponManager::GetRandomWeapon()
{
	float randomIndex = GetRandomNumberInt(0, _weapons->size() - 1);
	return _weapons->at(randomIndex);
}
