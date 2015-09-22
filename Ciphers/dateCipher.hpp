/*
	Steven Rappe
	dateCipher.hpp
*/

#ifndef DATECIPHER_HPP_
#define DATECIPHER_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
	DateCipher();
	virtual ~DateCipher();
	virtual std::string encrypt( std::string &text );
	virtual std::string decrypt( std::string &text );
private:
	std::string date;
};

#endif /* DATECIPHER_HPP_ */