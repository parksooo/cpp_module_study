/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:21 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:21 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie *horde = new Zombie[N];
    std::stringstream s;

    for (int i = 0; i < N; i++)
    {
        s.str("");
        s << i;
        horde[i].setName(name + s.str());
    }
    return (horde);
}