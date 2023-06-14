/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:34:50 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/13 14:46:55 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "ERROR: incorrect ammount of arguments!" BLANK << std::endl;
		std::cerr << YELL "Please specify input file..." BLANK << std::endl;
		return (-1);
	}
	BitcoinExchange	exchange("../cpp_09/data.csv");
	exchange.evaluate(argv[1]);
	(void)argv;
	return (0);
}