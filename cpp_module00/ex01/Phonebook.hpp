/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:07:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/01 18:55:38 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include "Contact.hpp"
#include "Phonebook_utils.hpp"

class Phonebook
{
	private:
			Contact contacts[8];
			int		index;

	public:
			Phonebook();
			~Phonebook();
			void	add(void);
			void	search(void);
			void	print_index(Contact contact);
};
#endif