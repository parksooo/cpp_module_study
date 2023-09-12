/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:46:29 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 16:04:10 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ob) : AForm(ob)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ob)
{
    if (this != &ob)
    {
        AForm::operator=(ob);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &excutor) const
{
    checkExecute(excutor.getGrade());
    std::cout << excutor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
