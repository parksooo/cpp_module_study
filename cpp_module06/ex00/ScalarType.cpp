/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:26:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/16 17:59:29 by suhwpark         ###   ########.fr       */
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

ScalarType::ScalarType(const ScalarType &ob)
{
    static_cast<void>(ob);
}

ScalarType &ScalarType::operator=(const ScalarType &ob)
{
    if (this != &ob) {
        return *this;
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

void ScalarType::convertChar(double _double)
{
    if (isnan(_double) || isinf(_double) || _double < 0 || _double > 127) {
        std::cout << "char: impossible" << std::endl;
        return ;
    }
    if (!std::isprint(_double)) {
        std::cout << "char: Non displayable" << std::endl;
        return ;
    }
    std::cout << "char: '" << static_cast<char>(_double) << "'" << std::endl;
}

void ScalarType::convertInt(double _double)
{
    if (isnan(_double) || isinf(_double) || _double < INT_MIN || _double > INT_MAX) {
        std::cout << "int: impossible" << std::endl;
        return ;
    }
    std::cout << "int: " << static_cast<int>(_double) << std::endl;
}

void ScalarType::convertFloat(double _double, std::string _str)
{
    if (errno == ERANGE || (!isinf(_double) && (_double < -FLT_MAX || _double > FLT_MAX))) {
        std::cout << "float: impossible" << std::endl;
        return ;
    }
    float _float = static_cast<float>(_double);
    std::cout << "float: " << _float;
    if (!isnan(_float) && !isinf(_float)
        && (_str.find('.') == std::string::npos || findZero(_str)))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarType::convertDouble(double _double, std::string _str)
{
    if (errno == ERANGE) {
        std::cout << "double: impossible" << std::endl;
        return ;
    }
    std::cout << "double: " << _double;
    if (!isnan(_double) && !isinf(_double)
        && (_str.find('.') == std::string::npos || findZero(_str)))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarType::convertAll(std::string arg)
{
    std::string _str;
    try {
        _str = arg;
    } catch (std::bad_alloc &e) {
        std::cout << "Too big for Allocated.." << std::endl;
        exit(1);
    }
    double _double = std::strtod(_str.c_str(), NULL);
    convertChar(_double);
    convertInt(_double);
    convertFloat(_double, _str);
    convertDouble(_double, _str);
}
