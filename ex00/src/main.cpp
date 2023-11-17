/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:24:53 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/17 11:30:47 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage is ./btc <csv file>.\n";
		return (ERROR);
	}
	BitcoinExchange btc;

	btc.getInput(argv[1]);
	return (SUCCESS);
}
