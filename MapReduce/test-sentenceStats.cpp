/*
 	Steven Rappe
 	test-sentenceStats.cpp
 
	Runs the sentenceStats program, which calculates the max, min, and
	average sentence length in the input.
 */

#include <iostream>
#include <string>
#include <future> 
#include <thread>
#include <chrono>

#include "ioutils.hpp"
#include "mr.hpp"
#include "sentenceStats.hpp"


int main(int argc, const char *argv[]) {
	using namespace std;

	mr::SentenceStats sentenceStats;
	std::map<string,int> final;

	IOUtils io;
	io.openStream(argc,argv);
	vector<string> fileNames = io.split(io.readFromStream(),'\n');
	io.closeStream();
	// start timer
	auto start = std::chrono::steady_clock::now();

#ifndef PARALLEL_MR
	// Invoke the Map Reduce runtime
	mr::run(sentenceStats, fileNames, final);
#else	
	
	mr::prun<string,int>(sentenceStats, fileNames, final, 10, 4);
#endif

	auto end = std::chrono::steady_clock::now();
		
	auto diff = end - start;
	
	cout << "MapReduce time: " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << endl;
	return 0;
}
