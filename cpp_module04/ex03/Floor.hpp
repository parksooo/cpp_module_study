/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:44:20 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 19:47:11 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP
# include "AMateria.hpp"

class Floor {
	private	:
			AMateria *floor[4];
	public	:
			Floor();
			Floor(Floor const &ob);
			Floor &operator=(Floor const &ob);
			~Floor();
			AMateria *getMateria(int idx) const;
			void	setMateria(AMateria *m);
};
#endif