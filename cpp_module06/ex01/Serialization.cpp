/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:25:21 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 16:43:58 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Data::Data()
{
}

Data::Data(int age, std::string name) : age(age), name(name)
{
}

Data::Data(const Data &ob) : age(ob.age), name(ob.name)
{
}

Data &Data::operator=(const Data &ob)
{
    if (this != &ob) {
        this->age = ob.age;
        this->name = ob.name;
    }
    return *this;
}

Data::~Data()
{
}

int Data::getAge() const
{
    return this->age;
}

std::string Data::getName() const
{
    return this->name;
}

std::ostream &operator<<(std::ostream &os, const Data &ob)
{
    os << "AGE : " << ob.getAge() << ", NAME : " << ob.getName() << std::endl;
    return os;
}
