/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:16 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:17 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
class Weapon{

    private :
            std::string type;
    public  :
            Weapon(std::string name);
            ~Weapon();
            std::string getType() const;
            void    setType(std::string type);
};
#endif