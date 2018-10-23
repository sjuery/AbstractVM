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

//Push adds a value to the top
int VirtualMachine::push(IOperand::eOperandType type, const std::string& line)
{
	_vect.push_back(IOperand::createOperand(type, line));
	return 1;
}

//Pop removes the top value. If there is no value, throw an exception.
int VirtualMachine::pop()
{
	if(_vect.size() == 0)
		return 0;
	_vect.erase(_vect.begin()+_vect.size()-1);
	return 1;
}

//Dump displays each value from most recent to older. Seperated by new line.
int VirtualMachine::dump()
{
	if(_vect.size() == 0)
		std::cout << "Empty" << std::endl;
	for(const IOperand *op : _vect) {
		std::cout << op->toString() << std::endl;
	}
	return 1;
}

//Assert X Makes sure the newest value is equal to X, otherwise throw an exception.
int VirtualMachine::asserts(IOperand::eOperandType type, const std::string& line)
{
	(void)line;
	(void)type;
	// if(_vect.size() != 0)

	return 1;
}

//Add Adds the top two values into one. Throws an exception if there are less then 2 values.
int VirtualMachine::add()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-1] + *_vect[_vect.size()-2]);
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	return 1;
}

//Sub Substracts the top two values into one. Throws an exception if there are less then 2 values.
int VirtualMachine::sub()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-1] - *_vect[_vect.size()-2]);
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	return 1;
}

//Mul Multiplies the top two values into one. Throws an exception if there are less then 2 values.
int VirtualMachine::mul()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-1] * *_vect[_vect.size()-2]);
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	return 1;
}

//Div divides the top two values into one. Throws an exception if there are less then 2 values or if the divisor is equal to 0.
int VirtualMachine::div()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-1] / *_vect[_vect.size()-2]);
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	return 1;
}

//Mod calculates the modulo of the top two values into one. Throws an exception if there are less then 2 values or if the divisor is equal to 0.
int VirtualMachine::mod()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-1] % *_vect[_vect.size()-2]);
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	return 1;
}

//Print Asserts that the value at the top of the stack is an 8-bit integer and displays it as an ASCII value. otherwise throw an exception.
int VirtualMachine::print()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-1] + *_vect[_vect.size()-2]);
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	return 1;
}

//Exits the program. If this instruction is not called, throw an exception.
int VirtualMachine::exit()
{
	return 2;
}

//***************************
//* Virtual Machine Getters *
//***************************

std::vector<const IOperand*> VirtualMachine::getVect() const
{
	return(_vect);
}
