/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/10/16 15:56:58 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
	Intern	someRandomIntern;
    Bureaucrat test("a", 1);
	AForm	*a = NULL;
	AForm	*b = NULL;
	AForm	*c = NULL;
	AForm	*d = NULL;

	try {
		a = someRandomIntern.makeForm("robotomy request", "Bender");
		b = someRandomIntern.makeForm("presidential pardon", "son");
		c = someRandomIntern.makeForm("shrubbery creation", "kim");
		d = someRandomIntern.makeForm("asdf", "park");
	}
	catch(const std::bad_alloc &e) {
		std::cout << "Allocation failed: " << e.what() << std::endl;
	}
    a->beSigned(test);
    try {
        a->execute(test);
    } catch(const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
	delete a;
	delete b;
	delete c;
	delete d;

	return 0;
}