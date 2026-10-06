/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortBench.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:57 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:55:39 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTBENCH_HPP
# define SORTBENCH_HPP
# include <string>
# include <vector>
# include "Stopwatch.hpp"

template <typename Core, typename Container>
class SortBench
{
	public:
		SortBench();
		SortBench(const std::string &name);
		SortBench(const SortBench &other);
		SortBench &operator=(const SortBench &other);
		~SortBench();

		void				run(const std::vector<int> &input);
		const Container		&result() const;
		const std::string	&name() const;
		double				microseconds() const;
		long				comparisons() const;

	private:
		std::string	_name;
		Container	_values;
		Core		_core;
		Stopwatch	_watch;
};

# include "SortBench.tpp"

#endif
