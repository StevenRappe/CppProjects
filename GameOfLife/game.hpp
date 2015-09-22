/*
 *	Steven Rappe
 *	game.hpp
 */

#ifndef GAME_HPP_
#define GAME_HPP_

#include <vector>
#include <iostream>


class Game {
	public:
		Game(int sizex, int sizey);
		~Game() {}
		
		// methods: 
		
		void initializeGrid();
		
		void checkSurroundings(int i, int j);
		
		void takeTurn();
		
		void printGrid();
		
	private:
		std::vector<std::vector<char>> grid;
		int sizex;
		int sizey;
		int numTurns;
		int sheepCount, wolfCount, farmerCount, emptyCount;
};	
	#endif /* GAME_HPP_ */
	