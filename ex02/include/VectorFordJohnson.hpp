/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorFordJohnson.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:58 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORFORDJOHNSON_HPP
# define VECTORFORDJOHNSON_HPP
# include <vector>
# include "Element.hpp"
# include "KeyComparator.hpp"

class VectorFordJohnson
{
	public:
		VectorFordJohnson();
		VectorFordJohnson(const VectorFordJohnson &other);
		VectorFordJohnson &operator=(const VectorFordJohnson &other);
		~VectorFordJohnson();

		void	sort(std::vector<int> &values);
		long	comparisons() const;

	private:
		typedef Element<std::vector<int> >	Elem;
		typedef std::vector<Elem>			Elems;

		KeyComparator	_cmp;

		Elems	mergeInsert(const Elems &elems);
};

#endif
