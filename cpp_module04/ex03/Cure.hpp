/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:31:07 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 16:10:08 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria{
	public	:
			Cure();
			~Cure();
			Cure(Cure const &ob);
			Cure& operator=(Cure const &ob);
			AMateria *clone() const;
};
#endif