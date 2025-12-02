/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:31 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/11/05 19:25:32 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T const& a, T const& b)
{
    return (a < b) ? a : b;
}

template<typename T>
T max(T const& a, T const& b)
{
    return (a > b) ? a : b;
}