/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:31:49 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/12 17:15:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "AForm.hpp"

class Intern {
    private :
            std::string formType[3];
    public :
            Intern();
            Intern(const Intern &ob);
            Intern& operator=(const Intern &ob);
            ~Intern();
            AForm   *makeForm(std::string type, std::string target);
};

#endif