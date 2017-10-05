#include "TournamentRound.h"
#include <sstream>

TournamentRound::TournamentRound()
{
}


TournamentRound::~TournamentRound()
{
	delete _monsterContestents;
}

void TournamentRound::SetupRound(std::vector<Monster*>* monsters)
{
	_monsterContestents = monsters;
}

// Play the round and perform the battling
std::vector<std::string>* TournamentRound::Play()
{
	// Create the vector that will hold a description on who died
	std::vector<std::string>* deathStrings = new std::vector<std::string>;

	// Cache the original number of contestants before the vector starts shrinking
	size_t numberOfContestants = _monsterContestents->size();

	for (int iContestant = 0; iContestant < numberOfContestants; iContestant += 2)
	{
		// Find and cache a random contestant. Remove said contestant from the vector so it doesn't get included in future battles this round
		int contestantIndex = GetRandomNumberInt(0, _monsterContestents->size() - 1);
		Monster* contestant1 = _monsterContestents->at(contestantIndex);
		_monsterContestents->erase(_monsterContestents->begin() + contestantIndex);

		// If there is an odd number of contestants, this will be true and the final contestant gets a free pass to the next round
		if (_monsterContestents->size() == 0) 
		{
			std::stringstream ss;
			ss << "Contestant " << contestant1->GetContestantDetails() << ", a " << contestant1->GetMonsterType() << ", was automatically moved to the next round because of an odd number.";
			deathStrings->push_back(ss.str());
			break;
		}

		// Get the opposing contest using the same technique
		contestantIndex = GetRandomNumberInt(0, _monsterContestents->size() - 1);
		Monster* contestant2 = _monsterContestents->at(contestantIndex);
		_monsterContestents->erase(_monsterContestents->begin() + contestantIndex);

		// While both monsters are alive, deal damage to each and fight to the death
		while (contestant1->GetCurrentHitPoints() > 0 && contestant2->GetCurrentHitPoints() > 0)
		{
			contestant1->ReceiveDamage(contestant2->CalculateDamageToDeal(contestant1->GetDefenceBonus()));
			contestant2->ReceiveDamage(contestant1->CalculateDamageToDeal(contestant2->GetDefenceBonus()));
		}

		if (contestant1->GetCurrentHitPoints() <= 0)
		{
			contestant2->SetDead(); // ????????????????????????? WRONG CONTESTANT BUT STILL WORKS?????

			std::stringstream ss;
			ss << "Contestant " << contestant1->GetContestantDetails() << ", a " << contestant1->GetVictoryText() << " Contestant "
				<< contestant2->GetContestantDetails() << ", a " << contestant2->GetMonsterType() << ".";

			deathStrings->push_back(ss.str());
		}
		else
		{
			contestant1->SetDead(); // ????????????????????????? WRONG CONTESTANT BUT STILL WORKS?????

			std::stringstream ss;
			ss << "Contestant " << contestant2->GetContestantDetails() << ", a " << contestant2->GetVictoryText() << " Contestant "
				<< contestant1->GetContestantDetails() << ", a " << contestant1->GetMonsterType() << ".";

			deathStrings->push_back(ss.str());
		}
	}

	return deathStrings;
}
