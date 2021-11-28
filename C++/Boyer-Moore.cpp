/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boyer-Moore.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:37:33 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/28 17:24:57 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

void preprocess_strong_suffix(int *shift, int *bpos, string pat, int m)
{
    // m is the length of pattern 
    int i = m, j = m + 1;
    bpos[i] = j;
  
    while (i > 0)
    {
        /* if character at position i - 1 is not equivalent to
           character at j - 1, then continue searching to right
           of the pattern for border */
        while (j <= m && pat[i - 1] != pat[j - 1])
        {
            /* The character preceding the occurrence of t in 
               pattern P is different than the mismatching character in P, 
               we stop skipping the occurrences and shift the pattern
               from i to j */
            if (shift[j] == 0)
                shift[j] = j - i;
  
            // Update the position of next border 
            j = bpos[j];
        }
        /* p[i - 1] matched with p[j - 1], border is found.
           store the  beginning position of border */
        i--; j--;
        bpos[i] = j; 
    }
}

void preprocess_case2(int *shift, int *bpos, string pat, int m)
{
    int i, j;
    j = bpos[0];
    for (i = 0; i <= m; i++)
    {
        /* Set the border position of the first character of the pattern
           to all indices in array shift having shift[i] = 0 */ 
        if (shift[i] == 0)
            shift[i] = j;
        /* Suffix becomes shorter than bpos[0], use the position of 
           next widest border as value of j */
        if (i == j)
            j = bpos[j];
    }
}

/* Search for a pattern in given text using
   Boyer Moore algorithm with Good suffix rule */
void    boyerMooreSearch( string text, string pat )
{
    // s is shift of the pattern with respect to text
    int s = 0, j;
    int m = pat.length();
    int n = text.length();
    int bpos[m + 1], shift[m + 1];

    // Initialize all occurrence of shift to 0
    for (int i = 0; i < m + 1; i++) shift[i] = 0;
    // Do preprocessing
    preprocess_strong_suffix(shift, bpos, pat, m);
    preprocess_case2(shift, bpos, pat, m);
    while(s <= n - m) {
        j = m - 1;
        /* Keep reducing index j of pattern while characters of
             pattern and text are matching at this shift s*/
        while (j >= 0 && pat[j] == text[s + j])
            j--;
        /* If the pattern is present at the current shift, then index j
             will become -1 after the above loop */
        if (j < 0)
        {
            s += shift[0];
            cout << "This sentence contains the Keyword ---> " << text << endl;
        }
        else
            /*pat[i] != pat[s+j] so shift the pattern
              shift[j+1] times  */
            s += shift[j+1];
    }
}