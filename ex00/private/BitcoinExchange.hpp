/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iostream>
# include <list>
# include <map>
# include <string>
# include <sstream>
# include <vector>
# include <utility>

 #include <cstdlib>

#define SUCCESS 0
#define ERROR 1

#define FALSE 0
#define TRUE 1

#define FEBRUARY 2
#define APRIL 4
#define JUNE 6
#define SEPTEMBER 9
#define NOVEMBER 11

#define DEBUG 0

/// irc = mapde commande 

typedef std::map<std::string, double> map_t;

class BitcoinExchange
{
	private:
		map_t	_database;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();

		void	getInput(char *input);

		void	getDatabase(void);

		void	checkDate(std::string line);
		void	checkFormat(std::string line);
		void	checkValue(std::string line);
		void	printValue(std::string line);

		BitcoinExchange &	operator=(BitcoinExchange const & rhs);

};

std::ostream & operator<<(std::ostream & lhs, BitcoinExchange const & rhs);

class ErrorException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class FileOpeningException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};
		
class ParseFailException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class WrongDateFormatException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class WrongFormatException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

class WrongValueFormatException : public std::exception 
{
	public:
		virtual const char* what() const throw();
};

#endif
