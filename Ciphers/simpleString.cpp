
#include "simpleString.hpp"

SimpleString::SimpleString() : str(NULL), length(0) {
	cout << "Empty constructor. " << "str = " << this->str << " and length = " << this->length << endl;
}

SimpleString::SimpleString(char * string, int length) {
	this->str = new string(string);
	cout << "Parameter constructor" << "str = " << this->str << " and length = " << this->length << endl;
}

SimpleString::~SimpleString() {
	delete this->str;
}

string SimpleString::getString() {
	return string (const char * this->str);
}
