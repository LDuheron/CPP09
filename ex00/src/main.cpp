/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:24:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/23 12:25:12 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage is ./btc <file>.\n";
		return (ERROR);
	}

	BitcoinExchange btc;

	try
	{
		btc.getDatabase();
		btc.getInput(argv[1]);
		return (SUCCESS);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (ERROR);
}
