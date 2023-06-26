/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:06:06 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/26 05:16:28 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Canonical	form	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ReversePolishNotation::ReversePolishNotation(void) {}

ReversePolishNotation::~ReversePolishNotation(void) {}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation&	other) { *this = other;}

ReversePolishNotation& ReversePolishNotation::operator=(const ReversePolishNotation& other) { (void)other; return (*this);}

static bool	checkNumber(char& it)
{
	if (it >= '0' && it <= '9')
		return (true);
	return (false);
}

static bool	checkOperator(char& it)
{
	if (it  == '+')
		return (true);
	else if (it == '-')
		return (true);
	else if (it == '/')
		return (true);
	else if (it == '*')
		return (true);
	return (false);
}

static int	performCalculation(int a, int b, char& it)
{
	if (it  == '+')
		return (b + a);
	else if (it == '-')
		return (b - a);
	else if (it == '/')
	{
		if (a == 0)
			throw std::logic_error("ERROR: Division by 0 is not possible!");
		return (b / a);
	}
	return (b * a);
}

ReversePolishNotation::ReversePolishNotation(std::string input)
{
	std::string::iterator	it;
	int						a, b = 0;

	for (it = input.begin(); it != input.end(); it++)
	{
		if (checkOperator(*it) == true)
		{
			if (_calculations.size() < 2)
			{
				std::cout << RED "Error: cannot perform operation because stack is too small!" BLANK << std::endl;
				exit(-1);
			}
			a = _calculations.top();
			_calculations.pop();
			b = _calculations.top();
			_calculations.pop();
			try {_calculations.push(performCalculation(a, b, *it));}
			catch (std::logic_error &e)
			{
				std::cerr << RED << e.what() << BLANK << std::endl;
				exit(-1);
			}
		}
		else if (checkNumber(*it) == true)
			_calculations.push(*it - '0');
		else if (*it == ' ')
			continue;
		else
		{
			std::cout << RED "Error" BLANK << std::endl;
			exit(-1);
		}
	}
	if (_calculations.size() == 1)
		std::cout << _calculations.top() << std::endl;
	else
		std::cout << RED "Error" BLANK << std::endl;
}