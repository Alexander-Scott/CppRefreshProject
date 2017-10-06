#pragma once

#include "MonsterManager.h"
#include "TournamentRound.h"

class Tournament
{
public:
	explicit Tournament(int numberOfMonsters);
	~Tournament();

	bool PlayRound();

private:
	static int CalculateNumberOfRounds(int numberOfMonsters);

	MonsterManager*				_monsterManager;
	int							_currentRound;
	int							_totalRounds;
};

