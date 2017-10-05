#include <iostream>
#include <string>

#include "Tournament.h"

using namespace std;

void Update()
{
	// Game update code goes here
	cout << "Hello World!" << endl;
}

void main()
{
	Tournament* tournament = new Tournament;

	while (1)
	{ 
		string input;
		getline(cin, input);

		if (!input.empty())
		{
			// Quit
			return;
		}

		Update();
	}
}