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

PMergeMe::PMergeMe(PMergeMe const & src) : _deque(src._deque), _vector(src._vector)
{
	if (DEBUG)
		std::cout << "PMergeMe constructor called.\n";
}

// Destructor ------------------------------------------------------------------

PMergeMe::~PMergeMe()
{
	if (DEBUG)
		std::cout << "Destructor called.\n";
}

// Accessors -------------------------------------------------------------------

deque_t const &	PMergeMe::getDeque(void) const
{
	return (this->_deque);
}

void	PMergeMe::setDeque(deque_t deque)
{
	this->_deque = deque;
}

vector_t const &	PMergeMe::getVector(void) const
{
	return (this->_vector);
}

void	PMergeMe::setVector(vector_t vector)
{
	this->_vector = vector;
}

// Exception -------------------------------------------------------------------

const char* ErrorTimeException::what() const throw()
{
	return ("an error occured using gettimeoftheday()");
}

const char* WrongInputException::what() const throw()
{
	return ("please enter unsigned ints only");
}

// Overload --------------------------------------------------------------------

PMergeMe &	PMergeMe::operator=(PMergeMe const & rhs)
{
	this->_deque = rhs._deque;
	this->_vector = rhs._vector;
	return *this;
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
	}
}

void	PMergeMe::fillDeque(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		this->_deque.push_back(atoi(argv[i]));
}

void	PMergeMe::fillVector(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		this->_vector.push_back(atoi(argv[i]));
}

void	PMergeMe::printBefore(void)
{
	std::cout << "Before: ";
	for (int i = 0; i < (int)this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
}

void	PMergeMe::printAfter(void)
{
	std::cout << "After: ";
	for (int i = 0; i < (int)this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
}

deque_t	PMergeMe::cutAndSort(deque_t deque)
{
	deque_t	dequeOne;
	deque_t	dequeTwo;
	if (deque.size() < 2)
		return (deque);
	for (int i = 0; i < (int)(deque.size() / 2); i++)
		dequeOne.push_back(deque[i]);
	for (int i = (int)(deque.size() / 2); i < (int)deque.size(); i++)
		dequeTwo.push_back(deque[i]);

	dequeOne = cutAndSort(dequeOne);
	dequeTwo = cutAndSort(dequeTwo);

	return (mergeSort(dequeOne,dequeTwo));
}

vector_t	PMergeMe::cutAndSort(vector_t vector)
{
	vector_t	vectorOne;
	vector_t	vectorTwo;
	if (vector.size() < 2)
		return (vector);
	for (int i = 0; i < (int)(vector.size() / 2); i++)
		vectorOne.push_back(vector[i]);
	for (int i = (int)(vector.size() / 2); i < (int)vector.size(); i++)
		vectorTwo.push_back(vector[i]);

	vectorOne = cutAndSort(vectorOne);
	vectorTwo = cutAndSort(vectorTwo);

	return (mergeSort(vectorOne,vectorTwo));
}

deque_t	PMergeMe::mergeSort(deque_t dequeOne, deque_t dequeTwo)
{
	deque_t	dequeThree;

	while (dequeOne.empty() != true && dequeTwo.empty() != true)
	{
		if (dequeOne[0] < dequeTwo[0])
		{
			dequeThree.push_back(dequeOne[0]);
			dequeOne.erase(dequeOne.begin());
		}
		else
		{
			dequeThree.push_back(dequeTwo[0]);
			dequeTwo.erase(dequeTwo.begin());
		}
	}
	
	while (dequeOne.empty() != true)
	{
		dequeThree.push_back(dequeOne[0]);
		dequeOne.erase(dequeOne.begin());
	}

	while (dequeTwo.empty() != true)
	{
			dequeThree.push_back(dequeTwo[0]);
			dequeTwo.erase(dequeTwo.begin());
	}

	return (dequeThree);
}

vector_t	PMergeMe::mergeSort(vector_t vectorOne, vector_t vectorTwo)
{
	vector_t	vectorThree;

	while (vectorOne.empty() != true && vectorTwo.empty() != true)
	{
		if (vectorOne[0] < vectorTwo[0])
		{
			vectorThree.push_back(vectorOne[0]);
			vectorOne.erase(vectorOne.begin());
		}
		else
		{
			vectorThree.push_back(vectorTwo[0]);
			vectorTwo.erase(vectorTwo.begin());
		}
	}
	
	while (vectorOne.empty() != true)
	{
		vectorThree.push_back(vectorOne[0]);
		vectorOne.erase(vectorOne.begin());
	}

	while (vectorTwo.empty() != true)
	{
			vectorThree.push_back(vectorTwo[0]);
			vectorTwo.erase(vectorTwo.begin());
	}

	return (vectorThree);
}

double	getTime(void)
{
	struct timeval	tv;
	double			milisecondes;
	double			secondes;
	double			time;

	if (gettimeofday(&tv, NULL) == -1)
		throw(ErrorTimeException());
	milisecondes = (double)tv.tv_usec / 1000;
	secondes = (double)tv.tv_sec * 0.001;
	time = secondes + milisecondes;
	return (time);
}

void	PMergeMe::printTime(int containerType, double time)
{
	std::string container = "deque";
	if (containerType == VECTOR)
		container = "vector";
	std::cout << "Time to process elements with std::" << container << " : " << std::fixed << std::setprecision(4) << time << "ms.\n";
}
