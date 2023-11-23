/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:40:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/23 18:35:03 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PMergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Usage is ./PMergeMe <numbers>" << std::endl;
		return (ERROR);
	}
	try
	{
		PMergeMe	PME;
		PME.checkInput(argc, argv);
		
		double	startTime = getTime();
		PME.fillVector(argc, argv);
		PME.printBefore();
		PME.setVector(PME.cutAndSort(PME.getVector()));
		PME.printAfter();
		PME.printTime(VECTOR, getTime() - startTime);
	
		startTime = getTime();
		PME.fillDeque(argc, argv);
		PME.setDeque(PME.cutAndSort(PME.getDeque()));
		PME.printTime(DEQUE, getTime() - startTime);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (SUCCESS);
}
