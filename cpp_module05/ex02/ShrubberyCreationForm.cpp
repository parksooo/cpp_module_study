/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:09:18 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 13:55:18 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
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

    checkExecute(excutor.getGrade());
    fout.open(excutor.getName() + "_shrubbery", std::ios::out | std::ios::trunc);
    if (fout.fail())
        throw FileOpenFailException();
    fout << getAsciiTree();
    fout.close();
}
