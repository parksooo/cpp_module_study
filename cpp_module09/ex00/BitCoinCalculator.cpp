/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinCalculator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:39:11 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/14 22:17:35 by suhwpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinCalculator.hpp"

BitCoinCalculator::BitCoinCalculator()
{
}

BitCoinCalculator::BitCoinCalculator(const BitCoinCalculator &ob)
{
	*this = ob;
}

BitCoinCalculator &BitCoinCalculator::operator=(const BitCoinCalculator &ob)
{
    *this = ob;
	return *this;
}

BitCoinCalculator::~BitCoinCalculator()
{
}

void BitCoinCalculator::letSomeTasteBitCoin(char *file) const
{
	std::map<std::string, float> inputMap;
	try {
		checkCsvFile();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		inputMap = validateInputFile(file);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

}

// void	displaya(std::map<std::string, float> map) {
// 	for (std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++)
// 		std::cout << "Key : " << it->first << " | Value : " << it->second << "\n";
// }

void BitCoinCalculator::checkCsvFile() const
{
    std::ifstream	ifst("data.csv");
    std::string		read;
	size_t			commaPos;
	std::string		_date;
    float			_value;
	
	if (!ifst || std::getline(ifst, read).eof())
    {
        throw std::runtime_error("Date file can't use.");
    }
    while(std::getline(ifst, read)){
		if (read == "date,exchange_rate")
			continue;
        commaPos = read.find(',');
		_date = validateDate(read.substr(0, commaPos));
        _value = validateFloat(read.substr(commaPos + 1, read.length()));
        this->dbData.insert(std::pair<std::string, float>(read.substr(0, commaPos), _value));
	}
	displaya(this->dbData);
}


std::string    BitCoinCalculator::validateDbDate(std::string _date) const
{
	std::string split;
	std::istringstream ss(_date);
	int year, month, day;
	size_t idx = 0;
		
	if (_date.length() != 10)
		throw InvalidDate();
	while(std::getline(ss, split, '-')) {
		if (idx == 0) {
			std::istringstream(split) >> year;
			if (year < 1000 || year > 9999)
				throw InvalidDate();
		} else if (idx == 1) {
			std::istringstream(split) >> month;
			if (month < 1 || month > 12)
				throw InvalidDate();
		} else if (idx == 2) {
			std::istringstream(split) >> day;
			if (day < 1 || day > 31)
				throw InvalidDate();
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				throw InvalidDate();
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
				if (day > 29 && month == 2)
					throw InvalidDate();
			} else if (day > 28 && month == 2)
				throw InvalidDate();
		}
		idx++;
	}
	if (idx != 3)
		throw InvalidDate();
	return _date;
}

float   BitCoinCalculator::validateDbFloat(std::string _value) const
{
	char *remain = NULL;
	double value = std::strtod(_value.c_str(), &remain);
	
	if (value == 0.0 && !std::isdigit(_value[0]))
		throw InvalidValue();
	if (*remain && std::strcmp(remain, "f"))
		throw InvalidValue();
	if (value < 0)
		throw InvalidValue();
	return static_cast<float>(value);
}

void	validateFirstLineInFile(std::string _str)
{
	std::istringstream ss(_str);
	std::string split;
	size_t idx = 0;

	while (std::getline(ss, split, ' ')) {
		if (idx == 0) {
			if (split != "date")
				throw BadInputFileForm();
		}
		if (idx == 1) {
			if (split != "|")
				throw BadInputFileForm();
		}
		if (idx == 2) {
			if (split != "value")
				throw BadInputFileForm();
		}
		idx++;
	}
	if (idx != 3)
		throw BadInputFileForm();
}

std::pair<std::string, float>	BitCoinCalculator::filemakePairs(std::string read) const
{
	std::istringstream ss(read);
	std::string split;
	size_t		idx;
	std::pair<std::string, float> result;
	while (std::getline(ss, split, ' ')) {
		std::string _date;
		float		_value;
		if (idx == 0) {
			try {
				_date = validateDbDate(split);
			} catch (std::exception &e) {
				return std::pair<std::string, float>("Error : Wrong Date Format.", -FLT_MAX);
			}
		}
		if (idx == 1) {
			if (split != "|") {
				return std::pair<std::string, float>("Error : Wrong Delimiter Format.", -FLT_MAX);
			}
		}
		if (idx == 2) {
			try {
				_value = validateDbValue(split);
			} catch (std::exception &e) {
				return std::pair<std::string, float>("Error : Wrong Value Format.", -FLT_MAX);
			}
		}
		idx++;
		result = std::pair<std::string, float>(_date, _value);
	}
	if (idx != 3)
		return std::pair<std::string, float>("Error : Wrong Format.", -FLT_MAX);
	return result;
}

std::map<std::string, float> BitCoinCalculator::validateInputFile(char	*file)
{
    std::ifstream input(file);
	std::string read;
	std::map<std::string, float> result;

	if (!input)
		throw InvalidInputFile();
	std::getline(file, read);
	validateFirstLineInFile(read);
	while (std::getline(file, read)) {
		result.insert(filemakePairs(read));		
	}
	return result;
}

void	printPairSource(std::string _date, float _value, float _advantage)
{
	_value == static_cast<int>(_value) ? std::cout << _date << " => " << static_cast<int>(_value) << " = " << _advantage
		: std::cout << _date << " => " << _value << " = " << _advantage;
}

void BitCoinCalculator::printMyBitCoin(std::pair<std::string, float> inputMap) const
{
	std::map<std::string, float>::const_iterator dbIter;

	for(std::map<std::string, float>::iterator iter = inputMap.begin();
			iter != inputMap.end(); iter++) {
		float res;
		
		if (iter.second == -FLT_MAX) {
			std::cout << iter.first << std::endl;
		} else {
			dbIter = this->dbData.find(iter.first);
			if (dbIter == this->dbData.begin()){
				std::cout << "Error : Wrong Date." << std::endl;
				continue ;
			}
			--dbIter;
			res = (dbIter.second) * iter.second;
			printPairSource(iter.first, iter.second, res);
		}
	}
}

const char *BitCoinCalculator::InvalidDate::what() const throw()
{
    return "Invalided Date Form.";
}

const char *BitCoinCalculator::InvalidValue::what() const throw()
{
    return "Invalided Value Form.";
}

const char *BitCoinCalculator::InvalidInputFile::what() const throw()
{
    return "Error: could not open file.";
}

const char *BitCoinCalculator::BadInputFileForm::what() const throw()
{
    return "Error: First line has Bad Form";
}
