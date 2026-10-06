/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Element.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:58 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename C>
Element<C>::Element() : _values()
{
}

template <typename C>
Element<C>::Element(int value) : _values()
{
	_values.push_back(value);
}

template <typename C>
Element<C>::Element(const Element &other) : _values(other._values)
{
}

template <typename C>
Element<C> &Element<C>::operator=(const Element &other)
{
	if (this != &other)
		_values = other._values;
	return (*this);
}

template <typename C>
Element<C>::~Element()
{
}

template <typename C>
int	Element<C>::key() const
{
	return (_values.back());
}

template <typename C>
size_t	Element<C>::size() const
{
	return (_values.size());
}

template <typename C>
Element<C>	Element<C>::absorb(const Element &winner, const Element &loser)
{
	Element	result(loser);

	result._values.insert(result._values.end(),
		winner._values.begin(), winner._values.end());
	return (result);
}

template <typename C>
void	Element<C>::release(Element &loser, Element &winner) const
{
	size_t	half = _values.size() / 2;

	loser._values.assign(_values.begin(), _values.begin() + half);
	winner._values.assign(_values.begin() + half, _values.end());
}

template <typename C>
void	Element<C>::unpackTo(C &out) const
{
	out.insert(out.end(), _values.begin(), _values.end());
}
