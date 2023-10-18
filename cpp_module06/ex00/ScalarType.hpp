/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:56:56 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 15:42:01 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPE_HPP
# define SCALARTYPE_HPP
# include <iostream>

class ScalarType {
    private :
            static void convertChar(double _double);
            static void convertInt(double _double);
            static void convertFloat(double _double, std::string _str);
            static void convertDouble(double _double, std::string _str);
            ScalarType();
            ScalarType(const ScalarType &ob);
            ScalarType& operator=(const ScalarType &ob);
            ~ScalarType();
    public  :
            static void convertAll(std::string arg);
};
#endif