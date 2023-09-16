/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:36:26 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/16 19:03:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error : check your Arguments" << std::endl;
		return 1;
	}

	RPN rpn;

	rpn.letsDoPolandGame(av[1]);
}