/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

// penser aux overflowSSSS

#define SUCCESS 0
#define ERROR 1

# define DEBUG 0

class WrongInputException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(RPN const & src);
		~RPN();

		// RPN &	operator=(RPN const & rhs);
	
		// std::string const 		&getName(void) const;

		bool					isOperator(char c);
		void					parseInput(std::string input);


};

// std::ostream & operator<<(std::ostream & lhs, RPN const & rhs);

#endif
