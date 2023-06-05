/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 18:20:41 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/05 18:20:41 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *strPTR = &str;
    std::string &strREF = str;

    std::cout << "Show strs address" << std::endl;
    std::cout << "str address : " << &str << std::endl;
    std::cout << "strPTR address : " << strPTR << std::endl;
    std::cout << "strREf address : " << &strREF << std::endl;

    std::cout << std::endl;
    std::cout << "Show strs value" << std::endl;
    std::cout << "str value : " << str << std::endl;
    std::cout << "strPTR value : " << *strPTR << std::endl;
    std::cout << "strREf value : " << strREF << std::endl;
    return (0);
}