/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:22:55 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 19:36:40 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]) ,_size(n)
{
}

template <typename T>
Array<T>::Array(const Array &ob)
{
    this->_size = ob.size();
    this->_array = new T[this->_size];
    for (unsigned int i = 0; i < this->_size; i++)
        this->_array[i] = ob._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &ob)
{
    if (this != &ob)
    {
        delete [] this->_array;
        this->_size = ob.size();
        this->_array = new T[this->_size];
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = ob._array[i];
    }
    return *this;
}
template <typename T>
Array<T>::~Array() {
    delete [] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
    if (idx >= this->size())
        throw std::out_of_range("out of orange");
    return this->_array[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
    if (idx >= this->size())
        throw std::out_of_range("out of orange");
    return this->_array[idx];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->_size;
}
