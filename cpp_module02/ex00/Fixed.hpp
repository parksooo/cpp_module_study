/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:36:28 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/07 15:58:33 by suhwpark         ###   ########.fr       */
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
			~Fixed();
			Fixed(const Fixed& fixed);
			Fixed& operator=(const Fixed& fixed);
			int	getRawBits(void) const;
			void	setRawBits(int const raw); 
};
#endif