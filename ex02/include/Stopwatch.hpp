/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stopwatch.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:58 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:58 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STOPWATCH_HPP
# define STOPWATCH_HPP
# include <ctime>

class Stopwatch
{
	public:
		Stopwatch();
		Stopwatch(const Stopwatch &other);
		Stopwatch &operator=(const Stopwatch &other);
		~Stopwatch();

		void	start();
		void	stop();
		double	microseconds() const;

	private:
		std::clock_t	_start;
		std::clock_t	_end;
};

#endif
