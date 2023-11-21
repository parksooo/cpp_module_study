/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:37:39 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 18:49:53 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <cstdlib>
# include <iostream>

template <typename T>
void    iter(T array[], size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

template <typename T>
void    iter(const T array[], const size_t len, void (*func)(T&))
{
    for (size_t i = 0; i < len; i++)
        func(array[i]);
}

template<typename T>
void    display(T &value)
{
    std::cout << value << " ";
}

#endif