/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorFordJohnson.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:01 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:48:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VectorFordJohnson.hpp"
#include "BoundedSearch.hpp"
#include "JacobsthalOrder.hpp"

VectorFordJohnson::VectorFordJohnson() : _cmp()
{
}

VectorFordJohnson::VectorFordJohnson(const VectorFordJohnson &other)
	: _cmp(other._cmp)
{
}

VectorFordJohnson &VectorFordJohnson::operator=(const VectorFordJohnson &other)
{
	if (this != &other)
		_cmp = other._cmp;
	return (*this);
}

VectorFordJohnson::~VectorFordJohnson()
{
}

long	VectorFordJohnson::comparisons() const
{
	return (_cmp.count());
}

void	VectorFordJohnson::sort(std::vector<int> &values)
{
	Elems	elems;

	_cmp.reset();
	elems.reserve(values.size());
	for (std::vector<int>::size_type i = 0; i < values.size(); ++i)
		elems.push_back(Elem(values[i]));
	Elems	sorted = mergeInsert(elems);
	values.clear();
	for (Elems::size_type i = 0; i < sorted.size(); ++i)
		sorted[i].unpackTo(values);
}

VectorFordJohnson::Elems	VectorFordJohnson::mergeInsert(const Elems &elems)
{
	if (elems.size() <= 1)
		return (elems);

	Elems	winners;
	winners.reserve(elems.size() / 2);
	for (Elems::size_type i = 0; i + 1 < elems.size(); i += 2)
	{
		if (_cmp.less(elems[i + 1].key(), elems[i].key()))
			winners.push_back(Elem::absorb(elems[i], elems[i + 1]));
		else
			winners.push_back(Elem::absorb(elems[i + 1], elems[i]));
	}

	Elems	sorted = mergeInsert(winners);

	Elems							chain;
	Elems							pend;
	std::vector<Elems::size_type>	limits;
	chain.reserve(elems.size());
	pend.reserve(sorted.size());
	limits.reserve(sorted.size());
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
		Elems::size_type	i = order[n] - 2;
		Elems::size_type	pos = search.position(chain, limits[i], pend[i]);
		chain.insert(chain.begin() + static_cast<Elems::difference_type>(pos),
			pend[i]);
		for (std::vector<Elems::size_type>::size_type j = 0; j < limits.size(); ++j)
			if (limits[j] >= pos)
				++limits[j];
	}
	return (chain);
}
