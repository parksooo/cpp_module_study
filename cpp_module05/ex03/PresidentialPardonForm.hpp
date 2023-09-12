/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:43:17 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 16:03:45 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    public :
            PresidentialPardonForm();
            PresidentialPardonForm(std::string name);
            PresidentialPardonForm(const PresidentialPardonForm &ob);
            PresidentialPardonForm& operator=(const PresidentialPardonForm & ob);
            ~PresidentialPardonForm();
            virtual void execute(Bureaucrat const &excutor) const;
};
#endif