#pragma once

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const bool DISPLAY_MONSTER_STATS = false;
const bool ROUND_RESULT_DELAY = false;

enum GameState 
{
	WaitingForFirstInput,
	WaitingToStartRound,
	TournamentComplete
};

struct MonsterType 
{
	std::string monsterName;
	std::string attackStyle;
};

struct Weapon 
{
	std::string weaponName;
	float damage;
};

// Reads in values from a text file and returns them as a vector of strings. Format is: 'delimiter object'.
static std::vector<std::string>* ParseConstsFromFile(const char* delimiter)
{
	std::vector<std::string>* parsedObjects = new std::vector<std::string>;

	std::ifstream infile("./configFile.txt");
	std::string line;

	while (std::getline(infile, line, '\n'))
	{
		if (line.compare(0, strlen(delimiter), delimiter) == 0)
		{
			line.erase(0, strlen(delimiter) + 1);
			parsedObjects->push_back(line);
		}
	}

	return parsedObjects;
}

// Returns a random float between two floats
static float GetRandomNumberFloat(float min, float max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

// Returns a random integer between two integers
static int GetRandomNumberInt(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	return uni(rng);
}