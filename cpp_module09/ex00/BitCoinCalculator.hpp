/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinCalculator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:29:34 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/15 17:19:10 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINCALCULATOR_HPP
# define BITCOINCALCULATOR_HPP
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cstdlib>
# include <cfloat>
# include <math.h>

class BitCoinCalculator {

    private :
            std::multimap<std::string, float> 			dbData;
            std::string								validateDbDate(std::string _date);
            float									validateDbFloat(std::string _value);
			std::multimap<std::string, float>			calculateInputFile(char *file);
            std::pair<std::string, float>	        filemakePairs(std::string read);
            void                                    checkCsvFile();
            void                                    printMyBitCoin(std::pair<std::string, float> pair);
    public  :
            BitCoinCalculator();
            BitCoinCalculator(const BitCoinCalculator &ob);
            BitCoinCalculator& operator=(const BitCoinCalculator &ob);
            ~BitCoinCalculator();
            class InvalidDate : public std::invalid_argument {
                public :
                        InvalidDate(const std::string &msg) : std::invalid_argument(msg) {}
            };
            class InvalidValue : public std::invalid_argument{
                public  :
                        InvalidValue(const std::string &msg) : std::invalid_argument(msg) {}
            };
            class InvalidInputFile : public std::exception {
                public  :
                        const char *what() const throw();
            };
            class BadInputFileForm : public std::exception {
                public  :
                        const char *what() const throw();
            };
            void    letSomeTasteBitCoin(char *file);
};
#endif