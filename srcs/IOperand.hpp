#pragma once
#include <iostream>

class IOperand {
private:
	static IOperand * createInt8( std::string const & value );
	static IOperand * createInt16( std::string const & value );
	static IOperand * createInt32( std::string const & value );
	static IOperand * createFloat( std::string const & value );
	static IOperand * createDouble( std::string const & value );
public:
	IOperand();
	enum eOperandType { int8, int16, int32, intf, intd };
	virtual ~IOperand( void );

	static IOperand * createOperand( eOperandType type, std::string const & value );

	struct InvalidNumber : public std::exception {
		const char * what () const throw () {
			return " did not match its type of ";
		}
	};
};
