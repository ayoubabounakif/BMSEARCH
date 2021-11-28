/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __main__.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:59:13 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/28 14:05:57 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template <typename T>
void    calculateTime( T start, string algorithm ) {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "\n---------------\n" << algorithm << " || Execution time ---> || " << duration.count() << " microseconds\n";
    cout << "---------------\n";
}

/* 
    Compiling instructions: (C++11)
        make
        ./a.out
        ./a.out | grep microseconds
*/

void    __main__( void ) {

    string pattern = "ATTTGACGCG";
    vector<string> vec = parse("./files/BIG_DNA_sequence.txt");
    vector<string>::iterator it;

    if (!pattern.length() || !vec.size())
        return ;

    cout << "----- Boyer-Moore -------" << endl;
    /* After few research, I found the Boyer-Moore string search algorithm. 
    This algorithm is a combination of a couple of approaches: 
        1 - Bad character heuristic. 
        2 - Good suffix heuristic.
    In mathematical optimizations and computer science, heuristic is a technique that's designed
    for solving a problem more quickly when classic methods are slow. */

    it = vec.begin();
    auto start = high_resolution_clock::now();
    for (; it != vec.end(); ++it) {
        boyerMooreSearch(*it, pattern);
    }
    calculateTime(start, "Boyer-Moore           ");


    cout << "----- Naive Search ------" << endl;
    it = vec.begin();
    start = high_resolution_clock::now();
    for (; it != vec.end(); ++it) {
        naiveSearch(pattern, *it);
    }
    calculateTime(start, "Naive Search          ");


    cout << "----- Naive Search Optimization ------" << endl;
    /*  I decided to try and optimize the naive algorithm */
    it = vec.begin();
    start = high_resolution_clock::now();
    for (; it != vec.end(); ++it) {
        naiveOptimizedSearch(pattern, *it);
    }
    calculateTime(start, "Optimized Naive Search");


    cout << "----- Find method in C++ -------" << endl;
    /* This algorithm was implemented using the find method. */
    start = high_resolution_clock::now();
    it = vec.begin();
    for (; it != vec.end(); ++it) {
        if (it->find(pattern) != string::npos)
            cout << "This sentence contains the Keyword ---> " << *it << endl;
    }
    calculateTime(start, "Find method           ");
}

int main( void ) {
    __main__();
    return EXIT_SUCCESS;
}