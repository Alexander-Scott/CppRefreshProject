#pragma once

#include "MonsterManager.h"
#include "TournamentRound.h"

class Tournament
{
public:
	Tournament();
	~Tournament();

private:
	void PlayRound();

private:
	MonsterManager*				_monsterManager;
	int							_currentRound;

};

