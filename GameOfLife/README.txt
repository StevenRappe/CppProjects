README

Project: GameOfLife

Description:
	Implements Conway's the game of life, which is a self driven game
		played on a grid that only needs to be started, then plays itself out.
	Rules:
		Any cell can be labelled as an empty cell (.), a sheep (s), a wolf (w),
			or a farmer (f).
		At each step:
			Sheep and wolf cells die when surrounded by 3 or more other sheep or
				other wolves, respectively.
			If sheep cell contains one or more wolf neighbours it dies. If an empty 
				cell has exactly two neighbours of one species, they reproduce and
				fill cell.
			Wolves can also die if they are surrounded by only wolf and empty cells
				(starvation), or if they contain a farmer neighbour.
			Finally, a farmer moves to a random adjacent empty cell if there is one.

Files:
	Makefile
	game.hpp
	
	game.cpp
	test-game.cpp

Execution:
	Execute Makefile the the command "make" followed by "./test-game".
	The program will ask the user to enter two grid dimensions followed
		by the number of steps the game should proceed.
	The game will then play itself out according to the specified rules.

