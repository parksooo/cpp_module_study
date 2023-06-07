/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:36:28 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/07 20:01:47 by suhwpark         ###   ########.fr       */
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
			void	setRawBits(int const raw);
};
std::ostream& operator <<(std::ostream &os, const Fixed &fixed);
#endif