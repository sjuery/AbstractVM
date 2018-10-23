#include "VirtualMachine.hpp"
#include "ParseInput.hpp"
#include <iostream>
#include <functional>


void extractVector(std::vector<std::string> vect)
{
	VirtualMachine *vm = new VirtualMachine();

	for(const std::string op : vect) {
		if(op.substr(0,2) == "00")
			vm->push(static_cast<IOperand::eOperandType>(std::stoi(op.substr(3,1))), op.substr(5));
		else if(op.substr(0,2) == "01")
			vm->pop();
		else if(op.substr(0,2) == "02")
			vm->dump();
		else if(op.substr(0,2) == "03")
			vm->asserts(static_cast<IOperand::eOperandType>(std::stoi(op.substr(3,1))), op.substr(5));
		else if(op.substr(0,2) == "04")
			vm->add();
		else if(op.substr(0,2) == "05")
			vm->sub();
		else if(op.substr(0,2) == "06")
			vm->mul();
		else if(op.substr(0,2) == "07")
			vm->div();
		else if(op.substr(0,2) == "08")
			vm->mod();
		else if(op.substr(0,2) == "09")
			vm->print();
		else if(op.substr(0,2) == "10")
			vm->exit();
	}
}

int main(int argc, char const *argv[]) {
	int linecnt = 1;
	std::string line;
	ParseInput pi;

	if(argc == 1)
	{
		while(std::getline (std::cin, line) && line != ";;")
			pi.cleanInput(line, linecnt++);
	}
	else if(argc == 2)
	{
		std::ifstream file(argv[1]);

		if(!file.good())
			perror("Error");
		while(std::getline (file, line))
			pi.cleanInput(line, linecnt++);
	}
	else
		std::cout << "Usage: ./avm\nUsage: ./avm [File]" << std::endl;
	extractVector(pi.getCleanInput());
	return 0;
}
