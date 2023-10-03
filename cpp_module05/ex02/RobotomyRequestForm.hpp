/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:18:09 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 15:41:05 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
class RobotomyRequestForm : public AForm {
    
    public :
            RobotomyRequestForm();
            RobotomyRequestForm(std::string target);
            RobotomyRequestForm(const RobotomyRequestForm &ob);
            RobotomyRequestForm& operator=(const RobotomyRequestForm &ob);
            ~RobotomyRequestForm();
            virtual void execute(Bureaucrat const &excutor) const;
};
#endif