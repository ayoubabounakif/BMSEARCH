/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naiveSearch.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:21:50 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 19:54:52 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

void    naiveSearch( string pat, string txt ) {
    int patLen = pat.length();
    int txtLen= txt.length();
    for (int i = 0; i <= txtLen - patLen; i++) {
        int j = 0;
        for (; j < patLen; j++)
            if (txt[i + j] != pat[j])
                break ;
        if (j == patLen)
            cout << "This sentence contains the Keyword ---> " << txt << endl;
    }
}