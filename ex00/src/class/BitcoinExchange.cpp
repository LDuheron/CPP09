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

const char* FileOpeningException::what() const throw()
{
	return ("can't open file.");
}

const char* WrongDateFormatException::what() const throw()
{
	return ("format is Year-Month-Day.");
}

const char* WrongFormatException::what() const throw()
{
	return ("format is data | value.");
}

const char* WrongValueFormatException::what() const throw()
{
	return ("value must be either a float or a positive integer, between 0 and 1000.");
}

const char* ParseFailException::what() const throw()
{
	return ("Isstream failed to parse.\n");
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
}

void	BitcoinExchange::checkFormat(std::string line)
{
	std::string date = line.substr(0, 10);

	for (int i = 0; i < 13; i++)
	{
		if (i == 4 || i == 7)
		{
			if (line[i] != '-')
				throw(WrongDateFormatException());
		}
		else if (i == 10 || i == 12)
		{
			if (line[i] != ' ')
				throw(WrongFormatException());
		}
		else if (i == 11)
		{
			if (line[i] != '|')
				throw(WrongFormatException());
		}
		else
		{
			if (!isdigit(line[i]))
				throw(WrongDateFormatException());
		}
	}
	std::string value = line.substr(10);
}

void	BitcoinExchange::checkValue(std::string line)
{
	int nbPositiveSign = 0;
	for (int i = 13; i < (int)line.size(); i++)
	{
		if (line[i] == '+')
			nbPositiveSign += 1;
		else
			break;
	}

	std::string value = line.substr(13 + nbPositiveSign, line.size());
	int cptDot = 0;
	for (int i = 0; i < (int)value.size(); i++)
	{
		if (value[i] == '.')
		{
			cptDot += 1;
			if (cptDot > 1 || i > 4)
				throw(WrongValueFormatException());
		}
		else if (!isdigit(value[i]))
			throw(WrongValueFormatException());
	}
	if (cptDot == 0 && value.size() > 4)
		throw(WrongValueFormatException());

	std::istringstream	iss(value);
	char	*valueNbr = new char[value.length() + 1];
	std::strcpy(valueNbr, value.c_str());
	if (iss >> valueNbr)
	{
		if (atoi(valueNbr) < 0 || atoi(valueNbr) > 1000)
		{
			delete[]valueNbr;
			throw(WrongValueFormatException());
		}
	}
	else
	{
		delete[] valueNbr;
		throw(ParseFailException());
	}
	delete[] valueNbr;
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
			checkFormat(line);
			checkDate(line);
			checkValue(line);
			std::cout << "All good bro !\n";
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
	}
	infile.close();
}
