/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortBench.tpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:59 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Core, typename Container>
SortBench<Core, Container>::SortBench()
	: _name(), _values(), _core(), _watch()
{
}

template <typename Core, typename Container>
SortBench<Core, Container>::SortBench(const std::string &name)
	: _name(name), _values(), _core(), _watch()
{
}

template <typename Core, typename Container>
SortBench<Core, Container>::SortBench(const SortBench &other)
	: _name(other._name), _values(other._values), _core(other._core),
	_watch(other._watch)
{
}

template <typename Core, typename Container>
SortBench<Core, Container> &SortBench<Core, Container>::operator=(
	const SortBench &other)
{
	if (this != &other)
	{
		_name = other._name;
		_values = other._values;
		_core = other._core;
		_watch = other._watch;
	}
	return (*this);
}

template <typename Core, typename Container>
SortBench<Core, Container>::~SortBench()
{
}

template <typename Core, typename Container>
void	SortBench<Core, Container>::run(const std::vector<int> &input)
{
	_watch.start();
	_values.assign(input.begin(), input.end());
	_core.sort(_values);
	_watch.stop();
}

template <typename Core, typename Container>
const Container	&SortBench<Core, Container>::result() const
{
	return (_values);
}

template <typename Core, typename Container>
const std::string	&SortBench<Core, Container>::name() const
{
	return (_name);
}

template <typename Core, typename Container>
double	SortBench<Core, Container>::microseconds() const
{
	return (_watch.microseconds());
}

template <typename Core, typename Container>
long	SortBench<Core, Container>::comparisons() const
{
	return (_core.comparisons());
}
