/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:22:07 by suhwpark          #+#    #+#             */
/*   Updated: 2023/05/29 18:43:03 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string	str;
	
	if (ac == 1){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else{
		for (int i = 1; i < ac; i++){
			str = av[i];
			for (size_t j = 0; j < str.size(); j++){
				str[j] = std::toupper(str[j]);
			}
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}