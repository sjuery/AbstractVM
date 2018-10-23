#include "IOperand.hpp"
#include "Polymorphed.hpp"

IOperand::IOperand()
{

}

IOperand::~IOperand()
{

}

IOperand * IOperand::createOperand( eOperandType type, std::string const & value )
{
	switch(type)
	{
		case 0:
			return(createInt8(value));
		case 1:
			return(createInt16(value));
		case 2:
			return(createInt32(value));
		case 3:
			return(createFloat(value));
		case 4:
			return(createDouble(value));
	}
}

IOperand * IOperand::createInt8( std::string const & value )
{
	try
	{
		if(stoi(value) >= -128 && stoi(value) <= 127)
			return new Polymorphed<int8_t>(stoi(value));
		throw InvalidNumber();

	}
	catch(std::exception& e)
	{
		std::cout << value << e.what() << std::endl;
	}
	return NULL;
}

IOperand * IOperand::createInt16( std::string const & value )
{
	try
	{
		if(stoi(value) >= -32768 && stoi(value) <= 32768)
			return new Polymorphed<int16_t>(stoi(value));
		throw InvalidNumber();

	}
	catch(std::exception& e)
	{
		std::cout << value << e.what() << std::endl;
	}
	return NULL;
}

IOperand * IOperand::createInt32( std::string const & value )
{
	try
	{
		if(stoi(value) >= -2147483648 && stoi(value) <= 2147483647)
			return new Polymorphed<int32_t>(stoi(value));
		throw InvalidNumber();
	}
	catch(std::exception& e)
	{
		std::cout << value << e.what() << std::endl;
	}
	return NULL;
}

IOperand * IOperand::createFloat( std::string const & value )
{
	try
	{
		if(stof(value) >= std::numeric_limits<float>::min() && stof(value) <= std::numeric_limits<float>::max())
			return new Polymorphed<float>(stof(value));
		throw InvalidNumber();
	}
	catch(std::exception& e)
	{
		std::cout << value << e.what() << std::endl;
	}
	return NULL;
}

IOperand * IOperand::createDouble( std::string const & value )
{
	try
	{
		if(stod(value) >= std::numeric_limits<double>::min() && stod(value) <= std::numeric_limits<double>::max())
			return new Polymorphed<double>(stod(value));
		throw InvalidNumber();
	}
	catch(std::exception& e)
	{
		std::cout << value << e.what() << std::endl;
	}
	return NULL;
}
