/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:33:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/22 17:44:15 by lduheron         ###   ########.fr       */
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
		// 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (SUCCESS);
}