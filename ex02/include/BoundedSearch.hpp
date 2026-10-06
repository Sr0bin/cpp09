/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoundedSearch.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:55 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:48:12 by rorollin         ###   ########.fr       */
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
		typename Chain::size_type	position(const Chain &chain,
			typename Chain::size_type limit, const Elem &x) const;

	private:
		KeyComparator	*_cmp;
};

# include "BoundedSearch.tpp"

#endif
