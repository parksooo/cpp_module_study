#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("who are you") , grade(1)
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ob)
{
    os << ob.getName();
    os << ",  bureaucrat grade ";
    os << ob.getGrade();
    os << ".";
    return os;
}
