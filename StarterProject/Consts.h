#pragma once

#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

static std::vector<std::string>* ParseConstsFromFile(const char* delimiter)
{
	std::vector<std::string>* parsedObjects = new std::vector<std::string>;

	std::ifstream infile("./configFile.txt");
	std::string line;
	std::size_t found = line.find("framerate");

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

static float GetRandomNumberFloat(float min, float max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

static int GetRandomNumberInt(int min, int max)
{
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(min, max); // guaranteed unbiased

	return uni(rng);
}