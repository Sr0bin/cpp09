/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeFordJohnson.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:56 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:56 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUEFORDJOHNSON_HPP
# define DEQUEFORDJOHNSON_HPP
# include <deque>
# include "Element.hpp"
# include "KeyComparator.hpp"

class DequeFordJohnson
{
	public:
		DequeFordJohnson();
		DequeFordJohnson(const DequeFordJohnson &other);
		DequeFordJohnson &operator=(const DequeFordJohnson &other);
		~DequeFordJohnson();

		void	sort(std::deque<int> &values);
		long	comparisons() const;

	private:
		typedef Element<std::deque<int> >	Elem;
		typedef std::deque<Elem>			Elems;

		KeyComparator	_cmp;

		Elems	mergeInsert(const Elems &elems);
};

#endif
