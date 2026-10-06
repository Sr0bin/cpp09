/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Report.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:59 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:59 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename C>
void	Report::sequence(const std::string &label, const C &values) const
{
	std::cout << label;
	for (typename C::const_iterator it = values.begin(); it != values.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
}
