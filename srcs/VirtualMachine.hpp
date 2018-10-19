#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "IOperand.hpp"

class VirtualMachine {
	std::vector<int> _vect;
public:
	VirtualMachine();
	~VirtualMachine();

	int push(void *);
	int pop(void *);
	int dump(void *);
	int asserts(void *);
	int add(void *);
	int sub(void *);
	int mul(void *);
	int div(void *);
	int mod(void *);
	int print(void *);
	int exit(void *);

	// struct InvalidCommand : public std::exception {
	// 	const char * what () const throw () {
	// 		return "Invalid command given";
	// 	}
	// };

	std::vector<int> getVect() const;
};
