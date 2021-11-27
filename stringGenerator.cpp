/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stringGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:41:18 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 17:26:50 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

void stringGenerator( vector <string> &vec, int howManyStringsToGenerate, int n )
{
    int     i, j;
    char    c;
    string  str;

    for (i = 0; i < howManyStringsToGenerate; i++) {
        for (j = 0; j < n; j++) {
            c = rand() % 26 + 'A';
            str += c;
        }
        vec.push_back(str);
        str.clear();
    }
}