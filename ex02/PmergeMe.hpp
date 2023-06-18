/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:59 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/18 05:19:11 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

# include	<string>
# include	<sstream>
# include	<climits>
# include	<cstdlib>
# include	<iostream>
# include	<algorithm>
# include	<deque>
# include	<vector>
# include	<sys/time.h>
# include	<iomanip>
# include	<time.h>

class	PmergeMe
{
	public:
		//Canonical	form	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		PmergeMe(void);
		PmergeMe(int& argc, char **input);
		~PmergeMe(void);
		
		//Member functions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void	fillContainers(int& argc, char **argv);
		double	getTime(void);
		void	printContainers(int decider_before_after, int decide_deque_or_vector);

		//Templated functions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		template	<typename	T>
		void	merge(T&	container, int front, int middle, int back);
		template	<typename	T>
		void	insertionSort(T& container, int front, int back);
		template	<typename	T>
		void	mergeInsertSort(T& container, int f, int b);
	private:
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		std::deque<int>		_nbr_arr_deque;
		std::vector<int>	_nbr_arr_vector;
};

//Colors	===========================
# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif