/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParser.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:56 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTPARSER_HPP
# define INPUTPARSER_HPP
# include <exception>
# include <string>
# include <vector>

class InputParser
{
	public:
		InputParser();
		InputParser(const InputParser &other);
		InputParser &operator=(const InputParser &other);
		~InputParser();

		std::vector<int>	parse(int argc, char **argv) const;

		class InvalidInput : public std::exception
		{
			public:
				const char	*what() const throw();
		};

	private:
		int	toPositiveInt(const std::string &token) const;
};

#endif
