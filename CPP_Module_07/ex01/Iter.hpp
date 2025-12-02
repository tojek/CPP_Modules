/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:33 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/11/05 19:25:34 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

template<typename T, typename F>
void iter(T* array, size_t const size, F func)
{
	for (size_t i = 0; i < size; ++i)
	{
		func(array[i]);
	}
}
