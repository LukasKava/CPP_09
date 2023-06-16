/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:52 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/15 22:03:32 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	inputErrors(int& argc, char	**argv)
{
	if (argc < 3)
	{
		std::cout << RED "Error: please provide more than 1 number!" BLANK << std::endl;
		exit(-1);
	}
	
	for (int i = 1; argv[i] != NULL; i++)
	{
		for (int x = 0; argv[i][x] != '\0'; x++)
		{
			if (isdigit(argv[i][x]) == false)
			{
				std::cout << RED "Error: its not a digit!" << std::endl;
				exit(-1);
			}
		}
	}
}

int main(int argc, char **argv)
{
	inputErrors(argc, argv);

	PmergeMe	a(argc, argv);
	return (0);
}