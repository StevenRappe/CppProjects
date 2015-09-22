/*	
	Steven Rappe
	maze.cpp
	
	Creates the Maze class and sets initial position. Uses step
	method to move, atExit method to check if the maze is complete,
	and getCurrentPosition to locate the user's position after each
	step.
*/

#include "maze.hpp"
#include <iostream>
#include <fstream>

Maze::Maze(int size) : size(size) {

}

// Reads input into a maze
void Maze::readFromFile(std::ifstream &f) {
	
	int i, j;
    for (i = 0; i < this->size; i++) {
		std::string line;
		f >> line;
        for (j = 0; j < this->size; j++) {
            (this->maze[j][i]) = line[j];
			if (line[j] == 'x') {
				this->x = i;
				this->y = j;
			}
		}
    }
	// Face correct direction at the start
	if (this->y == (size-1)) {
		this->facing = LEFT;
	}
	else if (this->x == 0) {
		this->facing = DOWN;
	}
	else if (this->x == (size-1)) {
		this->facing = UP;
	}
	else if (this->y == 0) {
		this->facing = RIGHT;
	}
}

void Maze::step() {
	// If facing up
	if (this->facing == UP) {
		if ((this->maze[y+1][x] == '@')&&(this->maze[y][x-1] == '@')&&(this->maze[y-1][x] == '@')) { // if 3 walls
			x += 1;
			this->facing = DOWN;
			std::cout << "DOWN" << std::endl;
		}
		else if ((this->maze[y+1][x] == '@')&&(this->maze[y][x-1] == '@')) { // if 2 walls
			y -= 1;
			this->facing = LEFT;
			std::cout << "LEFT" << std::endl;
		}
		else if (this->maze[y+1][x] == '@') { // if 1 wall
			x -= 1;
			this->facing = UP;
			std::cout << "UP" << std::endl;
		}
		else {
			y += 1;
			this->facing = RIGHT;
			std::cout << "RIGHT" << std::endl;
		}
	}
	// If facing right
	else if (this->facing == RIGHT) {
		if ((this->maze[y][x+1] == '@')&&(this->maze[y+1][x] == '@')&&(this->maze[y][x-1] == '@')) { // if 3 walls
			y -= 1;
			this->facing = LEFT;
			std::cout << "LEFT" << std::endl;
		}
		else if ((this->maze[y][x+1] == '@')&&(this->maze[y+1][x] == '@')) { // if 2 walls
			x -= 1;
			this->facing = UP;
			std::cout << "UP" << std::endl;
		}
		else if (this->maze[y][x+1] == '@') { // if 1 wall
			y += 1;
			this->facing = RIGHT;
			std::cout << "RIGHT" << std::endl;
		}
		else {
			x += 1;
			this->facing = DOWN;
			std::cout << "DOWN" << std::endl;
		}
	}
	// If facing down
	else if (this->facing == DOWN) {
		if ((this->maze[y-1][x] == '@')&&(this->maze[y][x+1] == '@')&&(this->maze[y+1][x] == '@')) { // if 3 walls
			x -= 1;
			this->facing = UP;
			std::cout << "UP" << std::endl;
		}
		else if ((this->maze[y-1][x] == '@')&&(this->maze[y][x+1] == '@')) { // if 2 walls
			y += 1;
			this->facing = RIGHT;
			std::cout << "RIGHT" << std::endl;
		}
		else if (this->maze[y-1][x] == '@') { // if 1 wall
			x += 1;
			this->facing = DOWN;
			std::cout << "DOWN" << std::endl;
		}
		else {
			y -= 1;
			this->facing = LEFT;
			std::cout << "LEFT" << std::endl;
		}
	}
	// If facing left
	else {
		if ((this->maze[y][x-1] == '@')&&(this->maze[y-1][x] == '@')&&(this->maze[y][x+1] == '@')) { // if 3 walls
			y += 1;
			this->facing = RIGHT;
			std::cout << "RIGHT" << std::endl;
		}
		else if ((this->maze[y][x-1] == '@')&&(this->maze[y-1][x] == '@')) { // if 2 walls
			x += 1;
			this->facing = DOWN;
			std::cout << "DOWN" << std::endl;
		}
		else if (this->maze[y][x-1] == '@') { // if 1 wall
			y -= 1;
			this->facing = LEFT;
			std::cout << "LEFT" << std::endl;
		}
		else {
			x -= 1;
			this->facing = UP;
			std::cout << "UP" << std::endl;
		}
	}	
}
// exit condition for the maze
bool Maze::atExit() {

	if (x <= 0 || x >= ((this->size)-1) || y <= 0 || y >= ((this->size)-1)) {
		return true;
	}
	else {
		return false;
	}
}

// gets the current position
void Maze::getCurrentPosition(int &row, int &col) {
	row = x;
	col = y;
}