#include "VirtualMachine.hpp"

//*********************************
//* Virtual Machine Instanciation *
//*********************************

VirtualMachine::VirtualMachine()
{
	//Do Nothing
}

VirtualMachine::~VirtualMachine()
{
	//Destroy Element
}

//*****************************
//* Virtual Machine Functions *
//*****************************

int stringIsNumbers(std::string str)
{
	int cnt = 0;

	if(str[cnt] == '-')
		cnt++;
	for(int i = cnt; i < str.length(); i++)
	{
		if((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			continue;
		else
			return 0;
	}
	return 1;
}

int getToEndOfLine(std::string str)
{
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ';')
			return 1;
		else if(str[i] != ' ')
			return 0;
	}
	return 1;
}

//Push adds a value to the top
int VirtualMachine::push(void *vd)
{
	std::string *line = static_cast<std::string*>(vd);

	if(stringIsNumbers(line->substr(line->find('(') + 1, line->find(')') - line->find('(') - 1).c_str()) && getToEndOfLine(line->substr(line->find(')') + 1)))
	{
		IOperand *operand;
		if(line->substr(5, line->find('(') - 5) == "int8")
				operand->createOperand(IOperand::int8, line->substr(line->find('(') + 1, line->find(')') - line->find('(') - 1).c_str());
		else if(line->substr(5, line->find('(') - 5) == "int16")
				operand->createOperand(IOperand::int16, line->substr(line->find('(') + 1, line->find(')') - line->find('(') - 1).c_str());
		else if(line->substr(5, line->find('(') - 5) == "int32")
				operand->createOperand(IOperand::int32, line->substr(line->find('(') + 1, line->find(')') - line->find('(') - 1).c_str());
		else if(line->substr(5, line->find('(') - 5) == "float")
				operand->createOperand(IOperand::intf, line->substr(line->find('(') + 1, line->find(')') - line->find('(') - 1).c_str());
		else if(line->substr(5, line->find('(') - 5) == "double")
				operand->createOperand(IOperand::intd, line->substr(line->find('(') + 1, line->find(')') - line->find('(') - 1).c_str());
		else
			return 0;
	}
	else
		return 0;
	return 1;
}

//Pop removes the top value. If there is no value, throw an exception.
int VirtualMachine::pop(void *vd)
{
	std::cout << "pop" << std::endl;
	return 1;
}

//Dump displays each value from most recent to older. Seperated by new line.
int VirtualMachine::dump(void *vd)
{
	std::cout << "dump" << std::endl;
	return 1;
}

//Assert X Makes sure the newest value is equal to X, otherwise throw an exception.
int VirtualMachine::asserts(void *vd)
{
	std::cout << "assert" << std::endl;
	return 1;
}

//Add Adds the top two values into one. Throws an exception if there are less then 2 values.
int VirtualMachine::add(void *vd)
{
	std::cout << "add" << std::endl;
	return 1;
}

//Sub Substracts the top two values into one. Throws an exception if there are less then 2 values.
int VirtualMachine::sub(void *vd)
{
	std::cout << "sub" << std::endl;
	return 1;
}

//Mul Multiplies the top two values into one. Throws an exception if there are less then 2 values.
int VirtualMachine::mul(void *vd)
{
	std::cout << "mul" << std::endl;
	return 1;
}

//Div divides the top two values into one. Throws an exception if there are less then 2 values or if the divisor is equal to 0.
int VirtualMachine::div(void *vd)
{
	std::cout << "div" << std::endl;
	return 1;
}

//Mod calculates the modulo of the top two values into one. Throws an exception if there are less then 2 values or if the divisor is equal to 0.
int VirtualMachine::mod(void *vd)
{
	std::cout << "mod" << std::endl;
	return 1;
}

//Print Asserts that the value at the top of the stack is an 8-bit integer and displays it as an ASCII value. otherwise throw an exception.
int VirtualMachine::print(void *vd)
{
	std::cout << "print" << std::endl;
	return 1;
}

//Exits the program. If this instruction is not called, throw an exception.
int VirtualMachine::exit(void *vd)
{
	std::cout << "exit" << std::endl;
	return 1;
}

//***************************
//* Virtual Machine Getters *
//***************************

std::vector<int> VirtualMachine::getVect() const
{
	return(_vect);
}
