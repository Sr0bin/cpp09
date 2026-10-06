/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParser.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:00 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:36:00 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputParser.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <sstream>

InputParser::InputParser()
{
}

InputParser::InputParser(const InputParser &other)
{
	(void)other;
}

InputParser &InputParser::operator=(const InputParser &other)
{
	(void)other;
	return (*this);
}

InputParser::~InputParser()
{
}

const char	*InputParser::InvalidInput::what() const throw()
{
	return ("Error");
}

std::vector<int>	InputParser::parse(int argc, char **argv) const
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

int	InputParser::toPositiveInt(const std::string &token) const
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
