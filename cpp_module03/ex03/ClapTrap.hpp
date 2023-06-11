/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 19:52:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 14:12:08 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap{
	protected	:
			std::string name;
			unsigned int hitPoint;
			unsigned int energyPoint;
			unsigned int attackDamage;
	public	:
			ClapTrap();
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap &ob);
			~ClapTrap();
			ClapTrap& operator=(const ClapTrap &ob); 
			void	attack(const std::string &target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
};
#endif