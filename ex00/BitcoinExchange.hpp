/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:57:23 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/12 19:07:40 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RPN_HPP
# define	RPN_HPP

# include	<map>
# include	<string>
# include	<iostream>
# include	<cstdlib>
# include	<fstream>

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(char *filename);
		BitcoinExchange(const BitcoinExchange& other);
		
		BitcoinExchange&	operator=(const BitcoinExchange& other);
	private:
		std::map<std::string, float>	_database;
};

//Colors	===========================
# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif