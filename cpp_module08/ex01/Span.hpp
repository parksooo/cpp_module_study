/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:40:48 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 21:24:56 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>

class Span {
    private :
            std::vector<int> _vector;
    public  :
            Span();
            Span(size_t _size);
            Span(const Span &ob);
            Span& operator=(const Span &ob);
            ~Span();
            void    addNumber(int num);
            int     shortestSpan() const;
            int     longestSpan() const;
};
#endif