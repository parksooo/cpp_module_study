/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:06:36 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 18:20:46 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"

class Character : public ICharacter{
	private	:
			std::string	name;
			AMateria	*inventory[4];
	public	:
			Character(std::string name);
			Character(Character const &ob);
			Character &operator=(Character const &ob);
			~Character();
			std::string const &getName() const;
			void equip(AMateria* m);
			void unequip(int idx);
			void use(int idx, ICharacter& target);
};
#endif