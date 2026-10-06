/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   KeyComparator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 11:35:57 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 11:35:57 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCOMPARATOR_HPP
# define KEYCOMPARATOR_HPP

class KeyComparator
{
	public:
		KeyComparator();
		KeyComparator(const KeyComparator &other);
		KeyComparator &operator=(const KeyComparator &other);
		~KeyComparator();

		bool	less(int a, int b);
		long	count() const;
		void	reset();

	private:
		long	_count;
};

#endif
