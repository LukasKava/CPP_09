/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:55 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/15 22:03:54 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Canonical	form	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this);}

void	PmergeMe::fillContainers(int& argc, char  **input)
{
	std::stringstream	ss;
	unsigned long int	tmp;
	for (int i = 1; i < argc; i++)
	{
		ss << input[i];
		ss >> tmp;
		if (tmp > INT_MAX)
		{
			std::cout << RED "Error: your desired number is more than INT_MAX!" BLANK << std::endl;
			exit(-1);
		}
		_nbr_arr_deque.push_back(tmp);
		_nbr_arr_list.push_back(tmp);
		ss.clear();
	}
}

void	PmergeMe::printContainers(void)
{
	for (std::deque<int>::iterator it = _nbr_arr_deque.begin(); it != _nbr_arr_deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (std::list<int>::iterator it = _nbr_arr_list.begin(); it != _nbr_arr_list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

PmergeMe::PmergeMe(int& argc, char **input)
{
	fillContainers(argc, input);
	printContainers();
}