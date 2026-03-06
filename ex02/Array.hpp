/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:00:00 by tsaeed            #+#    #+#             */
/*   Updated: 2026/03/06 23:54:06 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <typename T>
class Array
{
private:
	T				*_array;
	unsigned int	_size;

public:
	Array(void);
	Array(unsigned int n);
	Array(Array const &src);
	~Array(void);

	Array &operator=(Array const &rhs);
	T &operator[](unsigned int index);
	T const &operator[](unsigned int index) const;

	unsigned int size(void) const;
};

#include "Array.tpp"

#endif
