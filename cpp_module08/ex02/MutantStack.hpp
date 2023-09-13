/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 21:28:21 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 22:15:50 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
    public  :
            MutantStack() {};
            MutantStack(const MutantStack &ob) {return *this};
            MutantStack& operator=(const MutantStack &ob) {*this = ob; return *this};
            ~MutantStack() {};

            typedef typename MutantStack<T>::stack::container_type::iterator iterator;
            iterator begin() {return this->c.begin();}
            iterator end() {return this->c.end();}

            typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
            reverse_iterator rbegin() {return this->c.rbegin();}
            reverse_iterator rend() {return this->c.rend();}

			typedef typename MutantStack<T>::stack::conatiner_type::const_iterator const_iterator;
			const_iterator cbegin() {return this->c.cbegin();}
			const_iterator cend() {return this->c.cend();}

			typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
			const_reverse_iterator crbegin() {return this->c.crbegin();}
			const_reverse_iterator crend() {return this->c.crend();}
}
#endif