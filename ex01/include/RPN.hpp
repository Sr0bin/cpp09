/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorollin <rorollin@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:50:34 by rorollin          #+#    #+#             */
/*   Updated: 2026/10/06 14:50:34 by rorollin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include <exception>
# include <stack>
# include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		int	evaluate(const std::string &expression) const;

		class InvalidExpression : public std::exception
		{
			public:
				const char	*what() const throw();
		};

	private:
		void		applyOperator(std::stack<int> &operands, char op) const;
		int			compute(char op, int lhs, int rhs) const;
		static bool	isOperator(char c);
		static bool	multiplicationOverflows(int lhs, int rhs);
};

#endif
