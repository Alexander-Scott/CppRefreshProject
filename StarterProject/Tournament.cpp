#include "Tournament.h"
#include <iostream>
#include <string>

Tournament::Tournament(int numberOfMonsters)
{
	_monsterManager = new MonsterManager(numberOfMonsters);

	_currentRound = 1;
	_totalRounds = CalculateNumberOfRounds(numberOfMonsters);
}


Tournament::~Tournament()
{
	_monsterManager->~MonsterManager();
	delete _monsterManager;
}

bool Tournament::PlayRound()
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

	if (_currentRound > _totalRounds)
	{
		for (int i = 0; i < totalMonsters->size(); i++)
		{
			if (!totalMonsters->at(i).CheckDead())
			{
				std::cout << "Tournament Complete. Contestant " << totalMonsters->at(i).GetContestantNumber() << ", a " << totalMonsters->at(i).GetDeathText() << ", is the winner!" << std::endl;
				return true;
			}
		}
	}

	std::cout << "Press any key to advance to the next round." << std::endl;
	return false;
}

int Tournament::CalculateNumberOfRounds(int numberOfMonsters)
{
	int numberOfRounds = 0;

	while (numberOfMonsters != 1)
	{
		if (numberOfMonsters % 2 != 0)
		{
			numberOfMonsters++;
		}

		numberOfMonsters = numberOfMonsters / 2;
		numberOfRounds++;
	}

	return numberOfRounds;
}
