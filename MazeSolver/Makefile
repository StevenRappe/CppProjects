CXX = g++ -std=c++11 -Wall -g

%.o : %.c 
	$(CXX) -c $< 

main: utils.o main.o maze.o
	$(CXX) -o $@ main.o utils.o maze.o

clean:
	$(RM) main *.o