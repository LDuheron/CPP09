/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:40:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/23 14:38:46 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PMergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Usage is ./PMergeMe <numbers>" << std::endl;
		return (ERROR);
	}
	try
	{
		PMergeMe	PME;
		PME.checkInput(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (SUCCESS);
}
