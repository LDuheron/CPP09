/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:33:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/23 11:35:00 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage is ./RPN <Inverted Polish mathematical expression>\n"; 
		return (ERROR);
	}
	try
	{
		RPN rpn;
		rpn.parseInput(argv[1]);
		rpn.readAndCalculate(argv[1]);
		std::cout << rpn.getResult() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (SUCCESS);
}
