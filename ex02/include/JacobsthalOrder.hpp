/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalOrder.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:56 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:55:39 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JACOBSTHALORDER_HPP
# define JACOBSTHALORDER_HPP
# include <cstddef>
# include <vector>

class JacobsthalOrder
{
	public:
		JacobsthalOrder();
		JacobsthalOrder(size_t count);
		JacobsthalOrder(const JacobsthalOrder &other);
		JacobsthalOrder &operator=(const JacobsthalOrder &other);
		~JacobsthalOrder();

		bool	next(size_t &k);

	private:
		std::vector<size_t>				_order;
		std::vector<size_t>::size_type	_index;
};

#endif
