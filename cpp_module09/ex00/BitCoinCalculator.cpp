/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinCalculator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhwpark <suhwpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:39:11 by suhwpark          #+#    #+#             */
/*   Updated: 2023/09/15 17:25:30 by suhwpark         ###   ########.fr       */
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
	if (this != &ob) {
		this->dbData = ob.dbData;
	}
	return *this;
}

BitCoinCalculator::~BitCoinCalculator()
{
}

void BitCoinCalculator::letSomeTasteBitCoin(char *file)
{
	std::multimap<std::string, float> inputMap;
	
	try {
		checkCsvFile();
		calculateInputFile(file);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void BitCoinCalculator::checkCsvFile()
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
		_date = validateDbDate(read.substr(0, commaPos));
        _value = validateDbFloat(read.substr(commaPos + 1, read.length()));
        this->dbData.insert(std::make_pair(read.substr(0, commaPos), _value));
	}
}


std::string    BitCoinCalculator::validateDbDate(std::string _date)
{
	std::string split;
	std::istringstream ss(_date);
	int year, month, day;
	size_t idx = 0;
		
	if (_date.length() != 10)
		throw InvalidDate("Error : bad input");
	while(std::getline(ss, split, '-')) {
		if (idx == 0) {
			std::istringstream(split) >> year;
			if (year < 1000 || year > 9999)
				throw InvalidDate("Error : bad input");
		} else if (idx == 1) {
			std::istringstream(split) >> month;
			if (month < 1 || month > 12)
				throw InvalidDate("Error : bad input");
		} else if (idx == 2) {
			std::istringstream(split) >> day;
			if (day < 1 || day > 31)
				throw InvalidDate("Error : bad input");
			if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
				throw InvalidDate("Error : bad input");
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
				if (day > 29 && month == 2)
					throw InvalidDate("Error : bad input");
			} else if (day > 28 && month == 2)
				throw InvalidDate("Error : bad input");
		}
		idx++;
	}
	if (idx != 3)
		throw InvalidDate("Error : bad input");
	return _date;
}

float   BitCoinCalculator::validateDbFloat(std::string _value)
{
	char *remain = NULL;
	double value = std::strtod(_value.c_str(), &remain);
	
	if (value == 0.0 && !std::isdigit(_value[0]))
		throw InvalidValue("Error : bad input");
	if (*remain && std::strcmp(remain, "f"))
		throw InvalidValue("Error : Not float input");
	if (value < 0)
		throw InvalidValue("Error : not a positive number.");
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
				throw BitCoinCalculator::BadInputFileForm();
		}
		if (idx == 1) {
			if (split != "|")
				throw BitCoinCalculator::BadInputFileForm();
		}
		if (idx == 2) {
			if (split != "value")
				throw BitCoinCalculator::BadInputFileForm();
		}
		idx++;
	}
	if (idx != 3)
		throw BitCoinCalculator::BadInputFileForm();
}

std::pair<std::string, float>	BitCoinCalculator::filemakePairs(std::string read)
{
	std::istringstream ss(read);
	std::string split;
	std::pair<std::string, float> result;
	std::string _date;
	size_t		idx = 0;
	float		_value = 0.0;

	while (std::getline(ss, split, ' ')) {
		if (idx == 0) {
			try {
				_date = validateDbDate(split);
			} catch (std::exception &e) {
				std::string msg = e.what();
				return std::make_pair(msg + " => " + split, -FLT_MAX);
			}
		}
		if (idx == 1) {
			if (split != "|") {
				return std::make_pair("Error : Wrong Format.", -FLT_MAX);
			}
		}
		if (idx == 2) {
			try {
				_value = validateDbFloat(split);
				if (_value >= INT_MAX)
					return std::make_pair("Error : too large a number.", -FLT_MAX);
			} catch (std::exception &e) {
				return std::make_pair(e.what(), -FLT_MAX);
			}
		}
		idx++;
	}
	if (idx != 3)
		return std::make_pair("Error : Wrong Format.", -FLT_MAX);
	else
		result = std::make_pair(_date, _value);
	return result;
}

void BitCoinCalculator::calculateInputFile(char	*file)
{
    std::ifstream input(file);
	std::string read;

	if (!input)
		throw InvalidInputFile();
	std::getline(input, read);
	validateFirstLineInFile(read);
	while (std::getline(input, read)) {
		std::pair<std::string, float> pairs = filemakePairs(read);
		printMyBitCoin(pairs);	
	}
}

void	printPairSource(std::string _date, float _value, float _advantage)
{
	_value == static_cast<int>(_value) ? std::cout << _date << " => " << static_cast<int>(_value) << " = " << _advantage << std::endl
		: std::cout << _date << " => " << _value << " = " << _advantage << std::endl;
}

void BitCoinCalculator::printMyBitCoin(std::pair<std::string, float> pair)
{
	std::multimap<std::string, float>::iterator dbIter;
	float res = 0.0;

	if (pair.second == -FLT_MAX) {
		std::cout << pair.first << std::endl;
		return ;
	}
	dbIter = this->dbData.find(pair.first);
	if (dbIter != this->dbData.end()){
		res = dbIter->second * pair.second;	
	} else {
		dbIter = this->dbData.lower_bound(pair.first);			
		if (dbIter == this->dbData.begin()){
			std::cout << "Error : Wrong Date." << std::endl;
			return ;
		}
		--dbIter;
		res = dbIter->second * pair.second;
	}
	printPairSource(pair.first, pair.second, res);
}

const char *BitCoinCalculator::InvalidInputFile::what() const throw()
{
    return "Error: could not open file.";
}

const char *BitCoinCalculator::BadInputFileForm::what() const throw()
{
    return "Error: First line has Bad Form";
}
