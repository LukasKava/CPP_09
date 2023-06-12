/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:12:54 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/12 19:07:50 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _database()
{
	std::cout << "Default constructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(char  *filename)
{
	std::cout << "Custom constructor. Input filename: " << filename << std::endl;
	std::ifstream	read_file;
	
	read_file.open(filename);
	if (read_file.is_open() == false)
	{
		std::cerr << RED "ERROR: something is wrong with the file. Please check if has correct name!" BLANK << std::endl;
		exit(-2);
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;		
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this->_database.empty() == false)
		this->_database.clear();
	std::map<std::string, float>::iterator	it;
	for (it == other._database.begin(); it != other._database.end(); it++)
		this->_database.insert(*it);
	return (*this);
}