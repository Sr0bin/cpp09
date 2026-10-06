/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:29:20 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 14:56:10 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _rates(other._rates)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
}

void	BitcoinExchange::loadDatabase(const std::string &path)
{
	std::ifstream	file(path.c_str());
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	if (!std::getline(file, line) || line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid database header.");
	while (std::getline(file, line))
	{
		std::string::size_type	comma = line.find(',');
		double					rate;

		if (comma == std::string::npos
			|| !isValidDate(line.substr(0, comma))
			|| !parseNumber(line.substr(comma + 1), rate)
			|| rate < 0)
			throw std::runtime_error("Error: invalid database line => " + line);
		_rates[line.substr(0, comma)] = rate;
	}
	if (_rates.empty())
		throw std::runtime_error("Error: empty database.");
}

void	BitcoinExchange::processInput(const std::string &path) const
{
	std::ifstream	file(path.c_str());
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (!std::getline(file, line))
		return ;
	if (line != "date | value")
		processLine(line);
	while (std::getline(file, line))
		processLine(line);
}

void	BitcoinExchange::processLine(const std::string &line) const
{
	std::string::size_type	separator = line.find(" | ");
	double					value;

	if (separator == std::string::npos)
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::string	date = line.substr(0, separator);
	if (!isValidDate(date) || !parseNumber(line.substr(separator + 3), value))
	{
		std::cerr << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (value < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}
	std::map<std::string, double>::const_iterator	it = _rates.upper_bound(date);
	if (it == _rates.begin())
	{
		std::cerr << "Error: no exchange rate before => " << date << std::endl;
		return ;
	}
	--it;
	std::cout << date << " => " << value << " = " << value * it->second
		<< std::endl;
}

bool	BitcoinExchange::isValidDate(const std::string &date)
{
	static const int	daysInMonth[12]
		= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (std::string::size_type i = 0; i < date.size(); ++i)
		if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1)
		return (false);
	bool	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	int		maxDay = daysInMonth[month - 1];
	if (month == 2 && leap)
		maxDay = 29;
	return (day <= maxDay);
}

bool	BitcoinExchange::parseNumber(const std::string &text, double &value)
{
	std::string::size_type	i = 0;
	std::string::size_type	digits = 0;
	bool					dot = false;

	if (i < text.size() && text[i] == '-')
		++i;
	for (; i < text.size(); ++i)
	{
		if (std::isdigit(static_cast<unsigned char>(text[i])))
			++digits;
		else if (text[i] == '.' && !dot)
			dot = true;
		else
			return (false);
	}
	if (digits == 0)
		return (false);
	value = std::strtod(text.c_str(), NULL);
	return (true);
}
