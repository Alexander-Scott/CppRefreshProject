#pragma once

#include "Monster.h"

#include <vector>

class TournamentRound
{
public:
	TournamentRound();
	~TournamentRound();

	void SetupRound(std::vector<Monster*>* monsters);
	std::vector<std::string>* Play();

private:
	std::vector<Monster*>* _monsterContestents;
};

