CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: test-caesar test-date

CAESAR_OBJECTS = test-caesar.o caesarCipher.o ioutils.o
test-caesar: $(CAESAR_OBJECTS)
	$(CXX) -o $@ $(CAESAR_OBJECTS)
	
DATE_OBJECTS = test-date.o dateCipher.o ioutils.o
test-date: $(DATE_OBJECTS)
	$(CXX) -o $@ $(DATE_OBJECTS)
	
clean: 
	$(RM) *.o test-caesar test-date
