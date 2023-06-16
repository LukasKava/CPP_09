/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:59 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/15 22:00:20 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PMERGEME_HPP
# define	PMERGEME_HPP

# include	<string>
# include	<sstream>
# include	<climits>
# include	<cstdlib>
# include	<iostream>
# include	<deque>
# include	<list>

class	PmergeMe
{
	public:
		//Canonical	form	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		PmergeMe(void);
		PmergeMe(int& argc, char **input);
		~PmergeMe(void);
		
		//Member functions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void	fillContainers(int& argc, char **argv);
		void	printContainers(void);
	private:
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		std::deque<int>	_nbr_arr_deque;
		std::list<int>	_nbr_arr_list;
};

//Colors	===========================
# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif