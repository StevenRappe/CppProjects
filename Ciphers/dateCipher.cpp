/*
	Steven Rappe
	dateCipher.cpp
	
	Date cipher class. Has encrypt and decrypt methods.
	Uses set date of 12/25/92.
*/

#include "cipher.hpp"
#include "dateCipher.hpp"

DateCipher::DateCipher() : Cipher(), date("122592") {

}

DateCipher::~DateCipher() {

}

// encrypt method
std::string
DateCipher::encrypt( std::string &inputText ) {

	std::string text = inputText;
	std::string::size_type len = text.length();
	std::string::size_type len2 = this->date.length();
	
	// int to hold location in date string.
	int k = 0;
	int convert = 0;
	
	for (int i = 0; i < len; i++) {
		convert = this->date[k] - '0';
		
		if (text[i] >= 97 && text[i] <= 123) {
			text[i] = (text[i] + convert)%124;
			if (text[i] < 97) {
				text[i] = text[i] + 97;
			}
			if (text[i] == 123) {
				text[i] = 32;
			}
		}
		// handles upper case letters
		else if (text[i] >= 65 && text[i] <= 90) {
			text[i] = (text[i] + convert)%91;
			if (text[i] < 65) {
				text[i] = text[i] + 65;
			}
		}
		// handles space character
		else if (text[i] == 32) {
			if (convert == 0) {
				text[i] = 32;
			}
			else {
				text[i] = 96 + convert;
			}
		}
		else {
			text[i] = text[i];
		}
		// increment k, reset to 0 if it reaches date length.
		k ++;
		if (k >= len2) {
			k = 0;
		}
	}
	return text;	
}

// decrypt method
std::string
DateCipher::decrypt( std::string &inputText ) {

	std::string text = inputText;
	std::string::size_type len = text.length();
	std::string::size_type len2 = this->date.length();
	
	// int to hold location in date string.
	int k = 0;
	int convert = 0;
	
	for (int i = 0; i < len; i++) {
		convert = (this->date[k] - '0');
	
		// handles lower case letters
		if (text[i] >= 97 && text[i] <= 123) {
			text[i] = text[i] - convert;
			if (text[i] < 97) {
				text[i] = text[i] + 27;
			}
			if (text[i] == 123) {
				text[i] = 32;
			}
		}
		// handles upper case letters
		else if (text[i] >= 65 && text[i] <= 90) {
			text[i] = text[i] - convert;
			if (text[i] < 65) {
				text[i] = text[i] + 26;
			}
		}
		// handles space character
		else if (text[i] == 32) {
			text[i] = 123 - convert;		
		}
		else {
			text[i] = text[i];
		}
		// increment k, reset to 0 if it reaches date length.
		k ++;
		if (k >= len2) {
			k = 0;
		}
	}
	return text;
}
