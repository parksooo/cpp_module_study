/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:49:12 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 13:28:22 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
class Contact
{
	private:
			std::string first_name;
			std::string last_name;
			std::string nick_name;
			std::string phone_num;
			std::string dark_secret;
	
	public :
			Contact();
			~Contact();
			std::string get_firstname() const;
			std::string get_lastname() const;
			std::string get_nickname() const;
			std::string get_phone_num() const;
			std::string	get_dark_secret() const;
			void		set_firstname(std::string str);
			void		set_lastname(std::string str);
			void		set_nick_name(std::string str);
			void		set_phone_num(std::string str);
			void		set_dark_secret(std::string str);
};
#endif