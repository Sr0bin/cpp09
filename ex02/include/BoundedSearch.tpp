/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BoundedSearch.tpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:58 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Chain, typename Elem>
size_t	BoundedSearch::position(const Chain &chain, size_t limit,
	const Elem &x) const
{
	size_t	lo = 0;
	size_t	hi = limit;

	while (lo < hi)
	{
		size_t	mid = lo + (hi - lo) / 2;
		if (_cmp->less(x.key(), chain[mid].key()))
			hi = mid;
		else
			lo = mid + 1;
	}
	return (lo);
}
