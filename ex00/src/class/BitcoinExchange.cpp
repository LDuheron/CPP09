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

BitcoinExchange::BitcoinExchange() : _database() // _configFile()
{
	if (DEBUG)
		std::cout << "Default constructor called.\n";
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _database(src._database)// _configFile(src._configFile) //
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

// map_t const &	BitcoinExchange::getDatabase(void) const
// {
// 	return (this->_database);
// }

// Overload --------------------------------------------------------------------

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	// this->_database = rhs._database;
	this->_database = rhs._database;
	return *this;
}

// std::ostream & operator<<(std::ostream & lhs, BitcoinExchange const & rhs)
// {
// 	lhs << rhs.getDatabase() << ".\n";
// 	return lhs;
// }

// Exception -------------------------------------------------------------------

const char* BitcoinExchange::FileOpeningException::what() const throw()
{
	return ("can't open file.");
}

const char* BitcoinExchange::WrongDateFormatException::what() const throw()
{
	return ("date format is Year-Month-Day.");
}

// Functions -------------------------------------------------------------------

void	BitcoinExchange::checkDate(std::string line)
{
	bool isLeapYear = FALSE;
	int	Year = atoi(line.substr(0,4).c_str());
	if ((Year % 4) == 0)
		isLeapYear = TRUE;
	int	Month = atoi(line.substr(5,2).c_str());
	int	Day = atoi(line.substr(8,2).c_str());
	if ((Month < 1 || Month > 12) || (Day < 1 || Day > 31))
		throw (WrongDateFormatException());
	if (Month == FEBRUARY && ((isLeapYear && Day > 29) || (!isLeapYear && Day > 28)))
		throw (WrongDateFormatException());
	if (Day > 30 && (Month == APRIL || Month == JUNE || Month == SEPTEMBER || Month == NOVEMBER))
		throw (WrongDateFormatException());
	// std::cout << "Year " << Year << " month " << Month << " Day " << Day << "\n";
}

void	BitcoinExchange::checkFormat(std::string line)
{
	std::string date = line.substr(0, 10);
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				throw(WrongDateFormatException());
		}
		else
		{
			if (isdigit(line[i]) == 0)
				throw(WrongDateFormatException());
		}
	}
	std::string value = line.substr(10);
}

void	BitcoinExchange::checkInput(std::string line)
{
	checkFormat(line); // - etc chiffre, points
	checkDate(line);
}

void	BitcoinExchange::getInput(char *input)
{
	std::ifstream infile(input);
	if (!infile.is_open() || infile.fail())
		throw(FileOpeningException());

	std::string line;
	while (std::getline(infile, line))
	{
		try
		{
			checkInput(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	infile.close();
}
