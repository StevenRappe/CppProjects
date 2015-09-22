/*	
	Steven Rappe
	test-date.cpp
	
	Runs date cipher, calls encrypt, decrypt methods and
	displays output.
*/

#include <iostream>
#include <fstream>

#include "ioutils.hpp"
#include "cipher.hpp"
#include "dateCipher.hpp"

int main(int argc, const char *argv[]) {

	IOUtils io;
	io.openStream(argc,argv);
	std::string input, encrypted, decrypted;
	input = io.readFromStream();
	std::cout << "Original text:" << std::endl << input;

	DateCipher date;
	encrypted = date.encrypt(input);
	std::cout << "Encrypted text:" << std::endl << encrypted;

	decrypted = date.decrypt(encrypted);
	std::cout << "Decrypted text:" << std::endl << decrypted;

	if (decrypted == input) std::cout << "Decrypted text matches input!" << std::endl;
	else {
		std::cout << "Oops! Decrypted text doesn't match input!" << std::endl;
		return 1;  
	}

	return 0;
}
