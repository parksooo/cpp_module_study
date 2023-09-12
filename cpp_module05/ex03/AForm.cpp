/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:30 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 16:06:50 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("unknown"), isSigned(false), signGrade(1), executeGrade(1)
{
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    try {
        checkGrade(signGrade);
    }
    catch(const std::exception &e) {
        std::cout << this->name << ": " << "sign " << e.what() << std::endl;
    }
    try {
        checkGrade(executeGrade);
    }
    catch(const std::exception &e) {
        std::cout << this->name << ": " << "excute " << e.what() << std::endl;
    }
}

AForm::AForm(const AForm &ob) : name(ob.name), isSigned(ob.isSigned), signGrade(ob.signGrade), executeGrade(ob.executeGrade)
{
    try {
        checkGrade(ob.signGrade);
    }
    catch(const std::exception &e) {
        std::cout << this->name << ": " << "sign " << e.what() << std::endl;
    }
    try {
        checkGrade(ob.executeGrade);
    }
    catch(const std::exception &e) {
        std::cout << this->name << ": " << "excute " << e.what() << std::endl;
    }
}

AForm &AForm::operator=(const AForm &ob)
{
    if (this != &ob) {
        const_cast<std::string &>(this->name) = ob.getName();
        const_cast<int &>(this->signGrade) = ob.getSignGrade();
        const_cast<int &>(this->executeGrade) = ob.getExecuteGrade();
        this->isSigned = ob.isSigned;
    }
    try {
        checkGrade(this->signGrade);
    }
    catch(const std::exception &e) {
        std::cout << this->name << ": " << "sign " << e.what() << std::endl;
    }
    try {
        checkGrade(this->executeGrade);
    }
    catch(const std::exception &e) {
        std::cout << this->name << ": " << "excute " << e.what() << std::endl;
    }
    return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

void AForm::beSigned(Bureaucrat &obj)
{
    checkGrade(obj.getGrade());
    if (this->signGrade < obj.getGrade()) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

void AForm::checkGrade(int grade) const
{
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

void AForm::checkExecute(int grade) const 
{
    if (this->isSigned == false)
        throw NotSignedException();
    checkGrade(grade);
    if (this->executeGrade < grade)
        throw GradeTooLowException();
} 
const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "Grade Toooo High..";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "Grade Toooo Low..";
}
const char *AForm::NotSignedException::what(void) const throw()
{
    return "This form has not been signed..";
}
const char *AForm::FileOpenFailException::what(void) const throw()
{
    return "FILE OPEN FAIL..";
}
std::ostream &operator<<(std::ostream &os, const AForm &ob)
{
   os << "[Form Informations]" << "\n";
   os << "Name : " << ob.getName() << "\n";
   os << "Signed : " << std::boolalpha << ob.getIsSigned() << "\n";
   os << "Sign Grade : " << ob.getSignGrade() << "\n";
   os << "Excute Grade : " << ob.getExecuteGrade() << "\n";
   return os;
}
