/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:09:18 by suhwpark          #+#    #+#             */
/*   Updated: 2023/10/03 13:32:15 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("default", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ob) : AForm(ob)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ob)
{
    if (this != &ob)
    {
        AForm::operator=(ob);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string getAsciiTree() {
    return "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{";
}

void ShrubberyCreationForm::execute(Bureaucrat const &excutor) const
{
    std::ofstream fout;

    if (excutor.getGrade() > this->getExecuteGrade())
        throw GradeTooLowException();
    if (this->getIsSigned() == false)
        throw NotSignedException();
    checkExecute(excutor.getGrade());
    fout.open(excutor.getName() + "_shrubbery", std::ios::out | std::ios::trunc);
    if (fout.fail())
        throw FileOpenFailException();
    fout << getAsciiTree();
    fout.close();
}
