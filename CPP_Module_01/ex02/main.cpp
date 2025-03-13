/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwojtcza <mwojtcza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:46:34 by mwojtcza          #+#    #+#             */
/*   Updated: 2025/03/13 14:46:35 by mwojtcza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    // Print memory addresses
    std::cout << "Memory addresses:" << std::endl;
    std::cout << "string:    " << &string << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;

    // Print values
    std::cout << "\nValues:" << std::endl;
    std::cout << "string:    " << string << std::endl;
    std::cout << "stringPTR: " << *stringPTR << std::endl;
    std::cout << "stringREF: " << stringREF << std::endl;

    return 0;
}
