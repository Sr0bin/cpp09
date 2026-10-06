/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyComparator.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:00 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:36:00 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "KeyComparator.hpp"

KeyComparator::KeyComparator() : _count(0)
{
}

KeyComparator::KeyComparator(const KeyComparator &other) : _count(other._count)
{
}

KeyComparator &KeyComparator::operator=(const KeyComparator &other)
{
	if (this != &other)
		_count = other._count;
	return (*this);
}

KeyComparator::~KeyComparator()
{
}

bool	KeyComparator::less(int a, int b)
{
	++_count;
	return (a < b);
}

long	KeyComparator::count() const
{
	return (_count);
}

void	KeyComparator::reset()
{
	_count = 0;
}
