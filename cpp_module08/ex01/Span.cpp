/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 20:47:26 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 21:52:45 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
    this->_vector.reserve(0);
}

Span::Span(size_t _size)
{
    this->_vector.reserve(_size);
}

Span::Span(const Span &ob)
{
    *this = ob;
}

Span &Span::operator=(const Span &ob)
{
    if (this != &ob) {
        this->_vector = ob._vector;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (this->_vector.size() >= this->_vector.capacity())
        throw std::runtime_error("No capacity of Span");
    this->_vector.push_back(num);
}

int Span::shortestSpan() const
{
    if (this->_vector.size() < 2)
        throw std::out_of_range("Too short size");
    std::vector<int> tmp(this->_vector);
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (std::vector<int>::iterator iter = tmp.begin() + 2;
            iter < tmp.end(); iter++) {
        if (min > *iter - *(iter - 1))
            min = *iter - *(iter - 1);
    }
    return min;
}

int Span::longestSpan() const
{
    if (this->_vector.size() < 2)
        throw std::out_of_range("Too short size");
    return *std::max_element(this->_vector.begin(), this->_vector.end()) - *std::min_element(this->_vector.begin(), this->_vector.end());
}
