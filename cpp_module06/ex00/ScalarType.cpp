/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:26:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 16:02:07 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarType.hpp"
#include <math.h>
#include <cstdlib>
#include <cctype>
#include <cfloat>
ScalarType::ScalarType()
{
}

ScalarType::ScalarType(std::string arg)
{
    try {
        this->_str = arg;
    } catch (std::bad_alloc &e) {
        std::cout << "Too big for Allocated.." << std::endl;
        exit(1);
    }
}

ScalarType::ScalarType(const ScalarType &ob) : _str(ob._str), _float(ob._float), _double(ob._double)
{
}

ScalarType &ScalarType::operator=(const ScalarType &ob)
{
    if (this != &ob) {
        this->_str = ob._str;
        this->_float = ob._float;
        this->_double = ob._double;
    }
    return *this;
}

ScalarType::~ScalarType()
{
}

bool findZero(std::string _str) {
    
    size_t idx = _str.find('.');
    
    try {
        while (_str.at(++idx) == '0')
            ;
        if (std::isdigit(_str.at(idx)))   
            return false;
    } catch(std::exception &e){};
    return true;
}

void ScalarType::convertChar() const
{
    if (isnan(this->_double) || isinf(this->_double) || this->_double < 0 || this->_double > 127) {
        std::cout << "char: impossible" << std::endl;
        return ;
    }
    if (!std::isprint(this->_double)) {
        std::cout << "char: Non displayable" << std::endl;
        return ;
    }
    std::cout << "char: '" << static_cast<char>(this->_double) << "'" << std::endl;
}

void ScalarType::convertInt() const
{
    if (isnan(this->_double) || isinf(this->_double) || this->_double < INT_MIN || this->_double > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
        return ;
    }
    std::cout << "int: " << static_cast<int>(this->_double) << std::endl;
}

void ScalarType::convertFloat()
{
    if (errno == ERANGE || (!isinf(this->_double) && (this->_double < -FLT_MAX || this->_double > FLT_MAX))) {
        std::cout << "float: impossible" << std::endl;
        return ;
    }
    this->_float = static_cast<float>(this->_double);
    std::cout << "float: " << this->_float;
    if (!isnan(this->_float) && !isinf(this->_float)
        && (this->_str.find('.') == std::string::npos || findZero(this->_str)))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarType::convertDouble() const
{
    if (errno == ERANGE) {
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    std::cout << "double: " << this->_double;
    if (!isnan(this->_double) && !isinf(this->_double)
        && (this->_str.find('.') == std::string::npos || findZero(this->_str)))
        std::cout << ".0";
    std::cout << std::endl;
}


void ScalarType::convertAll()
{
    this->_double = std::strtod(this->_str.c_str(), NULL);
    convertChar();
    convertInt();
    convertFloat();
    convertDouble();
}
