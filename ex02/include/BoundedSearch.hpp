/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoundedSearch.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:55 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:55:39 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOUNDEDSEARCH_HPP
# define BOUNDEDSEARCH_HPP
# include <cstddef>
# include "KeyComparator.hpp"

class BoundedSearch
{
	public:
		BoundedSearch();
		BoundedSearch(KeyComparator &cmp);
		BoundedSearch(const BoundedSearch &other);
		BoundedSearch &operator=(const BoundedSearch &other);
		~BoundedSearch();

		template <typename Chain, typename Elem>
		size_t	position(const Chain &chain, size_t limit, const Elem &x) const;

	private:
		KeyComparator	*_cmp;
};

# include "BoundedSearch.tpp"

#endif
