/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructor -----------------------------------------------------------------

RPN::RPN()
{
	if (DEBUG)
		std::cout << "RPN default constructor called.\n";
}

RPN::RPN(RPN const & src) : _stack(src._stack)
{
	if (DEBUG)
		std::cout << "RPN copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

RPN::~RPN()
{
	if (DEBUG)
		std::cout << "RPN destructor called.\n";
}

// Accessors -------------------------------------------------------------------

// std::string const &	RPN::getName(void) const
// {
// 	return (this->_name);
// }

// Exception -------------------------------------------------------------------
const char* WrongInputException::what() const throw()
{
	return ("rpn takes number <10 nb signs +-*/%");
}

// Overload --------------------------------------------------------------------

// RPN &	RPN::operator=(RPN const & rhs)
// {
// 	return *this;
// }

// std::ostream & operator<<(std::ostream & lhs, RPN const & rhs)
// {
// 	lhs << rhs.getName() << ", RPN grade " << rhs.getGrade() << ".\n";
// 	return lhs;
// }

// Functions -------------------------------------------------------------------

bool	RPN::isOperator(char c)
{
	if (c == '-' || c == '+' || c == '/' || c == '*' || c == '%')
		return (true);
	return (false);
}

// void	RPN::readAndCalculate(std::string input)
// {
// 	for (int i = 0; i < (int)input.size(); i++)
// 	{
// 		if (i = )
// 	}
// }

void	RPN::parseInput(std::string input)
{
	for (int i = 0; i < (int)input.size(); i++)
	{
		if (isdigit(input[i]) == 0 && isOperator(input[i]) == false && input[i] != ' ')
			throw(WrongInputException());
		if (isdigit(input[i]) != 0 && isdigit(input[i + 1]) != 0 && isdigit(input[i + 2]) != 0)
			throw(WrongInputException());
		if (isOperator(input[i]) && input[i + 1] && input[i + 1] != ' ')
			throw(WrongInputException());
		if (isdigit(input[i]) != 0 && input [i + 1] && !(isdigit(input[i + 1]) != 0 || input[i + 1] == ' '))
			throw(WrongInputException());
	}
}
