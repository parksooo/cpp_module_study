/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:50:19 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/11 15:17:01 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
	public	:
			FragTrap();
			FragTrap(std::string name);
			FragTrap(FragTrap const &ob);
			FragTrap& operator=(FragTrap const &ob);
			~FragTrap();
			void	highFivesGuys();
};
#endif