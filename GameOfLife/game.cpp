/*
 	Steven Rappe
 	game.cpp
	
	Game class, controls the initialization of the game grid, and invokes
	the methods takeTurn, to progress the game, and checkSurroundings, to 
	determine what action to take at each turn.
 */

#include "game.hpp"
#include <cstdlib>
#include <math.h>
#include <ctime>

// Constructor for GameOfLife class
Game::Game(int sx, int sy) : grid(50), sizex(sx), sizey(sy),
		numTurns(0), sheepCount(0), wolfCount(0), farmerCount(0),
				emptyCount(0) {
}

// creates grid
void Game::initializeGrid() {
	std::srand(time(NULL));
	int choice = 0;
	
	for (int i = 0; i < this->sizex; i++) {
	    grid[i] = std::vector<char>(50);
		for (int j = 0; j < this->sizey; j++) {
			
			choice = (std::rand()%4);
			if (choice == 0) {
			    this->grid[i][j] = 'S';
			}
			else if (choice == 1) {
				this->grid[i][j] = 'W';
			}
			else if (choice == 2) {
				this->grid[i][j] = 'F';
			}
			else {
				this->grid[i][j] = '.';
			}
		}
	}
}

// advances the game 1 turn
void Game::takeTurn() {
	
	int farmerMove = 0;
	int gridCount = 0;
	std::srand(time(NULL));

	for (int i=0; i<this->sizex; i++) {
		for (int j=0; j<this->sizey; j++) {
			// Call checkSurroundings
			checkSurroundings(i,j);
			
			if (this->grid[i][j] == 'S') {
				if (this->sheepCount > 3) {
					this->grid[i][j] = '.';
				}
				else if (wolfCount >= 1) {
					this->grid[i][j] = '.';
				}
			}
			else if (this->grid[i][j] == 'W') {
				
				if (this->wolfCount > 3) {
					this->grid[i][j] = '.';
				}
				else if (this->farmerCount >= 1) {
					this->grid[i][j] = '.';
				}
				else if (this->sheepCount == 0) {
					this->grid[i][j] = '.';
				}
			}
			else if (this->grid[i][j] == 'F') {
				
				gridCount = 0;
				// Farmer movement
				farmerMove = (std::rand()%(1+(this->emptyCount))-1);
				for (int k=-1; k<=1; k++) {
					for (int l=-1; l<=1; l++) {
						if ((k!=0)||(l!=0)) {	
							if (((i+k)>=0)&&((j+l)>=0)&&((i+k)<sizex)&&((j+l)<sizey)) {
								if (this->grid[i+k][j+l] == '.') {
									if(farmerMove == gridCount) {
										grid[i+k][j+l] = 'F';
										grid[i][j] = '.';
									}
								gridCount++;
								}
							}
						}
					}
				}
			}
			else {
				if (sheepCount == 2) {
					this->grid[i][j] = 'S';
				}
				else if (wolfCount == 2) {
					this->grid[i][j] = 'W';
				}
				else if (farmerCount == 2) {
					this->grid[i][j] = 'F';
				}
			}
		}
	}
}
// checks the surrounding cells of the current cell
void Game::checkSurroundings(int i, int j) {

	this->sheepCount = 0;
	this->wolfCount = 0;
	this->farmerCount = 0;
	this->emptyCount = 0;
	
	for (int k=-1; k<=1; k++) {
		for (int l=-1; l<=1; l++) {
			if ((k!=0)||(l!=0)) {
				if (((i+k)>=0)&&((j+l)>=0)&&((i+k)<sizex)&&((j+l)<sizey)) {
				
					if (this->grid[i+k][j+l] == 'S') {
						this->sheepCount++;
					}
					else if (this->grid[i+k][j+l] == 'W') {
						this->wolfCount++;
					}
					else if (this->grid[i+k][j+l] == 'F') {
						this->farmerCount++;
					}
					else if (this->grid[i+k][j+l] == '.') {
						this->emptyCount++;
					}
				}
			}
		}
	}
}

// prints the current grid
void Game::printGrid() {

	for (int i=0; i<this->sizex; i++) {
		std::cout << "" << std::endl;
		for (int j=0; j<this->sizey; j++) {
			std::cout << this->grid[i][j];
		}
	}
}