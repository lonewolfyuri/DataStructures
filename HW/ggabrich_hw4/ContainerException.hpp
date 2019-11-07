// George Gabricht
//
// ggabrich - 56735102


#ifndef CONTAINEREXCEPTION_HPP

#define CONTAINEREXCEPTION_HPP

#include <exception>
using namespace std;

class ContainerOverflow : public exception {
private:
	char * errmsg;
public:
	ContainerOverflow(char * err_msg)
	: errmsg(err_msg)
	{}

	char * error() {
		return errmsg;
	}

};

class ContainerUnderflow : public exception {
private:
	char * errmsg;
public:
	ContainerUnderflow(char * err_msg) 
	: errmsg(err_msg)
	{}

	char * error() {
		return errmsg;
	}

};

#endif // CONTAINEREXCEPTION_HPP
