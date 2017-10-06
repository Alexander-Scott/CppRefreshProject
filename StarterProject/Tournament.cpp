#include "Tournament.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

Tournament::Tournament(const int numberOfMonsters)
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

// Starts a new tournament round and battles the contestants among one another. Returns true if the tournament is complete
bool Tournament::PlayRound()
{
	// Initalise a new tournament round
	auto tournamentRound = new TournamentRound;

	// This vector will hold all the monsters that are currently competing. Worked out from if they are dead or not.
	auto competingMonsters = new std::vector<Monster*>;
	auto totalMonsters = _monsterManager->GetMonsters();

	for (auto i = 0; i < totalMonsters->size(); i++)
	{
		if (!totalMonsters->at(i).GetDeadStatus()) // If the monster is not dead, they will be in the next round
		{
			competingMonsters->push_back(&totalMonsters->at(i));
		}
	}

	// Load the tournament round with the competing monsters
	tournamentRound->SetupRound(competingMonsters);

	std::cout << "Round " << _currentRound << " starting..." << std::endl;
	std::cout << "===========================================" << std::endl;

	// Play the round and return the vector of strings containg how and which monsters were killed
	auto deathStrings = tournamentRound->Play();

	if (ROUND_RESULT_DELAY) std::this_thread::sleep_for(std::chrono::milliseconds(GetRandomNumberInt(1000, 1500)));

	// Print out results from the round
	for (auto i = 0; i < deathStrings->size(); i++)
	{
		std::cout << deathStrings->at(i) << std::endl;

		if (ROUND_RESULT_DELAY)	std::this_thread::sleep_for(std::chrono::milliseconds(GetRandomNumberInt(10, 500)));
	}

	std::cout << "===========================================" << std::endl;

	_currentRound++; // Increment the round number
	
	delete tournamentRound;
	delete deathStrings;

	if (_currentRound > _totalRounds) // If we've reached the final round
	{
		for (auto i = 0; i < totalMonsters->size(); i++)
		{
			if (!totalMonsters->at(i).GetDeadStatus()) // Find only alive contestant
			{
				std::cout << "Tournament Complete. Contestant " << totalMonsters->at(i).GetContestantDetails() << ", a " 
					<< totalMonsters->at(i).GetMonsterType() << ", is the winner!" << std::endl;

				return true;
			}
		}
	}

	std::cout << "Press any key to advance to the next round." << std::endl;
	return false;
}

// Simple function that will calculate the number of rounds that will need to be played based on the number of monsters created
int Tournament::CalculateNumberOfRounds(int numberOfMonsters)
{
	auto numberOfRounds = 0;

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
