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

/// Play the round and perform the battling
std::vector<std::string>* TournamentRound::Play()
{
	// Create the vector that will hold a description on who died
	auto deathStrings = new std::vector<std::string>;

	// Cache the original number of contestants before the vector starts shrinking
	auto numberOfContestants = _monsterContestents->size();

	for (auto iContestant = 0; iContestant < numberOfContestants; iContestant += 2)
	{
		// Find and cache a random contestant. Remove said contestant from the vector so it doesn't get included in future battles this round
		auto contestant1 = GetMonsterContestant();

		// If there is an odd number of contestants, this will be true and the final contestant gets a free pass to the next round
		if (_monsterContestents->size() == 0)
		{
			std::stringstream ss;
			ss << "Contestant " << contestant1->GetContestantDetails() << ", a " << contestant1->GetMonsterType() << ", was automatically moved to the next round because of an odd number.";

			deathStrings->push_back(ss.str());
			break;
		}

		// Get the opposing contestant
		auto contestant2 = GetMonsterContestant();

		// While both monsters are alive, deal damage to each and fight to the death
		while (contestant1->GetCurrentHitPoints() > 0 && contestant2->GetCurrentHitPoints() > 0)
		{
			contestant1->ReceiveDamage(contestant2->CalculateDamageToDeal(contestant1->GetDefenceBonus()));
			contestant2->ReceiveDamage(contestant1->CalculateDamageToDeal(contestant2->GetDefenceBonus()));
		}

		// Check who has died (hp less than 0) and then build a death string from the contestants details
		if (contestant1->GetCurrentHitPoints() <= 0 && contestant2->GetCurrentHitPoints() <= 0)
		{
			deathStrings->push_back(BuildDoubleDeathString(contestant1, contestant2));
		}
		else if (contestant1->GetCurrentHitPoints() <= 0)
		{
			deathStrings->push_back(BuildDeathString(contestant2, contestant1));
		}
		else if (contestant2->GetCurrentHitPoints() <= 0)
		{
			deathStrings->push_back(BuildDeathString(contestant1, contestant2));
		}
	}

	return deathStrings;
}

std::string TournamentRound::BuildDeathString(Monster* winner, Monster* loser)
{
	loser->SetDead();

	std::stringstream ss;
	ss << "Contestant " << winner->GetContestantDetails() << ", a " << winner->GetVictoryText() << " Contestant "
		<< loser->GetContestantDetails() << ", a " << loser->GetMonsterType() << ", with just " << winner->GetCurrentHitPoints() << " hitpoints remaining!";

	return ss.str();
}

std::string TournamentRound::BuildDoubleDeathString(Monster * contestant1, Monster * contestant2)
{
	contestant1->SetDead();
	contestant2->SetDead();

	std::stringstream ss;
	ss << "Contestant " << contestant1->GetContestantDetails() << ", a " << contestant1->GetMonsterType() << ", and Contestant " 
		<< contestant2->GetContestantDetails() << ", a " << contestant2->GetMonsterType() << ", killed eachother!";

	return ss.str();
}

// Find and cache a random contestant. Remove said contestant from the vector so it doesn't get included in future battles this round
Monster* TournamentRound::GetMonsterContestant()
{
	auto contestantIndex = GetRandomNumberInt(0, _monsterContestents->size() - 1);
	auto contestant1 = _monsterContestents->at(contestantIndex);
	_monsterContestents->erase(_monsterContestents->begin() + contestantIndex);

	return contestant1;
}
