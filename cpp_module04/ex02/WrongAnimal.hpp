/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:53:49 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/12 16:21:55 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal{
	protected	:
				std::string type;
	public		:
				WrongAnimal();
				WrongAnimal(WrongAnimal const &ob);
				WrongAnimal& operator=(WrongAnimal const &ob);
				~WrongAnimal();
				void	makeSound() const;
				std::string	getType() const;
};
#endif