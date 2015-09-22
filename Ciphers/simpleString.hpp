
#ifndef SIMPLESTRING_HPP_
#define SIMPLESTRING_HPP_

#include <string>
#include <iostream>

class SimpleString {
public:
	SimpleString();
	virtual ~SimpleString();
	virtual std::string getString();
private:
	char * str;
	int length;
};

#endif /* SIMPLESTRING_HPP_ */