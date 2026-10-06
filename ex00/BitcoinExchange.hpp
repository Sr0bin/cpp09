/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:29:22 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 14:56:09 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <map>
# include <string>

class BitcoinExchange
{
public:

	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	void	loadDatabase(const std::string &path);
	void	processInput(const std::string &path) const;

private:
	std::map<std::string, double>	_rates;

	void		processLine(const std::string &line) const;
	static bool	isValidDate(const std::string &date);
	static bool	parseNumber(const std::string &text, double &value);

};

#endif
