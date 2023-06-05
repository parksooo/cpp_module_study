/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:27:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 19:29:50 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP
# include <iostream>

class Karen{
	private	:
			void	debug();
			void	info();
			void	warning();
			void	error();
	public	:
			void	complain(std::string level);
};

#endif