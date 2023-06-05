/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:12:50 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/01 19:27:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{	
}

std::string	Contact::get_firstname(void) const
{
	return (this->first_name);
}

std::string	Contact::get_lastname(void) const
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->nick_name);
}

std::string	Contact::get_phone_num(void) const
{
	return (this->phone_num);
}

std::string	Contact::get_dark_secret(void) const
{
	return (this->dark_secret);
}

void	Contact::set_firstname(std::string str)
{
	this->first_name = str;
}

void	Contact::set_lastname(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nick_name(std::string str)
{
	this->nick_name = str;
}

void	Contact::set_phone_num(std::string str)
{
	this->phone_num = str;
}

void	Contact::set_dark_secret(std::string str)
{
	this->dark_secret = str;
}