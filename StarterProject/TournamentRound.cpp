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

	for (int i = 0; i < _monsterContestents->size(); i += 2)
	{
		// While both monsters are alive
		while (_monsterContestents->at(i)->GetCurrentHitPoints() > 0 &&
			_monsterContestents->at(i + 1)->GetCurrentHitPoints() > 0)
		{
			_monsterContestents->at(i)->ReceiveDamage(_monsterContestents->at(i + 1)->CalculateDamageToGive());
			_monsterContestents->at(i + 1)->ReceiveDamage(_monsterContestents->at(i)->CalculateDamageToGive());
		}

		if (_monsterContestents->at(i)->GetCurrentHitPoints() <= 0)
		{
			// MONSTER i IS DEAD
			_monsterContestents->at(i)->SetDead();

			std::stringstream ss;
			ss << "Contestant " << i << ", a " << _monsterContestents->at(i)->GetVictoryText() << " Contestant " 
				<< i + 1 << ", a " << _monsterContestents->at(i + 1)->GetDeathText() << ".";

			deathStrings->push_back(ss.str());
		}
		else
		{
			// MONSTER i+1 IS DEAD
			_monsterContestents->at(i+1)->SetDead();

			std::stringstream ss;
			ss << "Contestant " << i+1 << ", a " << _monsterContestents->at(i+1)->GetVictoryText() << " Contestant "
				<< i << ", a " << _monsterContestents->at(i)->GetDeathText();

			deathStrings->push_back(ss.str());
		}
	}

	return deathStrings;
}
