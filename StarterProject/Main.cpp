#include <iostream>
#include <string>

#include "Tournament.h"

using namespace std;

void main()
{
	auto gameState = WaitingForFirstInput;
	Tournament* tournament = nullptr;

	// Update loop
	while (true)
	{
		string input;

		switch (gameState)
		{
		case WaitingForFirstInput:
			cout << "Enter number of monsters: ";
			getline(cin, input);

			try
			{
				const auto numberOfMonsters = std::stoi(input);
				tournament = new Tournament(numberOfMonsters);

				cout << "Tournament created with " << numberOfMonsters << " monsters. Press any key to start the tournament." << std::endl;
				gameState = WaitingToStartRound;
			}
			catch (std::exception& e)
			{
				cout << "Failed to parse integer. Try again" << std::endl;
			}

			break;

		case WaitingToStartRound:
			getline(cin, input);

			if (tournament->PlayRound())
			{
				gameState = TournamentComplete;
			}
			break;

		default:;
		}
	}
}
