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

std::vector<std::string>* TournamentRound::Play()
{
	std::vector<std::string>* deathStrings = new std::vector<std::string>;

	size_t size = _monsterContestents->size();

	for (int i = 0; i < size; i += 2)
	{
		int rand1 = GetRandomNumberInt(0, _monsterContestents->size() - 1);
		Monster* contestant1 = _monsterContestents->at(rand1);
		_monsterContestents->erase(_monsterContestents->begin() + rand1);

		if (_monsterContestents->size() == 0) // If there is an odd number of contestants, the final contestant gets a free pass to the next round
		{
			std::stringstream ss;
			ss << "Contestant " << contestant1->GetContestantNumber() << ", a " << contestant1->GetDeathText() << ", was automatically moved to the next round because of an odd number.";
			deathStrings->push_back(ss.str());
			break;
		}

		int rand2 = GetRandomNumberInt(0, _monsterContestents->size() - 1);
		Monster* contestant2 = _monsterContestents->at(rand2);
		_monsterContestents->erase(_monsterContestents->begin() + rand2);

		// While both monsters are alive
		while (contestant1->GetCurrentHitPoints() > 0 &&
			contestant2->GetCurrentHitPoints() > 0)
		{
			contestant1->ReceiveDamage(contestant2->CalculateDamageToGive(contestant1->GetDefenceBonus()));
			contestant2->ReceiveDamage(contestant1->CalculateDamageToGive(contestant2->GetDefenceBonus()));
		}

		if (contestant1->GetCurrentHitPoints() <= 0)
		{
			// MONSTER i IS DEAD
			contestant2->SetDead();

			std::stringstream ss;
			ss << "Contestant " << contestant1->GetContestantNumber() << ", a " << contestant1->GetVictoryText() << " Contestant "
				<< contestant2->GetContestantNumber() << ", a " << contestant2->GetDeathText() << ".";

			deathStrings->push_back(ss.str());
		}
		else
		{
			// MONSTER i+1 IS DEAD
			contestant1->SetDead();

			std::stringstream ss;
			ss << "Contestant " << contestant2->GetContestantNumber() << ", a " << contestant2->GetVictoryText() << " Contestant "
				<< contestant1->GetContestantNumber() << ", a " << contestant1->GetDeathText() << ".";

			deathStrings->push_back(ss.str());
		}
	}

	return deathStrings;
}
