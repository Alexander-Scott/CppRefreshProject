#include "Tournament.h"
#include <iostream>
#include <string>

Tournament::Tournament(int numberOfMonsters)
{
	_monsterManager = new MonsterManager(numberOfMonsters);
	_currentRound = 1;
}


Tournament::~Tournament()
{
	_monsterManager->~MonsterManager();
	delete _monsterManager;
}

void Tournament::PlayRound()
{
	TournamentRound* tournamentRound = new TournamentRound;

	std::vector<Monster>* totalMonsters = _monsterManager->GetMonsters();
	std::vector<Monster*>* competingMonsters = new std::vector<Monster*>;

	for (int i = 0; i < totalMonsters->size(); i++)
	{
		if (!totalMonsters->at(i).CheckDead())
		{
			competingMonsters->push_back(&totalMonsters->at(i));
		}
	}

	tournamentRound->SetupRound(competingMonsters);

	std::cout << "Round " << _currentRound << " starting..." << std::endl;
	std::cout << "===========================================" << std::endl;

	std::vector<std::string>* deathStrings = tournamentRound->Play();

	// Print out results from round
	for (int i = 0; i < deathStrings->size(); i++)
	{
		std::cout << deathStrings->at(i) << std::endl;
	}

	std::cout << "===========================================" << std::endl;

	_currentRound++;
	
	delete tournamentRound;
	delete deathStrings;
}
