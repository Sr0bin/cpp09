/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoundedSearch.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:58 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:48:12 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Chain, typename Elem>
typename Chain::size_type	BoundedSearch::position(const Chain &chain,
	typename Chain::size_type limit, const Elem &x) const
{
	typename Chain::size_type	lo = 0;
	typename Chain::size_type	hi = limit;

	while (lo < hi)
	{
		typename Chain::size_type	mid = lo + (hi - lo) / 2;
		if (_cmp->less(x.key(), chain[mid].key()))
			hi = mid;
		else
			lo = mid + 1;
	}
	return (lo);
}
