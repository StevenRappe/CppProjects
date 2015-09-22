/*
 	Steven Rappe
 	test-game.cpp
 
	Runs the game, calls all game class methods and displays output.
 */

#include "game.hpp"

using namespace std;

// Main method
int main() {

	int sizex = 0;
	int sizey = 0;
	int numTurns = 0;
	
	// get user input
	cout << "Please enter the size of the grid (Press Enter after the first number): " << endl;
	cin >> sizex >> sizey;
	cout << "\nPlease enter the number of steps: " << endl;
	cin >> numTurns;
	
	// initialize game
	Game game(sizex, sizey);
	
	// create grid
	game.initializeGrid();
	
	game.printGrid();
	cout << "\n" << endl;
	cout << "start" << endl;
	for (int i=1; i<=numTurns; i++) {

		game.takeTurn();
		cout << "" << endl;
		cout << "\nStep " << i << ": " << endl;
		game.printGrid();
	}
	return 0;
}