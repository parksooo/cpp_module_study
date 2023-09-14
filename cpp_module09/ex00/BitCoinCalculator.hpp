/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinCalculator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:29:34 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/14 22:17:40 by suhwpark         ###   ########.fr       */
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

class BitCoinCalculator {

    private :
            std::map<std::string, float> 			dbData;
            std::string								validateDbDate(std::string _date);
            float									validateDbFloat(std::string _value);
			std::map<std::string, float>			validateInputFile(char *file);
            std::pair<std::string, float>	        filemakePairs(std::string read);
            void                                    checkCsvFile();
            void                                    printMyBitCoin(std::map<std::string, float> inputMap);
    public  :
            BitCoinCalculator();
            BitCoinCalculator(const BitCoinCalculator &ob);
            BitCoinCalculator& operator=(const BitCoinCalculator &ob);
            ~BitCoinCalculator();
            class InvalidDate : public std::exception {
                public :
                        const char *what() const throw();
            };
            class InvalidValue : public std::exception {
                public  :
                        const char *what() const throw();
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