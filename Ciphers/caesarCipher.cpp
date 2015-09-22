/*
	Steven Rappe
	caesarCipher.cpp
	
	Caesar cipher class. Has encrypt and decrypt methods.
	Has a set shift of 5.
*/

#include "cipher.hpp"
#include "caesarCipher.hpp"

CaesarCipher::CaesarCipher() : Cipher(), shift(5) {

}

CaesarCipher::~CaesarCipher() {

}

// encrypt method
std::string
CaesarCipher::encrypt( std::string &inputText ) {

	std::string text = inputText;
	std::string::size_type len = text.length();
	
	for (int i = 0; i < len; i++) {
		// handles lower case letters
		if (text[i] >= 97 && text[i] <= 123) {
			text[i] = (text[i] + this->shift)%124;
			if (text[i] < 97) {
				text[i] = text[i] + 97;
			}
			if (text[i] == 123) {
				text[i] = 32;
			}
		}
		// handles upper case letters
		else if (text[i] >= 65 && text[i] <= 90) {
			text[i] = (text[i] + this->shift)%91;
			if (text[i] < 65) {
				text[i] = text[i] + 65;
			}
		}
		// handles space character
		else if (text[i] == 32) {
			if (this->shift == 0) {
				text[i] = 32;
			}
			else {
				text[i] = 96 + this->shift;
			}
		}
		else {
			text[i] = text[i];
		}
	}
	return text;
}

// decrypt method
std::string
CaesarCipher::decrypt( std::string &inputText ) {

	std::string text = inputText;
	std::string::size_type len = text.length();
	
	for (int i = 0; i < len; i++) {
		// handles lower case letters
		if (text[i] >= 97 && text[i] <= 123) {
			text[i] = text[i] - this->shift;
			if (text[i] < 97) {
				text[i] = text[i] + 27;
			}
			if (text[i] == 123) {
				text[i] = 32;
			}
		}
		// handles upper case letters
		else if (text[i] >= 65 && text[i] <= 90) {
			text[i] = text[i] - this->shift;
			if (text[i] < 65) {
				text[i] = text[i] + 26;
			}
		}
		// handles space character
		else if (text[i] == 32) {
			text[i] = text[123] - this->shift;		
		}
		else {
			text[i] = text[i];
		}
	}
	return text;
}

