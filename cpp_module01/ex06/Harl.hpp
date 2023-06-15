/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 17:01:27 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl{
	private	:
			void	debug();
			void	info();
			void	warning();
			void	error();
	public	:
			Harl();
			~Harl();
			void	complain(std::string level);
};

#endif