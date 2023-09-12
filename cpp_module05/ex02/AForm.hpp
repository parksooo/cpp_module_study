/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:41:28 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 16:05:25 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private :
            const std::string name;
            bool isSigned;
            const int signGrade;
            const int executeGrade;

    public :
            AForm();
            AForm(std::string name, int signGrade, int executeGrade);
            AForm(const AForm &ob);
            AForm&       operator=(const AForm &ob);
            virtual ~AForm();
            std::string getName() const;
            bool getIsSigned() const;
            int getSignGrade() const;
            int getExecuteGrade() const;
            void beSigned(Bureaucrat &obj);
            void checkGrade(int grade) const;
            void checkExecute(int grade) const;
            class GradeTooHighException : public std::exception {
                public :
                        const char * what(void) const throw();
            };
            class GradeTooLowException : public std::exception {
                public :
                        const char * what(void) const throw();
            };
            class NotSignedException : public std::exception {
                public :
                        const char * what(void) const throw();
            };
            class FileOpenFailException : public std::exception {
                public :
                        const char * what(void) const throw();
            };
            virtual void execute(Bureaucrat const &excutor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm &ob);
#endif