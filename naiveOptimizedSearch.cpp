/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naiveOptimizedSearch.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:26:06 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 17:46:01 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

void    naiveOptimizedSearch( string pat, string txt ) {
    int M = pat.length();
    int N = txt.length();
    int i = 0;
    while (i <= N - M) {
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;
        if (j == M)
        {
            cout << "This sentence contains the Keyword ---> " << txt << endl;
            i = i + M;
        }
        else if (j == 0)
            i = i + 1;
        else
            i = i + j;
    }  
}