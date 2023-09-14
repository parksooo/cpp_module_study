/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:04:34 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/14 22:11:33 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinCalculator.hpp"
#include <iostream>

int main(int ac, char** av) {

	BitCoinCalculator a;
	if (ac != 2) {
		std::cout << "Error : check Arguments" << std::endl;
	}
	a.letSomeTasteBitCoin(av[1]);
}