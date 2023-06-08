/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:55:22 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/08 14:49:16 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() 
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;
	
	std::cout << "operator+ :" << a.operator+(b) << std::endl;
	std::cout << "operator- :" << a.operator-(b) << std::endl;
	std::cout << "operator* :" << a.operator*(b) << std::endl;
	std::cout << "operator/ :" << a.operator/(b) << std::endl;
	std::cout << "operator> :" << a.operator>(b) << std::endl;
	std::cout << "operator>= :" << a.operator>=(b) << std::endl;
	std::cout << "operator< :" << a.operator<(b) << std::endl;
	std::cout << "operator<= :" << a.operator<=(b) << std::endl;
	std::cout << "operator== :" << a.operator==(b) << std::endl;
	std::cout << "operator!= :" << a.operator!=(b) << std::endl;
	std::cout << "max :" << Fixed::max(a, b) << std::endl;
	std::cout << "min :" << Fixed::min(a, b) << std::endl;
	std::cout << ++a << std::endl;
	return 0;
}