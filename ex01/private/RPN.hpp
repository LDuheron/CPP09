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

#define SUCCESS 0
#define ERROR 1

# define DEBUG 0

class DivisionByZeroException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class TooMuchNumbersException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class NotEnoughNumbersException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class WrongInputException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class RPN
{
	private:
		int				_result;
		std::stack<int> _stack;

	public:
		RPN();
		RPN(RPN const & src);
		~RPN();

		RPN &					operator=(RPN const & rhs);

		int const				&getResult(void) const;

		void					doOperation(char op, int firstNB, int secondNb);
		bool					isOperator(char c);
		void					parseInput(std::string input);
		void					readAndCalculate(std::string input);

};

#endif
