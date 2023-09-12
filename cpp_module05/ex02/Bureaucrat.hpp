/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:28:58 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 15:51:56 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;
class Bureaucrat {
	private	:
			const std::string name;
			int	grade;
	public	:
			Bureaucrat();
			Bureaucrat(std::string name, int grade);
			Bureaucrat(Bureaucrat const &ob);
			Bureaucrat& operator=(Bureaucrat const &ob);
			~Bureaucrat();
			std::string getName() const;
			int getGrade() const;
			void setGrade(int grade);
			void incrementGrade();
			void decrementGrade();
			void signForm(AForm &ob);
			void executeForm(const AForm &ob);
			class GradeTooHighException : public std::exception{
				public :
						const char * what(void) const throw();
			};
			class GradeTooLowException : public std::exception{
				public :
						const char * what(void) const throw();
			};
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat &ob);
#endif