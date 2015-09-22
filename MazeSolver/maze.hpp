/*	Steven Rappe
	maze.hpp
*/

#ifndef MAZE_HPP_
#define MAZE_HPP_

#include <fstream>

class Maze
{
public:
	Maze(int size);
	~Maze() {}

	enum Direction { DOWN=0, RIGHT=1, UP=2, LEFT=3 };

	// read maze from file, find starting location
	void readFromFile(std::ifstream &f);

	// make a single step advancing toward the exit
	void step();

	// return true if the maze exit has been reached, false otherwise
	bool atExit();

	// set row and col to current position of 'x'
	void getCurrentPosition(int &row, int &col);

	// You can add more functions if you like
private:
	char maze[30][30] = { /**/ };
	int facing = UP;
	int size;
	int x, y;
};


#endif /* MAZE_HPP_ */
