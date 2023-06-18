/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkavalia <lkavalia@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:54:55 by lkavalia          #+#    #+#             */
/*   Updated: 2023/06/18 05:39:52 by lkavalia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Canonical	form	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& other) { *this = other;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) { (void)other; return (*this);}

//Member functions	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
		_nbr_arr_vector.push_back(tmp);
		ss.clear();
	}
}

void	PmergeMe::printContainers(int decider_before_after, int decide_deque_or_vector)
{
	if (decider_before_after == 0)
		std::cout << "Before:	";
	else
		std::cout << "After:	";
	if (decide_deque_or_vector == 0)
	{
		for (std::deque<int>::iterator it = _nbr_arr_deque.begin(); it != _nbr_arr_deque.end(); it++)
			std::cout << *it << " ";
	}
	else
	{
		for (std::deque<int>::iterator it = _nbr_arr_deque.begin(); it != _nbr_arr_deque.end(); it++)
			std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template	<typename	T>
void	PmergeMe::merge(T&	container, int front, int middle, int back) 
{
    T temp;
    for (int i = front; i <= back; ++i) {
        temp.push_back(container[i]);
    }

	int k = front;
    int front_p_index = front;
    int second_p_index = middle + 1;

    while (front_p_index <= middle && second_p_index <= back) 
	{
        if (temp[front_p_index - front] <= temp[second_p_index - front])
            container[k++] = temp[front_p_index++ - front];
        else
            container[k++] = temp[second_p_index++ - front];
    }
    while (front_p_index <= middle)
        container[k++] = temp[front_p_index++ - front];
    while (second_p_index <= back)
        container[k++] = temp[second_p_index++ - front];
}

template	<typename	T>
void	PmergeMe::insertionSort(T& container, int front, int back)
{
    for (int i = front; i < back; i++) {
        int tempVal = container[i + 1];
        int j = i + 1;
        while (j > front && container[j - 1] > tempVal) {
            container[j] = container[j - 1];
            j--;
        }
        container[j] = tempVal;
    }
}

template	<typename	T>
void	PmergeMe::mergeInsertSort(T& container, int front, int back)
{
	if (back - front > 30)
	{
		int	middledle = (front + back) / 2;;
		mergeInsertSort(container, front, middledle);
		mergeInsertSort(container, middledle + 1, back);
		merge(container, front, middledle, back);
	}
	else
		insertionSort(container, front, back);
}

double	PmergeMe::getTime()
{
	double	time;
	struct	timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec + tv.tv_usec * 1e-6;
	return (time * 1000);
}

PmergeMe::PmergeMe(int& argc, char **input)
{
	fillContainers(argc, input);
	printContainers(0, 0);

	clock_t	startTime_deque = clock();
	mergeInsertSort(_nbr_arr_deque, 0, _nbr_arr_deque.size() - 1);
	clock_t	endTime_deque = clock();
	double	dequeDiff = (double)(endTime_deque - startTime_deque) / CLOCKS_PER_SEC * 1e3;
	clock_t	startTime_vector = clock();
	mergeInsertSort(_nbr_arr_vector ,0, _nbr_arr_vector.size() - 1);
	clock_t	endTime_vector = clock();
	double	vectorDiff = (double)(endTime_vector - startTime_vector) / CLOCKS_PER_SEC * 1e3;
	printContainers(1, 0);
	std::cout << "Time to process a range of " << _nbr_arr_deque.size() <<  " elements with std::deque<int> : " << dequeDiff << " ms" << std::endl;
	std::cout << "Time to process a range of " << _nbr_arr_vector.size() << " elements with std::vector<int> : " << vectorDiff << " ms" << std::endl;
}
