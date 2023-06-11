/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:37:05 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 16:41:51 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP
# define PHONEBOOK_UTILS_HPP
# include "Contact.hpp"
# include <iostream>
# include <sstream>
# include <string>

std::string	check_size(std::string data);
int	check_isnum(std::string str);
int	check_alphabet(std::string str);
int	print_contacts(Contact contacts[8]);

#endif
