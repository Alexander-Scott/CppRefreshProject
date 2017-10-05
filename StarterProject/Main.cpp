#include <iostream>
#include <string>

#include "Tournament.h"

using namespace std;

void main()
{
	GameState gameState = WaitingForFirstInput;
	Tournament* tournament = nullptr;

	// Update loop
	while (1) 
	{ 
		string input;

		switch (gameState)
		{
			case WaitingForFirstInput:
				cout << "Enter number of monsters: ";
				getline(cin, input);

				try 
				{
					int numberOfMonsters = 0;
					numberOfMonsters = std::stoi(input);
					tournament = new Tournament(numberOfMonsters);
					cout << "Tournament created with " << numberOfMonsters << " monsters. Press any key to start the tournament." << std::endl;
					gameState = WaitingToStartRound;
				}
				catch (int e) 
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
		}
	}
}