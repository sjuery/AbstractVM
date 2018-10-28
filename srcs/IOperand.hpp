#pragma once
#include <iostream>
#include <cmath>

class IOperand {
private:
	static IOperand * createInt8( std::string const & value );
	static IOperand * createInt16( std::string const & value );
	static IOperand * createInt32( std::string const & value );
	static IOperand * createFloat( std::string const & value );
	static IOperand * createDouble( std::string const & value );
public:
	enum eOperandType { int8, int16, int32, intf, intd };
	virtual int getPrecision( void ) const = 0;
	virtual eOperandType getType( void ) const = 0;
	virtual IOperand const * operator+( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator-( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator*( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator/( IOperand const & rhs ) const = 0;
	virtual IOperand const * operator%( IOperand const & rhs ) const = 0;
	virtual std::string const & toString( void ) const = 0;
	IOperand();

	virtual ~IOperand( void );
	static IOperand * createOperand( eOperandType type, std::string const & value );

	class InvalidNumber : public std::exception {
			std::string _message;
		public:
			InvalidNumber(std::string type, std::string nbr) : _message(nbr + " dosen't fit in type " + type) {}
			const char * what () const throw () {
				system("say Scrub!");
				return _message.c_str();
			}
	};

	class DividingByZero : public std::exception {
		public:
			const char * what () const throw () {
				system("say Do you even math?");
				return "Please don't divide by zero...";
			}
	};
};
