/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:56 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:55:39 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_HPP
# define ELEMENT_HPP
# include <cstddef>

template <typename C>
class Element
{
	public:
		Element();
		Element(int value);
		Element(const Element &other);
		Element &operator=(const Element &other);
		~Element();

		int				key() const;
		size_t			size() const;

		static Element	absorb(const Element &winner, const Element &loser);
		void			release(Element &loser, Element &winner) const;
		void			unpackTo(C &out) const;

	private:
		C	_values;
};

# include "Element.tpp"

#endif
