/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:51:30 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/15 18:27:56 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &ob)
{
    *this = ob;
}

RPN &RPN::operator=(const RPN &ob)
{
    if (this != &ob)
        *this = ob;
    return *this;
}

RPN::~RPN()
{
}

void RPN::split(std::string av)
{
    std::stack<std::string> tmp;
    std::istringstream ss(av);
    std::string _split;
    
    while(std::getline(ss, _split, ' ')) {
        if (_split.empty() == false)
            tmp.push(_split);
        std::cout << _split << std::endl;
    }

}

// void RPN::calculate()
// {
// }

void RPN::letsDoPolandGame(char *av)
{
    split(av);
}

const char *RPN::Error::what(void) const throw()
{
    return "Error";
}
