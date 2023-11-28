/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:40:48 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 21:51:47 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>

class Span {
    public :
            std::vector<int> _vector;
    public  :
            Span();
            Span(size_t _size);
            Span(const Span &ob);
            Span& operator=(const Span &ob);
            ~Span();
            void    addNumber(int num);
            template <typename InputIt>
            void    addNumber(InputIt begin, InputIt end){
                if (this->_vector.size() + std::distance(begin, end) > this->_vector.capacity())
                    throw std::runtime_error("No capacity of Span");
                this->_vector.insert(this->_vector.end(), begin, end);
            }
            int     shortestSpan() const;
            int     longestSpan() const;
};
#endif