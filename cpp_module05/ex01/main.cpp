/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/11 15:41:24 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  ba("ba", 150);
    Form        fa("fa", 50, 50);

    std::cout << fa << std::endl;

    ba.signForm(fa);
    std::cout << fa << std::endl;

    while (ba.getGrade() != 50)
        ba.incrementGrade();
    ba.signForm(fa);
    std::cout << fa << std::endl;

    Form    test1("test1", 10, 10);
    Form    test2("test2", 42, 42);

    test1 = test2;
    std::cout << test1 << std::endl;

    Form    test3(test2);
    std::cout << test3 << std::endl;

    Form    abnormal("abnormal", 151, 150);

    return 0;
}