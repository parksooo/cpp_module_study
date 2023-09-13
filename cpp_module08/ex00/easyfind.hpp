/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:07:55 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 20:23:36 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP
# include <iostream>
# include <algorithm>

template <typename T>
typename T::iterator    easyfind(T &container, int value) {
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), value);
    if (iter == container.end())
        throw std::runtime_error("No value in container");
    return iter;
}
#endif