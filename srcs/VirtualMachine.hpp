#pragma once
#include <stdint.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#undef assert
#include <stdio.h>
#include <stdlib.h>
#include "IOperand.hpp"

class VirtualMachine {
private:
	std::vector<const IOperand*> _vect;
public:
	VirtualMachine();
	~VirtualMachine();

	std::string getType(IOperand::eOperandType type);
	void push(IOperand::eOperandType type, const std::string& line);
	void pop();
	void dump();
	void assert(IOperand::eOperandType type, const std::string& line);
	void add();
	void sub();
	void mul();
	void div();
	void mod();
	void print();
	void dupe(IOperand::eOperandType type, const std::string& line);

	class StackTooSmall : public std::exception {
			std::string _message;
		public:
			StackTooSmall(std::string instruction) : _message("Stack too small to " + instruction) {}
			const char * what () const throw () {
				system("say Push more stuff please!");
				return _message.c_str();
			}
	};

	class TypesNotEqual : public std::exception {
			std::string _message;
		public:
			const char * what () const throw () {
				system("say Types are diffrent");
				return "Types do not match";
			}
	};

	class ValuesNotEqual : public std::exception {
			std::string _message;
		public:
			ValuesNotEqual(std::string assert, std::string stack) : _message("Top of stack ("  + stack + ") and Assert (" + assert + ") values are not equal.") {}
			const char * what () const throw () {
				system("say Do you think these are the same?");
				return _message.c_str();
			}
	};

	class NotPrintable : public std::exception {
			std::string _message;
		public:
			NotPrintable(std::string nbr) : _message(nbr + " is not printable") {}
			const char * what () const throw () {
				system("say Please use a printable number...");
				return _message.c_str();
			}
	};

	std::vector<const IOperand*> getVect() const;
};
