#include "WeaponManager.h"

// Read from a file, all the types of weapon and their respective damage, to be used in the tournament
WeaponManager::WeaponManager()
{
	_weapons = new std::vector<Weapon>;

	auto parsedWeapons = ParseConstsFromFile("weapon");

	for (int i = 0; i < parsedWeapons->size(); i++)
	{
		const auto split = parsedWeapons->at(i).find(",");

		Weapon weapon;
		weapon.WeaponName = parsedWeapons->at(i).substr(0, split).c_str();
		weapon.Damage = std::stof(parsedWeapons->at(i).substr(split + 1, parsedWeapons->at(i).length()).c_str());

		_weapons->push_back(weapon);
	}

	delete parsedWeapons;
}

WeaponManager::~WeaponManager()
{
	delete _weapons;
}

Weapon WeaponManager::GetRandomWeapon() const
{
	const float randomIndex = GetRandomNumberInt(0, _weapons->size() - 1);
	return _weapons->at(randomIndex);
}
