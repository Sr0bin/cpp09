/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:01 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:36:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#ifdef DEBUG
# include <algorithm>
# include <iostream>
#endif

PmergeMe::PmergeMe()
	: _parser(), _report(), _vectorBench("std::vector"),
	_dequeBench("std::deque")
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _parser(other._parser), _report(other._report),
	_vectorBench(other._vectorBench), _dequeBench(other._dequeBench)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_parser = other._parser;
		_report = other._report;
		_vectorBench = other._vectorBench;
		_dequeBench = other._dequeBench;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::run(int argc, char **argv)
{
	std::vector<int>	input = _parser.parse(argc, argv);

	_report.sequence("Before:", input);
	_vectorBench.run(input);
	_dequeBench.run(input);
	_report.sequence("After:", _vectorBench.result());
	_report.timing(input.size(), _vectorBench.name(), _vectorBench.microseconds());
	_report.timing(input.size(), _dequeBench.name(), _dequeBench.microseconds());
#ifdef DEBUG
	const std::vector<int>	&v = _vectorBench.result();
	const std::deque<int>	&d = _dequeBench.result();
	bool	same = v.size() == d.size() && std::equal(v.begin(), v.end(), d.begin());
	std::cerr << "comparisons vector=" << _vectorBench.comparisons()
		<< " deque=" << _dequeBench.comparisons()
		<< " same_result=" << same << std::endl;
#endif
}
