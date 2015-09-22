/*	
	Steven Rappe
	main.cpp
	
	Main method, calls all maze methods and displays output.
*/

#include <iostream>
#include <fstream>
#include "maze.hpp"
#include "utils.hpp"

int main(int argc, const char *argv[]) {

	//checks for the input file name
	if( argc != 2 )
	{
		std::cerr << "Error: no input file name" << std::endl;
		std::cerr << "Usage: ./" << argv[0] << " someinput.txt" << std::endl;
		return 1;
	}
	
	// open the input file
	std::ifstream mazeInputFile ( argv[1] );
	int numberOfMazes = 0;
	// read the number of mazes
	mazeInputFile >> numberOfMazes; 

	for (int currentMaze = 0; currentMaze < numberOfMazes; currentMaze++ ) {
		int mazeSize = 0;
		// read the maze size from the input file
		mazeInputFile >> mazeSize;

		std::cout << "size = " << mazeSize << std::endl;
		Utils mazeUtils(mazeSize, mazeInputFile);

		if (mazeSize < 10 || mazeSize > 30) {
			std::cerr << "Error: invalid maze size " << mazeSize << " read from " << argv[1] << std::endl;
			std::cerr << "     Maze sizes must be between 10 and 30" << std::endl;
			return 1;
		}

		// Create a new maze object of the given size
		Maze maze(mazeSize);

		// Initialize the maze
		maze.readFromFile(mazeInputFile);

		int row, col;

		// Solve the maze
		do {

			// Get current location in the maze
			maze.getCurrentPosition(row, col);

			// Print the current maze string
			mazeUtils.print(row, col);
			std::cout << "Press ENTER to continue..." << std::endl;
			std::cin.get();

			// Advance one step in the maze
			maze.step();

		} while ( ! maze.atExit() );

		maze.getCurrentPosition(row, col);
		mazeUtils.print(row, col);
		std::cout << "YAY! Maze solved!" << std::endl;
        std::cout << "Press ENTER to continue..." << std::endl;
		std::cin.get();    

		mazeUtils.reset();
	} 
}

