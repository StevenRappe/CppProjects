README

Project: MazeSolver

Description:
	Program reads an input file of a maze, and receives a start location.
	The program then solves the maze using the "right hand on the wall trick".
	Program outputs directions turned and maze progress.
	
Files:
	Makefile
	maze.hpp
	utils.hpp
	
	main.cpp
	maze.cpp
	utils.cpp
	
	input1.txt
	input2.txt

Execution:
	Execute Makefile with commands: "make", and then "./main input1.txt"
		or "./main input2.txt".
	The program will begin solving input mazes, and will require the
		user press enter to take each step in the maze. Holding down
		enter will rapidly progress through the mazes.
		
		input1.txt has one maze.
		input2.txt has multiple mazes.
	