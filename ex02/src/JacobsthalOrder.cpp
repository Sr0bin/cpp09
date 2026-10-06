/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   JacobsthalOrder.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:00 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:13:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "JacobsthalOrder.hpp"
#include <algorithm>

std::vector<size_t>	jacobsthalOrder(size_t count)
{
	std::vector<size_t>	order;
	size_t				prev = 1;
	size_t				cur = 1;
	size_t				low = 1;

	while (low < count)
	{
		size_t	following = cur + 2 * prev;
		prev = cur;
		cur = following;
		size_t	high = std::min(cur, count);
		for (size_t k = high; k > low; --k)
			order.push_back(k);
		low = high;
	}
	return (order);
}
