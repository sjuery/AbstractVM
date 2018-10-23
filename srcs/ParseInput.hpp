#pragma once
#include <iostream>
#include <vector>
#include <cmath>

class ParseInput {
private:
	std::string _cmds[11] = { "push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit" };
	std::string _types[5] = { "int8(", "int16(", "int32(", "float(", "double(" };
	std::vector<std::string> _input;
public:
	ParseInput();
	~ParseInput();
	char isvalidcomment(std::string);
	int stringIsNumbers(std::string);
	void cleanInput(std::string, int);
	void cleanfurther(std::string, int);
	std::vector<std::string> getCleanInput();

	struct InvalidInstruction : public std::exception {
		const char * what () const throw () {
			return "Invalid instruction on line ";
		}
	};
};
