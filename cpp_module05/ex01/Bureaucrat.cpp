/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:37 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/11 15:41:38 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown") , grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(1)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &ob) : name(ob.getName()), grade(ob.getGrade())
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &ob)
{
    if (this != &ob)
        this->grade = ob.getGrade();
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::setGrade(int grade)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        if (grade > 150)
            throw GradeTooLowException();
        this->grade = grade;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    };
}

void Bureaucrat::incrementGrade()
{
    setGrade(getGrade() - 1);
}

void Bureaucrat::decrementGrade()
{
    setGrade(getGrade() + 1);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "Grade Toooo High..";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "Grade Toooo Low..";
}

void Bureaucrat::signForm(Form &ob)
{
    try {
        ob.beSigned(*this);
        std::cout << this->name << " signed " << ob.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->name << " couldn't sign " << ob.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ob)
{
    os << ob.getName();
    os << ",  bureaucrat grade ";
    os << ob.getGrade();
    os << ".";
    return os;
}
