/*
 *	Steven Rappe
 *	sentenceStats.cpp
 *
 *	Computes the maximum length, the minimum length, 
 *	and the average length of all sentences found in
 *	the input.
 */


#include <sstream> 
#include <fstream>
#include <map>
#include <algorithm>

#include "mr.hpp"
#include "ioutils.hpp"
#include "sentenceStats.hpp"


namespace mr {

// Adds words to a sentence until sentence-ending punctuation is found.
// Then appends that sentence to output.
void
SentenceStats::MRmap(const std::map<std::string,std::string> &input,
				std::multimap<std::string,int> &out_values) {
	IOUtils io;
	
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);
		
		std::istringstream iss(inputString);
		do {
			int words = 0;
			std::string sentence;
			std::string word;
			
			do {
				iss >> word;
				sentence.append(word+" ");
				words += 1;
			} while (iss && (sentence.find(".") == std::string::npos) && (sentence.find("?") == std::string::npos) && (sentence.find("!") == std::string::npos));
			
			if (sentence != " ") {
				
				// Give each sentence a count of its length in words.
				out_values.insert(std::pair<std::string,int>(sentence,words));
			}
		} while (iss);
	}
}

// Finds the maximum, the minimum, and the average sentence length(in number of words).
void
SentenceStats::MRreduce(const std::multimap<std::string,int> &intermediate_values,
					std::map<std::string,int> &out_values) {
					
	using namespace std;
	// Declare values for final output.
	int max_length = 0;
	int min_length = 10000;
	float avg_length = 0;
	float total_length = 0;
	float total_sentences = 0;
	
	std::for_each(intermediate_values.begin(), intermediate_values.end(),
			
			[&](std::pair<std::string,int> mapElement)->void
			{
			
				// Assign max_length to largest found element.
				if (mapElement.second > max_length) {
					max_length = mapElement.second;
				}
				// Assign min_length to smallest found element.
				if (mapElement.second < min_length) {
					min_length = mapElement.second;
				}
				
				total_length += mapElement.second;
				total_sentences += 1;
				
			});
	// Compute average.
	avg_length = (total_length/total_sentences);
	
	// Print final output, maximum length, minimum length, and average length.
	cout << "Maximum Sentence Length: " << max_length << " words" << endl;
	cout << "Minimum Sentence Length: " << min_length << " words" << endl;
	cout << "Average Sentence Length: " << avg_length << " words" << endl;

}

};
					
					
					