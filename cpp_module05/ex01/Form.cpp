#include "Form.hpp"

Form::Form() : name("unknown"), isSigned(false), signGrade(1), executeGrade(1)
{
}

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
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

Form::Form(const Form &ob) : name(ob.name), isSigned(ob.isSigned), signGrade(ob.signGrade), executeGrade(ob.executeGrade)
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

Form &Form::operator=(const Form &ob)
{
    if (this != &ob) {
        const_cast<std::string &>(this->name) = ob.getName();
        const_cast<int &>(this->signGrade) = ob.getSignGrade();
        const_cast<int &>(this->executeGrade) = ob.getExcuteGrade();
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

Form::~Form()
{
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getSignGrade() const
{
    return this->signGrade;
}

int Form::getExcuteGrade() const
{
    return this->executeGrade;
}

void Form::beSigned(Bureaucrat &obj)
{
    checkGrade(obj.getGrade());
    if (this->signGrade < obj.getGrade()) {
        throw GradeTooLowException();
    }
    this->isSigned = true;
}

void Form::checkGrade(int grade)
{
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return "Grade Toooo High..";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "Grade Toooo Low..";
}

std::ostream &operator<<(std::ostream &os, const Form &ob)
{
   os << "[Form Informations]" << "\n";
   os << "Name : " << ob.getName() << "\n";
   os << "Signed : " << std::boolalpha << ob.getIsSigned() << "\n";
   os << "Sign Grade : " << ob.getSignGrade() << "\n";
   os << "Excute Grade : " << ob.getExcuteGrade() << "\n";
   return os;
}
