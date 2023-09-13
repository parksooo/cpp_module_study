/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:50:25 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 17:59:17 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
# include <iostream>

template <typename T>
void    swap(T &t1, T &t2)
{
    T   tmp;
    
    tmp = t1;
    t1 = t2;
    t2 = tmp;
}

template <typename T>
T   min(T &t1, T &t2)
{
    return t1 > t2 ? t2 : t1;
}

template <typename T>
T   max(T &t1, T &t2)
{
    return t1 > t2 ? t1 : t2; 
}
#endif