/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoundedSearch.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:59 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BoundedSearch.hpp"
#include <cstddef>

BoundedSearch::BoundedSearch() : _cmp(NULL)
{
}

BoundedSearch::BoundedSearch(KeyComparator &cmp) : _cmp(&cmp)
{
}

BoundedSearch::BoundedSearch(const BoundedSearch &other) : _cmp(other._cmp)
{
}

BoundedSearch &BoundedSearch::operator=(const BoundedSearch &other)
{
	if (this != &other)
		_cmp = other._cmp;
	return (*this);
}

BoundedSearch::~BoundedSearch()
{
}
