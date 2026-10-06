/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeFordJohnson.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:59 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:13:02 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DequeFordJohnson.hpp"
#include "BoundedSearch.hpp"
#include "JacobsthalOrder.hpp"

DequeFordJohnson::DequeFordJohnson() : _cmp()
{
}

DequeFordJohnson::DequeFordJohnson(const DequeFordJohnson &other)
	: _cmp(other._cmp)
{
}

DequeFordJohnson &DequeFordJohnson::operator=(const DequeFordJohnson &other)
{
	if (this != &other)
		_cmp = other._cmp;
	return (*this);
}

DequeFordJohnson::~DequeFordJohnson()
{
}

long	DequeFordJohnson::comparisons() const
{
	return (_cmp.count());
}

void	DequeFordJohnson::sort(std::deque<int> &values)
{
	Elems	elems;

	_cmp.reset();
	for (std::deque<int>::size_type i = 0; i < values.size(); ++i)
		elems.push_back(Elem(values[i]));
	Elems	sorted = mergeInsert(elems);
	values.clear();
	for (Elems::size_type i = 0; i < sorted.size(); ++i)
		sorted[i].unpackTo(values);
}

DequeFordJohnson::Elems	DequeFordJohnson::mergeInsert(const Elems &elems)
{
	if (elems.size() <= 1)
		return (elems);

	Elems	winners;
	for (Elems::size_type i = 0; i + 1 < elems.size(); i += 2)
	{
		if (_cmp.less(elems[i + 1].key(), elems[i].key()))
			winners.push_back(Elem::absorb(elems[i], elems[i + 1]));
		else
			winners.push_back(Elem::absorb(elems[i + 1], elems[i]));
	}

	Elems	sorted = mergeInsert(winners);

	Elems				chain;
	Elems				pend;
	std::deque<size_t>	limits;
	for (Elems::size_type i = 0; i < sorted.size(); ++i)
	{
		Elem	b;
		Elem	a;
		sorted[i].release(b, a);
		if (i == 0)
			chain.push_back(b);
		else
		{
			pend.push_back(b);
			limits.push_back(chain.size());
		}
		chain.push_back(a);
	}
	if (elems.size() % 2 != 0)
	{
		pend.push_back(elems.back());
		limits.push_back(chain.size());
	}

	BoundedSearch		search(_cmp);
	std::vector<size_t>	order = jacobsthalOrder(pend.size() + 1);
	for (std::vector<size_t>::size_type n = 0; n < order.size(); ++n)
	{
		size_t	i = order[n] - 2;
		size_t	pos = search.position(chain, limits[i], pend[i]);
		chain.insert(chain.begin() + pos, pend[i]);

		for (std::deque<size_t>::size_type j = 0; j < limits.size(); ++j)
			if (limits[j] >= pos)
				++limits[j];
	}
	return (chain);
}
