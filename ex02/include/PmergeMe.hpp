/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:57 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:08:53 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <deque>
# include <vector>
# include "InputParser.hpp"
# include "Report.hpp"
# include "SortBench.hpp"
# include "VectorFordJohnson.hpp"
# include "DequeFordJohnson.hpp"

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv);

	private:
		SortBench<VectorFordJohnson, std::vector<int> >	_vectorBench;
		SortBench<DequeFordJohnson, std::deque<int> >	_dequeBench;
};

#endif
