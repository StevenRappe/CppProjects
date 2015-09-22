/*
 	Steven Rappe
 	test-phrases.cpp
	
	Runs the phrases program, which counts the frequency
	of two-word phrases.
 */

#include <iostream>
#include <string>
#include <future> 
#include <thread>
#include <chrono>

#include "ioutils.hpp"
#include "mr.hpp"
#include "phrases.hpp"


int main(int argc, const char *argv[]) {
	using namespace std;

	mr::Phrases phrases;
	std::map<string,int> final;

	IOUtils io;
	io.openStream(argc,argv);
	vector<string> fileNames = io.split(io.readFromStream(),'\n');
	io.closeStream();

	auto start = std::chrono::steady_clock::now(); // start timer

#ifndef PARALLEL_MR
	// Invoke the Map Reduce runtime
	mr::run(phrases, fileNames, final);
#else	
	
	mr::prun<string,int>(phrases, fileNames, final, 10, 4);
#endif

	auto end = std::chrono::steady_clock::now();

	// Print the final results
	for (auto it = final.begin(); it != final.end(); it++ )
		cout << it->first << ": " << it->second << endl;

	auto diff = end - start;
	cout << "MapReduce time: " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << endl;
	return 0;
}
