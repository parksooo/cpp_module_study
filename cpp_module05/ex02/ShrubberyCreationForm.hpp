/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:04:41 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/11 19:40:04 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {

    public :
            ShrubberyCreationForm();
            ShrubberyCreationForm(std::string name);
            ShrubberyCreationForm(const ShrubberyCreationForm &ob);
            ShrubberyCreationForm& operator=(const ShrubberyCreationForm &ob);
            ~ShrubberyCreationForm();
            virtual void execute(Bureaucrat const &excutor) const;
};
#endif