/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:01 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:08:53 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#ifdef DEBUG
# include <algorithm>
# include <iostream>
#endif

PmergeMe::PmergeMe()
	: _vectorBench("std::vector"), _dequeBench("std::deque")
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
	: _vectorBench(other._vectorBench), _dequeBench(other._dequeBench)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
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
	std::vector<int>	input = parseInput(argc, argv);

	printSequence("Before:", input);
	_vectorBench.run(input);
	_dequeBench.run(input);
	printSequence("After:", _vectorBench.result());
	printTiming(input.size(), _vectorBench.name(), _vectorBench.microseconds());
	printTiming(input.size(), _dequeBench.name(), _dequeBench.microseconds());
#ifdef DEBUG
	const std::vector<int>	&v = _vectorBench.result();
	const std::deque<int>	&d = _dequeBench.result();
	bool	same = v.size() == d.size() && std::equal(v.begin(), v.end(), d.begin());
	std::cerr << "comparisons vector=" << _vectorBench.comparisons()
		<< " deque=" << _dequeBench.comparisons()
		<< " same_result=" << same << std::endl;
#endif
}
