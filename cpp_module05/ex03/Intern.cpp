/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:03 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 17:16:55 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    this->formType[0] = "shrubbery creation";
    this->formType[1] = "robotomy request";
    this->formType[2] = "presidential pardon";
}

Intern::Intern(const Intern &ob)
{
    this->formType[0] = ob.formType[0];
    this->formType[1] = ob.formType[1];
    this->formType[2] = ob.formType[2];
}

Intern &Intern::operator=(const Intern &ob)
{
    if (this != &ob) {
        this->formType[0] = ob.formType[0];
        this->formType[1] = ob.formType[1];
        this->formType[2] = ob.formType[2];
    }
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string type, std::string target)
{
    int i;

    for (i = 0; i < 3; i++){
        if (this->formType[i] == type)
            break ;
    }
    
    switch (i)
    {
        case 0:
            std::cout << "Intern creates " << target << std::endl;
            return new ShrubberyCreationForm(target);
        case 1:
            std::cout << "Intern creates " << target << std::endl;
            return new RobotomyRequestForm(target);
        case 2:
            std::cout << "Intern creates " << target << std::endl;
            return new PresidentialPardonForm(target);
        default:
            std::cout << "This request type of " << type << " doesn't exit. Check your request." << std::endl;
    }
    return NULL;
}
