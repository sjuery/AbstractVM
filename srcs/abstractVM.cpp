#include "VirtualMachine.hpp"
#include "LexInput.hpp"
#undef assert
#include <iostream>
#include <functional>

// enum function { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

void parseLexedInput(std::vector<std::string> vect)
{
	VirtualMachine *vm = new VirtualMachine();

	for(const std::string op : vect) {
		try
		{
			switch(stoi(op.substr(0,2)))
			{
				case 0: vm->push(static_cast<IOperand::eOperandType>(std::stoi(op.substr(3,1))), op.substr(5));
					break;
				case 1: vm->pop();
					break;
				case 2: vm->dump();
					break;
				case 3: vm->assert(static_cast<IOperand::eOperandType>(std::stoi(op.substr(3,1))), op.substr(5));
					break;
				case 4: vm->add();
					break;
				case 5: vm->sub();
					break;
				case 6: vm->mul();
					break;
				case 7: vm->div();
					break;
				case 8: vm->mod();
					break;
				case 9: vm->dupe(static_cast<IOperand::eOperandType>(std::stoi(op.substr(3,1))), op.substr(5));
					break;
				case 10: vm->print();
					break;
				case 11: delete vm;
					exit(1);
			}
		}
		catch(std::exception& e)
		{
			std::cout << "\033[1;31mRuntime Error: " << e.what() << "\033[0m" << std::endl;
			exit(1);
		}
	}
}

int main(int argc, char const *argv[]) {
	int linecnt = 1;
	int valid_exit = 0;
	std::string line;
	LexInput li;

	if(argc == 1)
	{
		std::cout << "\033[1;32m";
		while(std::getline (std::cin, line) && line != ";;")
			if(!valid_exit)
				valid_exit = li.cleanInput(line, linecnt++);
		std::cout << "\033[0m";
	}
	else if(argc == 2)
	{
		std::ifstream file(argv[1]);

		if(!file.good())
		{
			perror("\033[1;33mError");
			return 1;
		}
		while(std::getline (file, line))
			if(!valid_exit)
				valid_exit = li.cleanInput(line, linecnt++);
	}
	else
		std::cout << "\033[1;33mUsage: ./avm\nUsage: ./avm [File]\033[0m" << std::endl;
	if(valid_exit)
		parseLexedInput(li.getCleanInput());
	else
		std::cout << "\033[1;33mLexical Error: Did you forget to call the exit command?\033[0m" << std::endl;
	return 0;
}
