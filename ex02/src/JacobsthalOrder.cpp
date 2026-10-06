/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalOrder.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:00 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:36:00 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JacobsthalOrder.hpp"
#include <algorithm>

JacobsthalOrder::JacobsthalOrder() : _order(), _index(0)
{
}

JacobsthalOrder::JacobsthalOrder(size_t count) : _order(), _index(0)
{
	size_t	prev = 1;
	size_t	cur = 1;
	size_t	low = 1;

	while (low < count)
	{
		size_t	following = cur + 2 * prev;
		prev = cur;
		cur = following;
		size_t	high = std::min(cur, count);
		for (size_t k = high; k > low; --k)
			_order.push_back(k);
		low = high;
	}
}

JacobsthalOrder::JacobsthalOrder(const JacobsthalOrder &other)
	: _order(other._order), _index(other._index)
{
}

JacobsthalOrder &JacobsthalOrder::operator=(const JacobsthalOrder &other)
{
	if (this != &other)
	{
		_order = other._order;
		_index = other._index;
	}
	return (*this);
}

JacobsthalOrder::~JacobsthalOrder()
{
}

bool	JacobsthalOrder::next(size_t &k)
{
	if (_index >= _order.size())
		return (false);
	k = _order[_index];
	++_index;
	return (true);
}
