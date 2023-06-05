/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:05 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:05 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA{
    
    private :
            std::string name;
            Weapon &weapon;
    public :
            HumanA(std::string name, Weapon &weapon);
            ~HumanA();
            void attack() const;
};
#endif