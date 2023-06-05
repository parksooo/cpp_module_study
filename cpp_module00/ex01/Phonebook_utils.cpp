/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:35:47 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 13:52:17 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook_utils.hpp"

std::string	check_size(std::string data)
{
	int	n;

	n = 0;
	if (data.size() > 10)
	{
		data.resize(10);
		data[9] = '.';
	}
	else
	{
		n = 10 - data.size();
		while(n--)
			data.insert(0, " ");
	}
	return (data);
}

int	print_contacts(Contact contacts[8])
{
	int	i;
	std::stringstream s;

	i = 0;
	if (!contacts[0].get_firstname().size())
		return (0);
	std::cout << ".-------------------------------------------." << std::endl;
	std::cout << "|index     |Firstname |Lastname  |Nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	while (i < 8)
	{
		s.str("");
		if (!contacts[i].get_firstname().size())
			break ;
		s << i + 1;
		std::cout << "|" << check_size(s.str()) << "|";
		std::cout << check_size(contacts[i].get_firstname()) << "|";
		std::cout << check_size(contacts[i].get_lastname()) << "|";
		std::cout << check_size(contacts[i].get_nickname()) << "|" << std::endl;
		i++;
	}
	std::cout << ".-------------------------------------------." << std::endl;
	return (1);
}
