/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 19:30:37 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 16:48:32 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>

class Zombie{

	private:
			std::string	name;
	public:
			Zombie();
			Zombie(std::string name);
			~Zombie();
			void	announce();
};

Zombie *newZombie(std::string name);
void	randomChump(std::string name);
#endif