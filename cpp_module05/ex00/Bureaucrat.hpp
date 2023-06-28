/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:28:58 by suhwpark          #+#    #+#             */
/*   Updated: 2023/06/28 19:44:07 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>

class Bureaucrat {
	private	:
			const std::string name;
			int	grade;
	public	:
			std::string const &getName() const;
			int	const getGrade() const;
			const char * what() const noexcept override {
				return ""
			}

};
#endif