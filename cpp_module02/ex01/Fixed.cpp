/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:46:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/07 21:36:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = num << this->bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(num * (1 << this->bits));
}

Fixed:: Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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