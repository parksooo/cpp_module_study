/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 20:05:06 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/08 15:19:09 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->bits));
}

Fixed:: Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	// std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt() const
{
	return this->value >> this->bits;
}


float Fixed::toFloat() const
{
	return (float)this->value / (1 << this->bits);
}

int	Fixed::getRawBits() const
{
	return this->value;
}

void	Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

bool Fixed::operator>(Fixed const &ob) const
{
	if (this->getRawBits() > ob.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const &ob) const
{
	if (this->getRawBits() < ob.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const &ob) const
{
	if (this->getRawBits() >= ob.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const &ob) const
{
	if (this->getRawBits() <= ob.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(Fixed const &ob) const
{
	if (this->getRawBits() == ob.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const &ob) const
{
	if (this->getRawBits() != ob.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(Fixed const ob) const
{
	
	return Fixed(this->toFloat() + ob.toFloat());
}

Fixed Fixed::operator-(Fixed const ob) const
{
	return Fixed(this->toFloat() - ob.toFloat());
}

Fixed Fixed::operator*(Fixed const ob) const
{
	return Fixed(this->toFloat() * ob.toFloat());
}

Fixed Fixed::operator/(Fixed const ob) const
{
	return Fixed(this->toFloat() / ob.toFloat());
}

Fixed &Fixed::operator++()
{
	this->value++;
	return *this;
}

const Fixed Fixed::operator++(int)
{
	const Fixed res(*this);
	this->value++;
	return res;
}

Fixed &Fixed::operator--()
{
	this->value--;
	return *this;
}

const Fixed Fixed::operator--(int)
{
	const Fixed res(*this);
	this->value--;
	return res;
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}
