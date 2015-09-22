CXX =g++
CXXFLAGS = -g -std=c++11

all: test-game

%o : %.cpp game.hpp

GOL_OBJECTS = test-game.o game.o
test-game: $(GOL_OBJECTS)
	$(CXX) -o $@ $(GOL_OBJECTS) $(CXXFLAGS)
	
clean:
	$(RM) *.o test-game