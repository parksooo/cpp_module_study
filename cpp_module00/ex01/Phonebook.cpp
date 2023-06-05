/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:03:47 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/01 19:37:12 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook:: Phonebook(void)
{
	this->index = 0;
}

Phonebook:: ~Phonebook(void)
{
}

void	Phonebook::add(void)
{
	std::string str;
	
	str = "";
	if (this->index > 7)
		std::cout << "Warning " << this->contacts[this->index % 8].get_firstname()
			<< " WILL OVERWRITE" << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Press your first Name : ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_firstname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Press your last Name : ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_lastname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Press your nick Name : ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_nick_name(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Press your phone number : ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_phone_num(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Press your darkest sercet : ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->index % 8].set_dark_secret(str);
	}
	this->index++;
}

void	Phonebook::print_index(Contact contact)
{
	if (!contact.get_firstname().size())
	{
		std::cout << std::endl << "Fail to get yout INFO!" << std::endl;
		return ;
	}
	std::cout << std::endl << "Here your INFO!" << std::endl;
	std::cout << "First name : " << contact.get_firstname() << std::endl;
	std::cout << "Last name : " << contact.get_lastname() << std::endl;
	std::cout << "Nick name : " << contact.get_nickname() << std::endl;
	std::cout << "Phone number : " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest secret : " << contact.get_dark_secret() << std::endl;
}

void	Phonebook::search()
{
	std::string str;
	
	if (!print_contacts(this->contacts))
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	while(!std::cin.eof())
	{
		std::cout << "Press an index you want: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->contacts[str[0] - '0' - 1].get_firstname().size())
			{
				print_index(contacts[str[0] - '0' - 1]);
				break ;
			}
			else
				std::cout << "Press correct INDEX!" << std::endl;
		}
	}
}