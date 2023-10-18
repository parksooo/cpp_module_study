/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:54:11 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 15:01:43 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarType.hpp"

int main (int ac, char **av) {
    if (ac != 2) {
        std::cout << "Invalid Arguments" << std::endl;
        return 1;
    }
    ScalarType::convertAll(av[1]);
}