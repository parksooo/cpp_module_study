/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:30 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie stack("John");
    Zombie *heap = newZombie("James");

    randomChump("Rash");
    stack.announce();
    heap->announce();
    delete heap;
    return (0);
}