/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stopwatch.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:01 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:36:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stopwatch.hpp"

Stopwatch::Stopwatch() : _start(0), _end(0)
{
}

Stopwatch::Stopwatch(const Stopwatch &other)
	: _start(other._start), _end(other._end)
{
}

Stopwatch &Stopwatch::operator=(const Stopwatch &other)
{
	if (this != &other)
	{
		_start = other._start;
		_end = other._end;
	}
	return (*this);
}

Stopwatch::~Stopwatch()
{
}

void	Stopwatch::start()
{
	_start = std::clock();
}

void	Stopwatch::stop()
{
	_end = std::clock();
}

double	Stopwatch::microseconds() const
{
	return ((_end - _start) * 1000000.0 / CLOCKS_PER_SEC);
}
