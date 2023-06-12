/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:25:43 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 15:46:36 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a("A");
	FragTrap b("B");

	a.attack("B");
	b.takeDamage(30);
	b.beRepaired(4);
	std::cout << std::endl;
	b.attack("A");
	a.takeDamage(30);
	a.beRepaired(2);
	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
}