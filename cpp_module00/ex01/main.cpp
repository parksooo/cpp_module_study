/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:14:02 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/03 14:10:24 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main()
{
	Phonebook ph;
	std::string cmd;

	while(cmd != "EXIT")
	{
		std::cout << "Press Command! >> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			ph.add();
		if (cmd == "SEARCH")
			ph.search();
		if (std::cin.eof())
		{
			std::cout << "BYE~" << std::endl;
			return (0);
		}
	}
	return (0);
}