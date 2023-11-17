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

# include <iostream>
# include <list>
# include <map>
# include <string>

#define SUCCESS 0
#define ERROR 1

#define DEBUG 0

typedef std::map<int, std::string> map_t;

class BitcoinExchange
{
	private:
		std::map<int, std::string>	_database;
		// std::list<std::string> _database;

	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();

		void	getInput(char *input);

		BitcoinExchange &	operator=(BitcoinExchange const & rhs);

		map_t const &getDatabase(void) const;
};

std::ostream & operator<<(std::ostream & lhs, BitcoinExchange const & rhs);

#endif
