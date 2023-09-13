/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:17:18 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 20:26:29 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main() {
    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;

    for (int i = 10; i < 20; i++) {
        v.push_back(i);
        d.push_back(i);
        l.push_back(i);
    }

    try {
        std::cout << *(easyfind(v, 13)) << " is at "
            << std::distance(v.begin(), easyfind(v, 13)) << std::endl; 
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << *(easyfind(d, 16)) << " is at "
            << std::distance(d.begin(), easyfind(d, 16)) << std::endl; 
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << *(easyfind(l, 1)) << " is at "
            << std::distance(l.begin(), easyfind(l, 1)) << std::endl; 
    } catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}