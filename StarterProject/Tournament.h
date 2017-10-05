#pragma once

#include "MonsterManager.h"
#include "TournamentRound.h"

class Tournament
{
public:
	Tournament(int numberOfMonsters);
	~Tournament();

	bool PlayRound();

private:
	int CalculateNumberOfRounds(int numberOfMonsters);

private:
	MonsterManager*				_monsterManager;
	int							_currentRound;
	int							_totalRounds;
};

