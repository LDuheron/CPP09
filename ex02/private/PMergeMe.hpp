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
# include <iostream>
# include <limits.h>
# include <string>

#define SUCCESS 0
#define ERROR 1

#define DEBUG 0 

// class DuplicateNumbersException : public std::exception 
// {
// 	public:
// 		virtual const char* what() const throw();
// };

class WrongInputException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class PMergeMe
{
	private:

	public:
		PMergeMe();
		PMergeMe(PMergeMe const & src);
		~PMergeMe();

		PMergeMe &	operator=(PMergeMe const & rhs);
	
		// std::string const 		&getName(void) const;
		void	checkInput(int argc, char **argv);

};

std::ostream & operator<<(std::ostream & lhs, PMergeMe const & rhs);

#endif
