/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:36:23 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/16 18:56:59 by suhwpark         ###   ########.fr       */
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
            int avsCount;
            int operatorCount;
            std::stack<double> rpn;
            void    split(std::string av);
            void    calculate();
            std::string    validateInput(std::string input);
    public  :
            RPN();
            RPN(const RPN &ob);
            RPN& operator=(const RPN &ob);
            ~RPN();
            void    letsDoPolandGame(char *av);
            class ErrorRPN : public std::exception {
                public :
			const char * what(void) const throw(); 
            };
};
#endif