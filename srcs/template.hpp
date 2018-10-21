#pragma once
#include "IOperand.hpp"

template <class T>
class Template : public IOperand {
private:
	T _number;
public:
	Template(T);
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
Template<T>::Template(T number) : _number(number) {
	std::cout << "Created int with value " << _number << std::endl;
}

template <class T>
int Template<T>::getPrecision( void ) const{
	return 0;
}

template <class T>
IOperand::eOperandType Template<T>::getType( void ) const {
	return int8;
}

template <class T>
IOperand const * Template<T>::operator+( IOperand const & rhs ) const {
	(void)rhs;
	return this;
}

template <class T>
IOperand const * Template<T>::operator-( IOperand const & rhs ) const {
	(void)rhs;
	return this;
}

template <class T>
IOperand const * Template<T>::operator*( IOperand const & rhs ) const {
	(void)rhs;
	return this;
}

template <class T>
IOperand const * Template<T>::operator/( IOperand const & rhs ) const {
	(void)rhs;
	return this;
}

template <class T>
IOperand const * Template<T>::operator%( IOperand const & rhs ) const {
	(void)rhs;
	return this;
}

template <class T>
std::string const & Template<T>::toString( void ) const {
	static std::string string = "string";
	return string;
}
