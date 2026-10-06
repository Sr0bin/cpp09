/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Report.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:57 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:08:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_HPP
# define REPORT_HPP
# include <cstddef>
# include <string>

template <typename C>
void	printSequence(const std::string &label, const C &values);
void	printTiming(size_t count, const std::string &container,
			double microseconds);

# include "Report.tpp"

#endif
