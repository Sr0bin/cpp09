/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Report.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:57 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPORT_HPP
# define REPORT_HPP
# include <cstddef>
# include <string>

class Report
{
	public:
		Report();
		Report(const Report &other);
		Report &operator=(const Report &other);
		~Report();

		template <typename C>
		void	sequence(const std::string &label, const C &values) const;
		void	timing(size_t count, const std::string &container,
					double microseconds) const;
};

# include "Report.tpp"

#endif
