#include "VirtualMachine.hpp"
#include <iostream>
#include <functional>

struct InvalidInstruction : public std::exception {
	const char * what () const throw () {
		return "Invalid instruction on line ";
	}
};

void parseLine(std::string line, VirtualMachine vm, int linecnt)
{
	std::string cmds[13] = { "push", "pop", "dump", "assert", "add", "sub",
							"mul", "div", "mod", "print", "exit", ";", ";;" };
	std::function<int(VirtualMachine&, void*)> fnctn[13] = { &VirtualMachine::push,
		&VirtualMachine::pop, &VirtualMachine::dump, &VirtualMachine::asserts,
		&VirtualMachine::add, &VirtualMachine::sub, &VirtualMachine::mul,
		&VirtualMachine::div, &VirtualMachine::mod, &VirtualMachine::print,
		&VirtualMachine::exit, &VirtualMachine::pop, &VirtualMachine::pop };

	try
	{
		if(line.empty())
			return ;
		for(int i = 0; i < 13; i++)
		{
			if(line.substr(0,cmds[i].length()) == cmds[i])
			{
				if(!fnctn[i](vm, static_cast<void*>(&line)))
					throw InvalidInstruction();
				return ;
			}
		}
		throw InvalidInstruction();
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << linecnt << std::endl;
	}
}

int main(int argc, char const *argv[]) {
	int linecnt = 1;
	std::string line;
	VirtualMachine vm;

	if(argc == 1)
	{
		while(std::getline (std::cin, line))
			parseLine(line, vm, linecnt++);
	}
	else if(argc == 2)
	{
		std::ifstream file(argv[1]);

		if(!file.good())
			perror("Error");
		while(std::getline (file, line))
			parseLine(line, vm, linecnt++);
	}
	else
		std::cout << "Usage: ./avm\nUsage: ./avm [File]" << std::endl;
	return 0;
}
