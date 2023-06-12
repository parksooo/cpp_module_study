/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:23:06 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 19:26:31 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal{
	private	:
			Brain *brain;
	public	:
			Cat();
			Cat(Cat const &ob);
			Cat& operator=(Cat const &ob);
			~Cat();
			void	makeSound() const;
			Brain*	getBrain() const;
};
#endif