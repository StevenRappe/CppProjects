/*
 *	Steven Rappe
 *	phrases.cpp
 *
 *	Counts the occurrences of all two-word phrases 
 *	found in the input.
 *
 */


#include <sstream>
#include <fstream>
#include <map>
#include <algorithm>

#include "mr.hpp"
#include "ioutils.hpp"
#include "phrases.hpp"


namespace mr {

// Maps two words per phrase and appends the phrases to output.
void
Phrases::MRmap(const std::map<std::string,std::string> &input,
				std::multimap<std::string,int> &out_values) {
	IOUtils io;
	
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);

		std::istringstream iss(inputString);
		std::string word;
		
		// Get first word.
		iss >> word;
		
		// put two words in a phrase.
		do {
			std::string phrase;
			
			// append previous word.
			phrase.append(word+" ");
			iss >> word;
			// append new word.
			phrase.append(word);
			
			// If end of file, do not insert the final phrase.
			if (iss.peek() == EOF) {
				break;
			}
			
			// Each phrase gets assigned a count of 1
			out_values.insert(std::pair<std::string,int>(phrase,1));
		} while (iss);
	}
}

// Same reduce function as wordCount.cpp
void
Phrases::MRreduce(const std::multimap<std::string,int> &intermediate_values,
					std::map<std::string,int> &out_values) {

	std::for_each(intermediate_values.begin(), intermediate_values.end(),
			
			[&](std::pair<std::string,int> mapElement)->void
			{
				out_values[mapElement.first] += 1;
			}); 
}

};
