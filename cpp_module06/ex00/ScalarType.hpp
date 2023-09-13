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
            std::string _str;
            float _float;
            double _double;
            void convertChar() const;
            void convertInt() const;
            void convertFloat();
            void convertDouble() const;
    public  :
            ScalarType();
            ScalarType(std::string arg);
            ScalarType(const ScalarType &ob);
            ScalarType& operator=(const ScalarType &ob);
            ~ScalarType();
            void convertAll();
};
#endif