#include "IOperand.hpp"

IOperand::IOperand()
{

}

IOperand::~IOperand()
{

}

IOperand const * IOperand::createOperand( eOperandType type, std::string const & value ) const
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

IOperand const * IOperand::createInt8( std::string const & value ) const
{
	std::cout << "Created Int8 with value " << value << std::endl;
	return NULL;
}

IOperand const * IOperand::createInt16( std::string const & value ) const
{
	std::cout << "Created Int16 with value " << value << std::endl;
	return NULL;
}

IOperand const * IOperand::createInt32( std::string const & value ) const
{
	std::cout << "Created Int32 with value " << value << std::endl;
	return NULL;
}

IOperand const * IOperand::createFloat( std::string const & value ) const
{
	std::cout << "Created Float with value " << value << std::endl;
	return NULL;
}

IOperand const * IOperand::createDouble( std::string const & value ) const
{
	std::cout << "Created Double with value " << value << std::endl;
	return NULL;
}
