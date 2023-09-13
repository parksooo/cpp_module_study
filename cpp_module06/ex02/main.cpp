/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:27:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/13 17:41:25 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <exception>

Base* generate(void)
{
    srand(time(NULL));
    switch (rand() % 3)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        default:
            return new C;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "Pointer A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "Pointer B" << std::endl;
    else if (dynamic_cast<C *>(p) != NULL)
        std::cout << "Pointer C" << std::endl;
}

void identify(Base &p)
{
    try {
        A &a = dynamic_cast<A &>(p);
        std::cout << "Reference A" << std::endl;
        static_cast<void>(a);
    } catch (std::exception &e){}
    try {
        B &b = dynamic_cast<B &>(p);
        std::cout << "Reference B" << std::endl;
        static_cast<void>(b);
    } catch (std::exception &e){}
    try {
        C &c = dynamic_cast<C &>(p);
        std::cout << "Reference C" << std::endl;
        static_cast<void>(c);
    } catch (std::exception &e){}
}

int main() {
    Base *p = generate();

    identify(*p);
    identify(p);

    delete p;
}