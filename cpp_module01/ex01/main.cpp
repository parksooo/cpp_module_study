/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:27 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:27 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *horde;

    horde = zombieHorde(10, "John");
    for (int i = 0; i < 10; i++)
        horde[i].announce();
    delete [] horde;
    return (0);
}