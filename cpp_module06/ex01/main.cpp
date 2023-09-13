/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 16:49:54 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main() {
    Data *data1;
    Data *data2;

    uintptr_t raw;

    data1 = new Data(28, "suhwpark");

    std::cout << "Data1 : " << *data1;
    raw = serialize(data1);
    std::cout << "raw : " << raw << std::endl;
    data2 = deserialize(raw);
    std::cout << "Data2 : " << *data2;

    delete data1;
}