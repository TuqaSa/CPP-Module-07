/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:59:11 by tsaeed            #+#    #+#             */
/*   Updated: 2026/03/06 22:05:56 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &x)
{
	std::cout << x << " ";
}

void increment(int &x)
{
	x += 1;
}

void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
}

int main(void)
{
	std::cout << "=== Int array ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Before: ";
	iter(intArr, intLen, print<int>);
	std::cout << std::endl;

	iter(intArr, intLen, increment);
	std::cout << "After increment: ";
	iter(intArr, intLen, print<int>);
	std::cout << std::endl;

	std::cout << "\n=== String array ===" << std::endl;
	std::string strArr[] = {"hello", "world", "foo"};
	size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "Before: ";
	iter(strArr, strLen, print<std::string>);
	std::cout << std::endl;

	iter(strArr, strLen, toUpper);
	std::cout << "After toUpper: ";
	iter(strArr, strLen, print<std::string>);
	std::cout << std::endl;

	std::cout << "\n=== Double array ===" << std::endl;
	double dblArr[] = {1.1, 2.2, 3.3};
	size_t dblLen = sizeof(dblArr) / sizeof(dblArr[0]);

	std::cout << "Values: ";
	iter(dblArr, dblLen, print<double>);
	std::cout << std::endl;

	return 0;
}
