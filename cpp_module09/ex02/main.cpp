/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:16:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/18 14:42:35 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int    validateArgumentsValues(std::string n) {
    char *ptr;
    double _value = std::strtod(n.c_str(), &ptr);

    if (_value == 0.0 && !std::isdigit(n[1]))
        return -1;
    if (*ptr && std::strcmp("f", ptr))
        return -1;
    if (_value < 0)
        return -1;
    return static_cast<int>(_value);
}

std::vector<int>    parseArguments(int ac, char **av) {
	std::vector<int> valueVector;
    int i = 1;

    while (i < ac) {
        std::string argv(av[i]);
        std::istringstream ss(argv);
        std::string num;
        
        while (std::getline(ss, num, ' ')) {
			int _value = 0;
			if (num.empty())
				continue ;
			_value = validateArgumentsValues(num);
            if (!num.empty() && _value < 0) {
                throw std::runtime_error("Error.");
            }
			valueVector.push_back(_value);			
        }
		i++;
    }
    return valueVector;
}

int main(int ac, char **av)
{
	std::vector<int> valueVector;
	
    if (ac < 2) {
        std::cout << "Error." << std::endl;
        return 1;
    }
    try {
        valueVector = parseArguments(ac, av);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
	for (std::vector<int>::iterator iter = valueVector.begin(); iter != valueVector.end(); iter++) {
		std::cout << *iter << std::endl;
	}
}