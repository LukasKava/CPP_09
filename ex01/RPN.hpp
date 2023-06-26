/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:06:03 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/26 05:12:28 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		RPN_HPP
# define	RPN_HPP

# include <stack>
# include <string>
# include <vector>
# include <cstdlib>
# include <stdexcept>
# include <iostream>

class	ReversePolishNotation
{
	public:
		//Canonical	form	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		ReversePolishNotation(void);
		~ReversePolishNotation(void);
		ReversePolishNotation(std::string input);
		
		//Member functions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	private:	
		ReversePolishNotation(const ReversePolishNotation& other);
		ReversePolishNotation&	operator=(const ReversePolishNotation& other);
		std::stack<int, std::vector<int> >	_calculations;
};

//Colors	===========================
# define	BLANK "\033[0m"
# define	RED	"\033[0;31m"
# define	GREEN "\033[0;32m"
# define	YELL "\033[0;33m"
# define	CYAN "\033[0;36m"

#endif