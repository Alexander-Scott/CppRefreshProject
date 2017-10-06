#pragma once

#include "Monster.h"
#include <vector>

class TournamentRound
{
public:
	TournamentRound();
	~TournamentRound();

	void SetupRound(std::vector<Monster*>* monsters);
	std::vector<std::string>* Play() const;

private:
	static std::string BuildDeathString(Monster* contestant1, Monster* contestant2);
	Monster* GetMonsterContestant() const;

	std::vector<Monster*>* _monsterContestents;
};

