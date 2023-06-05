/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:37:05 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 13:41:50 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP
# define PHONEBOOK_UTILS_HPP
# include "Contact.hpp"
# include <iostream>
# include <sstream>

std::string	check_size(std::string data);
int	print_contacts(Contact contacts[8]);
#endif
