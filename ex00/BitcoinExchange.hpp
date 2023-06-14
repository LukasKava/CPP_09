/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:57:23 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/14 14:01:01 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
# define	RPN_HPP

# include	<map>
# include	<string>
# include	<iostream>
# include	<sstream>
# include	<cstdlib>
# include	<fstream>
# include	<iomanip>
# include	<exception>
# include	<algorithm>

class	BitcoinExchange
{
	public:
		//Canonical form 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		BitcoinExchange(void);
		BitcoinExchange(std::string filename);
		~BitcoinExchange(void);
		
		//Member functions 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		void	evaluate(std::string filename2);
		
		//Exceptions 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		class	BadInput: public std::exception
		{
		public:
			virtual const char	*what() const throw();			
		};
		
		class	WhatIsBitcoin: public std::exception
		{
		public:
			virtual const char	*what() const throw();			
		};

		class	DayDoesNotExist: public std::exception
		{
		public:
			virtual const char	*what() const throw();			
		};

		class	NegativeNumber: public std::exception
		{
		public:
			virtual	const char	*what() const throw();
		};
		
		class	NumberIsToLarge: public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
	private:
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);
		std::map<std::string, double>	_database;
};

//Colors	===========================
# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif