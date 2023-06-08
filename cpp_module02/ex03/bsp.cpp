/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:29:32 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/08 17:47:59 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

int calculate(Point const a, Point const b, Point const c)
{
	int res = std::abs((a.getX().getRawBits() * (b.getY().getRawBits() - c.getY().getRawBits())) + 
			(b.getX().getRawBits() * (c.getY().getRawBits() - a.getY().getRawBits())) + 
			(c.getX().getRawBits() * (a.getY().getRawBits() + b.getY().getRawBits())));

	return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int n = calculate(a, b, c);
	int aa = calculate(point, b, c);
	int bb = calculate(a, point, c);
	int cc = calculate(a, b, point);

	return (n == aa + bb + cc);
}