/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 16:21:40 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat a("a", 5);
    Bureaucrat b("b", 50);
    Bureaucrat c("c", 150);
    
    ShrubberyCreationForm sc("SC");
    RobotomyRequestForm rr("RR");
    PresidentialPardonForm pp("PP");

    std::cout << sc << std::endl;
    std::cout << rr << std::endl;
    std::cout << pp << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    
    c.signForm(sc);
    c.signForm(rr);
    c.signForm(pp);
    std::cout << std::endl;
    std::cout << sc << std::endl;
    std::cout << rr << std::endl;
    std::cout << pp << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    b.signForm(sc);
    b.signForm(rr);
    b.signForm(pp);
    std::cout << std::endl;
    std::cout << sc << std::endl;
    std::cout << rr << std::endl;
    std::cout << pp << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    a.signForm(sc);
    a.signForm(rr);
    a.signForm(pp);
    std::cout << std::endl;
    std::cout << sc << std::endl;
    std::cout << rr << std::endl;
    std::cout << pp << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        a.executeForm(rr);
    a.executeForm(pp);
    // a.executeForm(sc);

    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    ShrubberyCreationForm test1(sc);
    std::cout << test1 << std::endl;

    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    ShrubberyCreationForm test2("HI");
    test2 = sc;
    std::cout << test2 << std::endl;
}