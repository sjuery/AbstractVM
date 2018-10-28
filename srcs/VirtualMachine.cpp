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

//Gets the type of a number as a string
std::string VirtualMachine::getType(IOperand::eOperandType type)
{
	switch(type)
	{
		case 0: return ("int8 ");
			break;
		case 1: return ("int16 ");
			break;
		case 2: return ("int32 ");
			break;
		case 3: return ("float ");
			break;
		case 4: return ("double ");
			break;
	}
	return("NULL");
}

//Push adds a value to the top
void VirtualMachine::push(IOperand::eOperandType type, const std::string& line)
{
	_vect.push_back(IOperand::createOperand(type, line));
}

//Pop removes the top value. If there is no value, throw an exception.
void VirtualMachine::pop()
{
	if(_vect.size() > 0)
		_vect.erase(_vect.begin()+_vect.size()-1);
	else
		throw StackTooSmall("pop");
}

//Dump displays each value from most recent to older. Seperated by new line.
void VirtualMachine::dump()
{
	if(_vect.size() > 0)
	{
		std::cout << "\033[1;36m" << "Dump:" << "\033[0m" << std::endl;
		reverse(_vect.begin(), _vect.end());
		for(const IOperand *op : _vect) {
			std::cout << "\033[1;36m" << getType(op->getType()) << op->toString() << "\033[0m" << std::endl;
		}
		reverse(_vect.begin(), _vect.end());
	}
	else
		throw StackTooSmall("dump");
}

//Assert X Makes sure the newest value is equal to X, otherwise throw an exception.
void VirtualMachine::assert(IOperand::eOperandType type, const std::string& line)
{
	if(_vect.size() > 0)
	{
		if(type == _vect[_vect.size()-1]->getType())
			if(stod(line) == stod(_vect[_vect.size()-1]->toString()))
				return ;
			else
				throw ValuesNotEqual(line, _vect[_vect.size()-1]->toString());
		else
			throw TypesNotEqual();
	}
	else
		throw StackTooSmall("assert");
}

//Add Adds the top two values into one. Throws an exception if there are less then 2 values.
void VirtualMachine::add()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-2] + *_vect[_vect.size()-1]);
		std::cout << "\033[1;33m" << _vect[_vect.size()-3]->toString() << " + " << _vect[_vect.size()-2]->toString() << " = " << _vect[_vect.size()-1]->toString() << "\033[0m" << std::endl;
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	else
		throw StackTooSmall("add");
}

//Sub Substracts the top two values into one. Throws an exception if there are less then 2 values.
void VirtualMachine::sub()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-2] - *_vect[_vect.size()-1]);
		std::cout << "\033[1;33m" << _vect[_vect.size()-3]->toString() << " - " << _vect[_vect.size()-2]->toString() << " = " << _vect[_vect.size()-1]->toString() << "\033[0m" << std::endl;
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	else
		throw StackTooSmall("substract");
}

//Mul Multiplies the top two values into one. Throws an exception if there are less then 2 values.
void VirtualMachine::mul()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-2] * *_vect[_vect.size()-1]);
		std::cout << "\033[1;33m" << _vect[_vect.size()-3]->toString() << " * " << _vect[_vect.size()-2]->toString() << " = " << _vect[_vect.size()-1]->toString() << "\033[0m" << std::endl;
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	else
		throw StackTooSmall("multiply");
}

//Div divides the top two values into one. Throws an exception if there are less then 2 values or if the divisor is equal to 0.
void VirtualMachine::div()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-2] / *_vect[_vect.size()-1]);
		std::cout << "\033[1;33m" << _vect[_vect.size()-3]->toString() << " / " << _vect[_vect.size()-2]->toString() << " = " << _vect[_vect.size()-1]->toString() << "\033[0m" << std::endl;
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	else
		throw StackTooSmall("divide");
}

//Mod calculates the modulo of the top two values into one. Throws an exception if there are less then 2 values or if the divisor is equal to 0.
void VirtualMachine::mod()
{
	if(_vect.size() >= 2)
	{
		_vect.push_back(*_vect[_vect.size()-2] % *_vect[_vect.size()-1]);
		std::cout << "\033[1;33m" << _vect[_vect.size()-3]->toString() << " % " << _vect[_vect.size()-2]->toString() << " = " << _vect[_vect.size()-1]->toString() << "\033[0m" << std::endl;
		_vect.erase(_vect.begin()+_vect.size()-2);
		_vect.erase(_vect.begin()+_vect.size()-2);
	}
	else
		throw StackTooSmall("modulo");
}

//dupe duplicated the top x values into a different type. If there are less than x values, throws an exception
void VirtualMachine::dupe(IOperand::eOperandType type, const std::string& line)
{
	size_t cnt = stod(line);
	if(_vect.size() >= cnt)
	{
		for(size_t i = 0; i < cnt; i++)
			_vect.push_back(IOperand::createOperand(type, _vect[_vect.size() - cnt + i]->toString()));
	}
	else
		throw StackTooSmall("dupe");
}

//Print Asserts that the value at the top of the stack is an 8-bit integer and displays it as an ASCII value. otherwise throw an exception.
void VirtualMachine::print()
{
	if(_vect.size() >= 1)
	{
		if(_vect[_vect.size()-1]->getType() == IOperand::eOperandType::int8)
			if(stod(_vect[_vect.size()-1]->toString()) >= 33 && stod(_vect[_vect.size()-1]->toString()) <= 126)
				std::cout << "\033[1;36m" << (int8_t)std::stoi(_vect[_vect.size()-1]->toString())  << "\033[0m" << std::endl;
			else
				throw NotPrintable(_vect[_vect.size()-1]->toString());
		else
			throw TypesNotEqual();
	}
	else
		throw StackTooSmall("print");
}

//***************************
//* Virtual Machine Getters *
//***************************

std::vector<const IOperand*> VirtualMachine::getVect() const
{
	return(_vect);
}
