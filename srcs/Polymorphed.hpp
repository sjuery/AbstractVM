#pragma once
#include "IOperand.hpp"

template <class T>
class Polymorphed : public IOperand {
private:
	T 				_number;
	std::string 	_string;
	eOperandType	_type;
public:
	Polymorphed(T);
	int getPrecision( void ) const;
	eOperandType getType( void ) const;
	IOperand const * operator+( IOperand const & rhs ) const;
	IOperand const * operator-( IOperand const & rhs ) const;
	IOperand const * operator*( IOperand const & rhs ) const;
	IOperand const * operator/( IOperand const & rhs ) const;
	IOperand const * operator%( IOperand const & rhs ) const;
	std::string const & toString( void ) const;
};

template <class T>
Polymorphed<T>::Polymorphed(T number) : _number(number), _string(std::to_string(number)) {
	if(!strcmp(typeid(_number).name(), "a"))
		_type = IOperand::int8;
	else if(!strcmp(typeid(_number).name(), "s"))
		_type = IOperand::int16;
	else if(!strcmp(typeid(_number).name(), "i"))
		_type = IOperand::int32;
	else if(!strcmp(typeid(_number).name(), "f"))
		_type = IOperand::intf;
	else if(!strcmp(typeid(_number).name(), "d"))
		_type = IOperand::intd;
}

template <class T>
int Polymorphed<T>::getPrecision( void ) const{
	return _type;
}

template <class T>
IOperand::eOperandType Polymorphed<T>::getType( void ) const {
	return _type;
}

template <class T>
IOperand const * Polymorphed<T>::operator+( IOperand const & rhs ) const {
	eOperandType precision = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
	return IOperand::createOperand(precision, std::to_string(_number + stod(rhs.toString())));
}

template <class T>
IOperand const * Polymorphed<T>::operator-( IOperand const & rhs ) const {
	eOperandType precision = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
	return IOperand::createOperand(precision, std::to_string(_number - stod(rhs.toString())));
}

template <class T>
IOperand const * Polymorphed<T>::operator*( IOperand const & rhs ) const {
	eOperandType precision = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
	return IOperand::createOperand(precision, std::to_string(_number * stod(rhs.toString())));
}

template <class T>
IOperand const * Polymorphed<T>::operator/( IOperand const & rhs ) const {
	eOperandType precision = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
	if(stod(rhs.toString()) != 0)
		return IOperand::createOperand(precision, std::to_string(_number / stod(rhs.toString())));
	throw DividingByZero();
}

template <class T>
IOperand const * Polymorphed<T>::operator%( IOperand const & rhs ) const {
	eOperandType precision = getPrecision() < rhs.getPrecision() ? rhs.getType() : getType();
	return IOperand::createOperand(precision, std::to_string(fmod(_number, stod(rhs.toString()))));
}

template <class T>
std::string const & Polymorphed<T>::toString( void ) const {
	return _string;
}
