/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Report.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:01 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:36:01 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Report.hpp"
#include <iomanip>
#include <iostream>

Report::Report()
{
}

Report::Report(const Report &other)
{
	(void)other;
}

Report &Report::operator=(const Report &other)
{
	(void)other;
	return (*this);
}

Report::~Report()
{
}

void	Report::timing(size_t count, const std::string &container,
	double microseconds) const
{
	std::cout << "Time to process a range of " << count << " elements with "
		<< container << " : " << std::fixed << std::setprecision(5)
		<< microseconds << " us" << std::endl;
}
