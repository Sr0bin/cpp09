/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputParser.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:56 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:08:53 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTPARSER_HPP
# define INPUTPARSER_HPP
# include <exception>
# include <vector>

class InvalidInput : public std::exception
{
	public:
		const char	*what() const throw();
};

std::vector<int>	parseInput(int argc, char **argv);

#endif
