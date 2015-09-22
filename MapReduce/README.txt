README

Project: MapReduce

Description:
	Program uses a map to extract words from text files which
		are used as the map keys, and number of occurrences, which
		are used as the values.
	WordCount counts number of individual words, sentenceStats counts maximum,
		minimum, and average sentence lengths, and phrases counts the frequency 
		of two-word phrases in the input.

Files:
	makefile
	wordCount.hpp
	sentenceStats.hpp
	phrases.hpp
	ioutils.hpp
	mr.hpp
	
	wordCount.cpp
	sentenceStats.cpp
	phrases.cpp
	ioutils.cpp
	test-wordCount.cpp
	test-sentenceStats.cpp
	test-phrases.cpp
	
	input.txt
	inputs/ (contains text files used as input)

Execution:
	Execute Makefile using the command "make" followed by 
		"./test-(wordCount, sentenceStats, or phrases) input.txt".
	