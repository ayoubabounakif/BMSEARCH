/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naiveOptimizedSearch.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:26:06 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 19:54:55 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

void    naiveOptimizedSearch( string pat, string txt ) {
    int patLen = pat.length();
    int txtLen= txt.length();
    int i = 0;
    while (i <= txtLen - patLen) {
        int j = 0;
        for (; j < patLen; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == patLen)
        {
            cout << "This sentence contains the Keyword ---> " << txt << endl;
            i = i + patLen;
        }
        else if (j == 0)
            i = i + 1;
        else
            i = i + j;
    }  
}