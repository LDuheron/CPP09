/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMergeMe_HPP
# define PMergeMe_HPP

# include <cstdlib>
# include <deque>
# include <iomanip>
# include <iostream>
# include <limits.h>
# include <string>
# include <sys/time.h>
# include <vector>

#define SUCCESS 0
#define ERROR 1

#define DEBUG 0

#define DEQUE 0
#define VECTOR 1

typedef std::vector<int> vector_t;
typedef std::deque<int> deque_t;

class ErrorTimeException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class WrongInputException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class PMergeMe
{
	private:
		deque_t				_deque;
		vector_t			_vector;

	public:
		PMergeMe();
		PMergeMe(PMergeMe const & src);
		~PMergeMe();

		PMergeMe &			operator=(PMergeMe const & rhs);

		deque_t const 		&getDeque(void) const;
		void				setDeque(deque_t deque);

		vector_t const 		&getVector(void) const;
		void				setVector(vector_t vector);

		void				checkInput(int argc, char **argv);
		void				fillDeque(int argc, char **argv);
		void				fillVector(int argc, char **argv);
		void				printBefore(void);
		void				printAfter(void);

		void				printTime(int containerType, double time);

		vector_t			cutAndSort(vector_t vector);
		vector_t			mergeSort(vector_t vectorOne, vector_t vectorTwo);

		deque_t				cutAndSort(deque_t deque);
		deque_t				mergeSort(deque_t dequeOne, deque_t dequeTwo);

};

double	getTime(void);

#endif
