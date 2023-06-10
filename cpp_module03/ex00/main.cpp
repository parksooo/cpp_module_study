/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:25:43 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/10 20:40:41 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("su");
	ClapTrap c;

	a.attack("su");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("default");
	c = a;
	a.takeDamage(10);
	a.beRepaired(10);
}