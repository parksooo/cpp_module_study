/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:22:48 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 16:24:35 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("default", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ob) : AForm(ob)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ob)
{
    if (this != &ob)
    {
        AForm::operator=(ob);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &excutor) const
{
    if (excutor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    if (this->getIsSigned() == false)
        throw NotSignedException();
    checkExecute(excutor.getGrade());
    std::cout << "(Ready to DRILLLLLL)" << std::endl;
    if (rand() % 2)
        std::cout << this->getTarget() << " has been robotized successfully." << std::endl;
    else
        std::cout << this->getTarget() << " has been failed to robotize." << std::endl;
}
