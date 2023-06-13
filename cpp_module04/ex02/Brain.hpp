/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:42:36 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 19:09:11 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain{
	private	:
			std::string idea[100];
	public	:
			Brain();
			Brain(Brain const &ob);
			Brain& operator=(Brain const &ob);
			~Brain();
			std::string	getIdea(int n) const;
			void	setIdea(std::string think, int n);
};
#endif