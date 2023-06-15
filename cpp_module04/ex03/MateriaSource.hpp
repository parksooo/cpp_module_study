/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:35:59 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/14 18:53:24 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private	:
			AMateria *slot[4];
	public	:
			MateriaSource();
			MateriaSource(MateriaSource const &ob);
			MateriaSource &operator=(MateriaSource const &ob);
			~MateriaSource();
			void learnMateria(AMateria *m);
			AMateria* createMateria(std::string const & type);
};
#endif