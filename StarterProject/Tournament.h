#pragma once

#include "MonsterManager.h"
#include "TournamentRound.h"

class Tournament
{
public:
	Tournament(int numberOfMonsters);
	~Tournament();

	void PlayRound();

private:
	MonsterManager*				_monsterManager;
	int							_currentRound;

};

