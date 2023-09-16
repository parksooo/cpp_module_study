/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:51:30 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/16 19:03:08 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	this->avsCount = 0;
	this->operatorCount = 0;
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
        if (_split.empty())
			continue;
        tmp.push(_split);
    }
	while(!tmp.empty()) {
		this->avs.push(validateInput(tmp.top()));
		tmp.pop();
	}
	if (this->avsCount - this->operatorCount != 1)
		throw ErrorRPN();
}

std::string RPN::validateInput(std::string input)
{
    char *ptr;
	double _double;

	if (input.length() == 1 && (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')) {
		this->operatorCount += 1;
		return input;
	}
	_double = std::strtod(input.c_str(), &ptr);
	if (_double == 0.0 && !std::isdigit(input[0]))
		throw ErrorRPN();
	if (*ptr && std::strcmp("f", ptr))
		throw ErrorRPN();
	if (_double < 0 || _double > 9)
		throw ErrorRPN();
	this->avsCount += 1;
	return input;
}

double	calculatByOperator(double a, double b, std::string operatorStr)
{
	if (operatorStr == "+")
		return a + b;
	if (operatorStr == "-")
		return a - b;
	if (operatorStr == "*")
		return a * b;
	if (operatorStr == "/")
		return a / b;
	else 
		throw RPN::ErrorRPN();	
}

void RPN::calculate()
{
	while (!this->avs.empty()) {
		if (this->avs.top() == "+" || this->avs.top() == "-" || this->avs.top() == "*" || this->avs.top() == "/")
		{
			if (this->rpn.size() < 2)
				throw ErrorRPN();
			double a = this->rpn.top();
			this->rpn.pop();
			double b = this->rpn.top();
			this->rpn.pop();
			this->rpn.push(calculatByOperator(b, a, this->avs.top()));
			this->avs.pop();
		}
		else {
			this->rpn.push(std::strtod(this->avs.top().c_str(), NULL));
			this->avs.pop();
		}
	}
	std::cout << this->rpn.top() << std::endl;
}

void RPN::letsDoPolandGame(char *av)
{
	try {
    	split(av);
		calculate();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

const char *RPN::ErrorRPN::what(void) const throw()
{
    return "Error";
}
