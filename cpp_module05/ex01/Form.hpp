#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private :
            const std::string name;
            bool isSigned;
            const int signGrade;
            const int executeGrade;

    public :
            Form();
            Form(std::string name, int signGrade, int executeGrade);
            Form(const Form &ob);
            Form&       operator=(const Form &ob);
            ~Form();
            std::string getName() const;
            bool getIsSigned() const;
            int getSignGrade() const;
            int getExcuteGrade() const;
            void beSigned(Bureaucrat &obj);
            void checkGrade(int grade);
            class GradeTooHighException : public std::exception{
				public :
						const char * what(void) const throw();
			};
			class GradeTooLowException : public std::exception{
				public :
						const char * what(void) const throw();
			};
};
std::ostream& operator<<(std::ostream& os, const Form &ob);
#endif