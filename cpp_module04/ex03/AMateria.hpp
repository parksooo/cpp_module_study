/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:20:46 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 19:16:14 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class ICharacter;
class AMateria{
	protected	:
				std::string type;
	public		:
				AMateria();
				AMateria(AMateria const &ob);
				AMateria(std::string const &type);
				AMateria &operator=(AMateria const &ob);
				virtual ~AMateria();
				std::string const &getType() const;
				virtual AMateria *clone() const = 0;
				virtual void use(ICharacter &target);
};
#endif