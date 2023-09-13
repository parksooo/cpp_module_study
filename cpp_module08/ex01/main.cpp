/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:22:27 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 21:32:49 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
int main() {
    
    Span sp(5);

    try {
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        // sp.addNumber(1);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "------ span ------" << std::endl;
    Span span(10000);
    for (int i = 1; i <= 9998; i++)
        span.addNumber(i);
    span.addNumber(9998);
    span.addNumber(100000);
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    try
    {
        span.addNumber(-1);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
}