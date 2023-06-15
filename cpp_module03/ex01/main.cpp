/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:25:43 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/13 19:27:11 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("A");
	ScavTrap b("B");

	a.attack("B");
	b.takeDamage(20);
	b.beRepaired(3);
	std::cout << std::endl;
	b.attack("A");
	a.takeDamage(20);
	a.beRepaired(10);
	std::cout << std::endl;
	a.guardGate();
	std::cout << std::endl;
}