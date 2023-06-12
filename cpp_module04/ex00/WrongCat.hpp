/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:24:04 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 19:11:53 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public	:
			WrongCat();
			WrongCat(WrongCat const &ob);
			WrongCat& operator=(WrongCat const &ob);
			~WrongCat();
			void	makeSound() const;
};
#endif