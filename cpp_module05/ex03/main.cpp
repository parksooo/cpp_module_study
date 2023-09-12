/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 17:17:26 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm *a;
    AForm *b;
    AForm *d;
    AForm *c;
    
    try {
        a = someRandomIntern.makeForm("shrubbery creation", "Bender");
        b = someRandomIntern.makeForm("robotomy request", "Robot");
        c = someRandomIntern.makeForm("presidential pardon", "Paul");
        d = someRandomIntern.makeForm("set me free", "intern");
    } catch (const std::bad_alloc &e) {
        std::cout << "Failed to create Form: " << e.what() << std::endl;
    }

    delete a;
    delete b;
    delete c;
    delete d;
}