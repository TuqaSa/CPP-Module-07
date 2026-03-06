/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaeed < tsaeed@student.42amman.com >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 23:00:00 by tsaeed            #+#    #+#             */
/*   Updated: 2026/03/06 23:54:07 by tsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

// Default constructor: empty array
template <typename T>
Array<T>::Array(void) : _array(NULL), _size(0)
{
}

// Parametric constructor: array of n elements initialized by default
template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
}

// Copy constructor: deep copy
template <typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(0)
{
	*this = src;
}

// Destructor
template <typename T>
Array<T>::~Array(void)
{
	delete[] _array;
}

// Assignment operator: deep copy
template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		delete[] _array;
		_size = rhs._size;
		_array = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = rhs._array[i];
	}
	return *this;
}

// Subscript operator (non-const)
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _array[index];
}

// Subscript operator (const)
template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _array[index];
}

// Size member function
template <typename T>
unsigned int Array<T>::size(void) const
{
	return _size;
}

#endif
