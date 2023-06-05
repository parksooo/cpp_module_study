/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:21:24 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 19:40:18 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
	Karen k;

	k.complain("DEBUG");
	std::cout << "-----Other Test Case!" << std::endl;
	k.complain("INFO");
	std::cout << "-----Other Test Case!" << std::endl;
	k.complain("WARNING");
	std::cout << "-----Other Test Case!" << std::endl;
	k.complain("ERROR");
}