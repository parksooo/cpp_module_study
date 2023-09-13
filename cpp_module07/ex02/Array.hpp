/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:55:05 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 19:34:29 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
# include <iostream>
# include <cstdlib>

template <typename T>
class Array {
    private :
            T   *_array;
            unsigned int _size;
    public  :
            Array();
            Array(unsigned int n);
            Array(const Array &ob);
            Array&  operator=(const Array &ob);
            ~Array();
            T&  operator[](unsigned int idx);
            const T&  operator[](unsigned int idx) const;
            unsigned int    size() const;
};

# include "Array.tpp"

#endif