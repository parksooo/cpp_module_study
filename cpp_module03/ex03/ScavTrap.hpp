/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:03:55 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 16:22:24 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap{
	public	:
			ScavTrap();
			ScavTrap(std::string name);
			ScavTrap(const ScavTrap &ob);
			ScavTrap& operator=(const ScavTrap &ob);
			~ScavTrap();
			void	attack(const std::string &target);
			void	guardGate();
};

#endif