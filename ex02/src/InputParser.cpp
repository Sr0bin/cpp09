/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:00 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:08:53 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputParser.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <string>

const char	*InvalidInput::what() const throw()
{
	return ("Error");
}

static int	toPositiveInt(const std::string &token)
{
	for (std::string::size_type i = 0; i < token.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw InvalidInput();
	errno = 0;
	long	value = std::strtol(token.c_str(), NULL, 10);
	if (errno == ERANGE || value > INT_MAX || value == 0)
		throw InvalidInput();
	return (static_cast<int>(value));
}

std::vector<int>	parseInput(int argc, char **argv)
{
	std::vector<int>	values;

	if (argc < 2)
		throw InvalidInput();
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream	stream(argv[i]);
		std::string			token;
		bool				found = false;

		while (stream >> token)
		{
			values.push_back(toPositiveInt(token));
			found = true;
		}
		if (!found)
			throw InvalidInput();
	}
	return (values);
}
