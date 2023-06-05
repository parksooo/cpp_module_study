/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:30:37 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 13:41:22 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie{

	private:
			std::string	name;
	public:
			Zombie(std::string name);
			Zombie();
			~Zombie();
			void	announce();
			void	setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
#endif