/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

// Constructor -----------------------------------------------------------------

PMergeMe::PMergeMe()
{
	if (DEBUG)
		std::cout << "PMergeMe default constructor called.\n";
}

// PMergeMe::PMergeMe(PMergeMe const & src)
// {
// 	if (DEBUG)
// 		std::cout << "PMergeMe constructor called.\n";
// }

// Destructor ------------------------------------------------------------------

PMergeMe::~PMergeMe()
{
	if (DEBUG)
		std::cout << "Destructor called.\n";
}

// Accessors -------------------------------------------------------------------

// std::string const &	PMergeMe::getName(void) const
// {
// 	return (this->_name);
// }

// Exception -------------------------------------------------------------------

// const char* DuplicateNumbersException::what() const throw()
// {
// 	return ("cannot divide by zero");
// }

const char* WrongInputException::what() const throw()
{
	return ("please enter unsigned ints only");
}

// Overload --------------------------------------------------------------------

// PMergeMe &	PMergeMe::operator=(PMergeMe const & rhs)
// {
// 	this->_grade = rhs._grade;
// 	return *this;
// }

std::ostream & operator<<(std::ostream & lhs, PMergeMe const & rhs)
{
	// lhs << rhs.getName() << ", PMergeMe grade " << rhs.getGrade() << ".\n";
	(void) rhs;
	return lhs;
}

// Functions -------------------------------------------------------------------

void	PMergeMe::checkInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string input = argv[i];
		for (int j = 0; j < (int)input.size(); j++)
		{
			if (isdigit(input[j]) == 0)
				throw(WrongInputException());
		}
		double dbl = atof(argv[i]);
		if (dbl < 0 || dbl > __INT_MAX__)
			throw(WrongInputException());
		std::cout << dbl << std::endl;
	}
}
