/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Report.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:36:01 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 15:08:52 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Report.hpp"
#include <iomanip>
#include <iostream>

void	printTiming(size_t count, const std::string &container,
	double microseconds)
{
	std::cout << "Time to process a range of " << count << " elements with "
		<< container << " : " << std::fixed << std::setprecision(5)
		<< microseconds << " us" << std::endl;
}
