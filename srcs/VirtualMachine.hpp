#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "IOperand.hpp"

class VirtualMachine {
private:
	std::vector<const IOperand*> _vect;
public:
	VirtualMachine();
	~VirtualMachine();

	int push(IOperand::eOperandType type, const std::string& line);
	int pop();
	int dump();
	int asserts(IOperand::eOperandType type, const std::string& line);
	int add();
	int sub();
	int mul();
	int div();
	int mod();
	int print();
	int exit();

	std::vector<const IOperand*> getVect() const;
};
