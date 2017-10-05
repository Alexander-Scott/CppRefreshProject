#pragma once

#include "Consts.h"

class WeaponManager
{
public:
	WeaponManager();
	~WeaponManager();

	Weapon GetRandomWeapon();

private:
	std::vector<Weapon>* _weapons;
};

