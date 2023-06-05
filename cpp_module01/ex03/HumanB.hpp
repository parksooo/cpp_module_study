/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:10 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:10 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB{
    private :
            std::string name;
            Weapon *weapon;

    public :
            HumanB(std::string name);
            ~HumanB();
            void    setWeapon(Weapon &weapon);
            void    attack() const;
};
#endif
