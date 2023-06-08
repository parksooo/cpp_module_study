/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:52:52 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/08 15:20:52 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point{
	private	:
			Fixed const x;
			Fixed const y;
	public :
			Point();
			Point(float const x, float const y);
			Point(const Point &p);
			~Point();
			Point& operator=(const Point& p);
			Fixed getX() const;
			Fixed getY() const;
};
bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif