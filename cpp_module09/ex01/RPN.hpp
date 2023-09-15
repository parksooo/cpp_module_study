/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:36:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/15 18:30:20 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <sstream>
# include <stack>
# include <exception>
# include <string>

class RPN {
    private :
            std::stack<std::string> avs;
            std::stack<double> rpn;
            void    split(std::string av);
            // void    calculate();
    public  :
            RPN();
            RPN(const RPN &ob);
            RPN& operator=(const RPN &ob);
            ~RPN();
            void    letsDoPolandGame(char *av);
            class Error : public std::exception {
                public :
						const char * what(void) const throw(); 
            };
};
#endif