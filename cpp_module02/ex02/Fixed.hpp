/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:55:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/17 18:36:40 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed{
	private :
			int	value;
			const static int	bits = 8;
	public	:
			Fixed();
			Fixed(const int num);
			Fixed(const float num);
			Fixed(const Fixed& fixed);
			~Fixed();
			Fixed& operator=(const Fixed& fixed);
			float toFloat() const;
			int	toInt() const;
			int	getRawBits(void) const;
			void setRawBits(int const raw);
			bool operator>(Fixed const &ob) const;
			bool operator<(Fixed const &ob) const;
			bool operator>=(Fixed const &ob) const;
			bool operator<=(Fixed const &ob) const;
			bool operator==(Fixed const &ob) const;
			bool operator!=(Fixed const &ob) const;
			Fixed operator+(Fixed const ob) const;
			Fixed operator-(Fixed const ob) const;
			Fixed operator*(Fixed const ob) const;
			Fixed operator/(Fixed const ob) const;
			Fixed &operator++();
			const Fixed operator++(int);
			Fixed &operator--();
			const Fixed operator--(int);
			
			static Fixed& max(Fixed &a, Fixed &b);			
			static const Fixed& max(Fixed const &a, Fixed const &b);
			static Fixed& min(Fixed &a, Fixed &b);
			static const Fixed& min(Fixed const &a, Fixed const &b);
};
std::ostream& operator <<(std::ostream &os, const Fixed &fixed);
#endif