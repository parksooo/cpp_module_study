/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:21:36 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 16:40:42 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP
# include <iostream>
# include <stdint.h>

// struct Data
// {
//     int n;
//     std::string s1;
//     std::string s2;
// };

// uintptr_t serialize(Data* ptr);
// Data* deserialize(uintptr_t raw);
class Data {
    private :
            int age;
            std::string name;
    public  :
            Data();
            Data(int age, std::string name);
            Data(const Data &ob);
            Data& operator=(const Data &ob);
            ~Data();
            int getAge() const;
            std::string getName() const;
};
std::ostream& operator<<(std::ostream& os, const Data &ob);
#endif