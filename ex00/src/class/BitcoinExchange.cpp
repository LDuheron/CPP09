/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructor -----------------------------------------------------------------

BitcoinExchange::BitcoinExchange() : _database()
{
	if (DEBUG)
		std::cout << "Default constructor called.\n";
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _database(src._database)
{
	if (DEBUG)
		std::cout << "Copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

BitcoinExchange::~BitcoinExchange()
{
	if (DEBUG)
		std::cout << "Destructor called.\n";
}

// Accessors -------------------------------------------------------------------

map_t const &	BitcoinExchange::getDatabase(void) const
{
	return (this->_database);
}

// Overload --------------------------------------------------------------------

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	this->_database = rhs._database;
	return *this;
}

// std::ostream & operator<<(std::ostream & lhs, BitcoinExchange const & rhs)
// {
// 	lhs << rhs.getDatabase() << ".\n";
// 	return lhs;
// }

// Functions -------------------------------------------------------------------

void	BitcoinExchange::getInput(char *input)
{
	
}

