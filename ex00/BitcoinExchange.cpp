/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:12:54 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/14 13:59:33 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void): _database()
{
	std::cout << "Default constructor" << std::endl;
}

BitcoinExchange::~BitcoinExchange(void){}

BitcoinExchange::BitcoinExchange(std::string  filename)
{
	std::ifstream	read_file;
	
	read_file.open(filename.c_str());
	if (read_file.is_open() == false)
	{
		std::cerr << RED "ERROR: something is wrong with the file. Please check if has correct name!" BLANK << std::endl;
		exit(-2);
	}

	std::stringstream	ss;
	std::string			line;
	std::string			date;
	std::string			exchange_rate_str;
	double				exchange_rate_f;

	std::getline(read_file, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << RED "Incorrect format of data.csv file!" BLANK << std::endl;
		exit(-3);
	}
	while (std::getline(read_file, line))
	{
		date = line.substr(0, line.find(','));
		exchange_rate_str = line.substr(line.find(",") + 1, line.size() - 1);
		ss << exchange_rate_str;
		ss >> exchange_rate_f;
		ss.clear();
		_database.insert(std::pair<std::string, float>(date, exchange_rate_f));
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
	std::map<std::string, double>::iterator	it;
	for (it == other._database.begin(); it != other._database.end(); it++)
		this->_database.insert(*it);
	return (*this);
}

//Functionality functions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static void	outputTheValue(std::map<std::string, double>::iterator& it, std::string& date, std::string& stored_ammount_str)
{
	std::stringstream	ss;
	double				stored_ammount_double;
	double				exchange_rate = it->second;

	ss << stored_ammount_str;
	ss >> stored_ammount_double;
	ss.clear();

	std::cout << date << " => " << stored_ammount_double << " = " << stored_ammount_double * exchange_rate << std::endl;
}

static void	checkDate(std::string& date)
{
	if (std::count(date.begin(), date.end(), '-') != 2)
		throw	BitcoinExchange::BadInput();
	if (date.size() != 11)
		throw	BitcoinExchange::BadInput();
	if (date.at(4) != '-' || date.at(7) != '-' || date.at(date.size() - 1) != ' ')
		throw	BitcoinExchange::BadInput();

	std::string arr_str_date[3] = {date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)};
	
	//Checking if it is an actual number.
	for (int i = 0; i < 3; i++)
	{
		for (size_t x = 0; x < arr_str_date[i].size(); x++)
		{
			if (std::isdigit(arr_str_date[i][x]) == false)
				throw	BitcoinExchange::BadInput();
		}
	}

	int	arr_int_date[3];
	std::stringstream	ss;
	
	//Converting things to numbers in c++98 way
	for (int i = 0; i < 3; i++)
	{
		ss << arr_str_date[i];
		ss >> arr_int_date[i];
		ss.clear();
	}
	if (arr_int_date[0] < 2009)
		throw	BitcoinExchange::WhatIsBitcoin();
	if (arr_int_date[1] > 12)
		throw	BitcoinExchange::BadInput();
	if (arr_int_date[2] > 31)
		throw	BitcoinExchange::BadInput();
	else if (arr_int_date[1] == 4 || arr_int_date[1] == 6 || \
				arr_int_date[1] == 9 || arr_int_date[1] == 11)
	{
		if (arr_int_date[2] > 30)
			throw	BitcoinExchange::DayDoesNotExist();
	}
	else if (arr_int_date[1] == 2)
	{
		if (arr_int_date[1] > 29)
			throw	BitcoinExchange::DayDoesNotExist();
		if (arr_int_date[2] == 29 && \
			(arr_int_date[0] % 4 != 0 || \
			(arr_int_date[0] % 100 == 0 && arr_int_date[0] % 400 != 0)))
			throw	BitcoinExchange::DayDoesNotExist();
	}
}

static bool	dateTestsOk(std::string date)
{
	try { checkDate(date);}
	catch (BitcoinExchange::BadInput& e)
	{
		std::cout << e.what() << date << std::endl;
		return (false);
	}
	catch (BitcoinExchange::WhatIsBitcoin& e)
	{
		std::cout << e.what() << date << std::endl;
		return (false);
	}
	catch (BitcoinExchange::DayDoesNotExist& e)
	{
		std::cout << e.what() << date << std::endl;
		return (false);
	}
	return (true);
}

static void	checkCoins(std::string& value)
{
	if (value[0] != ' ' || std::count(value.begin(), value.end(), '.') > 1)
		throw	BitcoinExchange::BadInput();
	else if (value[1] == '-')
		throw	BitcoinExchange::NegativeNumber();
	else if (value[1] != '+' && std::isdigit(value[1]) == false)
		throw	BitcoinExchange::BadInput();
	
	//Checking if it is an actual number
	for (size_t i = 2; i < value.size(); i++)
	{
		if (value[i] != '.' && std::isdigit(value[i]) == false)
			throw	BitcoinExchange::BadInput();
	}

	std::stringstream	ss;
	double				ammount;

	ss << value;
	ss >> ammount;

	if (ammount > 1000)
		throw	BitcoinExchange::NumberIsToLarge();	
}

static bool	storedAmmountTestsOk(std::string& stored_ammount)
{
	try {	checkCoins(stored_ammount);}
	catch (const BitcoinExchange::BadInput& e)
	{
		std::cout << e.what() << stored_ammount << std::endl;
		return (false);
	}
	catch (const BitcoinExchange::NegativeNumber& e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
	catch (const BitcoinExchange::NumberIsToLarge& e)
	{
		std::cout << e.what() << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::evaluate(std::string filename2)
{
	std::ifstream	read_file;
	
	read_file.open(filename2.c_str());
	if (read_file.is_open() == false)
	{
		std::cerr << RED "ERROR: something is wrong with the file. Please check if has correct name!" BLANK << std::endl;
		exit(-2);
	}

	std::string line;

	std::getline(read_file, line);
	if (line != "date | value")
	{
		std::cerr << RED "ERROR: incorrect format of and" << filename2 << " file!" BLANK << std::endl;
		exit(-3);
	}

	std::string	date;
	std::string value;

	while (std::getline(read_file, line))
	{
		if (line.find("|") == std::string::npos)
			std::cout << "ERROR: bad input => " << line << std::endl;
		else
		{
			if (dateTestsOk(line.substr(0, line.find("|"))) == true)
			{
				value = line.substr(line.find("|") + 1, line.size() - 1);
				if (storedAmmountTestsOk(value) == true)
				{
					date = line.substr(0, line.find("|") - 1);
					std::map<std::string, double>::iterator it;
					for (it = _database.begin(); it != _database.end(); it++)
					{
						if (it->first == date)
						{
							outputTheValue(it, date, value);
							break;
						}
						else if (it->first > date)
						{
							it--;
							outputTheValue(it, date, value);
							break;
						}
					}
				}
			}
		}
	}
}

//Exceptions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

const char 	*BitcoinExchange::WhatIsBitcoin::what() const throw()
{
	return ("ERROR: Bitcoin did not exist before 2009 => ");
}

const char 	*BitcoinExchange::DayDoesNotExist::what() const throw()
{
	return ("ERROR: Please check if this month day exists! => ");
}

const char 	*BitcoinExchange::BadInput::what() const throw()
{
	return ("ERROR: Bad input => ");
}

const char	*BitcoinExchange::NumberIsToLarge::what() const throw()
{
	return ("ERROR: Too large a number.");
}

const char	*BitcoinExchange::NegativeNumber::what() const throw()
{
	return ("ERROR: not a positive number.");
}