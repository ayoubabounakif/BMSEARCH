/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:59:13 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 17:46:08 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

/* #pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops") */

/* 
    Compiling instructions: (C++11)
        make
        ./a.out || ./a.out | grep microseconds
*/

template <typename T>
void    calculateTime( T start ) {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "---------------" << endl <<
        "Execution time ---> || " << duration.count() << " microseconds ||" << endl;
    cout << "---------------" << endl;
}

int main( void ) {
    string pattern = "GTTCGTGTGGTATCGGT";

    vector<string> vec;
    vector<string>::iterator it;
    auto start = high_resolution_clock::now();

    string data;
    ifstream myFile("./files/DNA_sequence.txt");

    while (getline(myFile, data))
        vec.push_back(data);
    myFile.close();
    it = vec.begin();
    

    cout << "----- Find method in C++ -------" << endl;
    /* This algorithm was implemented using the find method. */
    start = high_resolution_clock::now();
    for (; it != vec.end(); ++it) {
        if (it->find(pattern) != string::npos)
            cout << "This sentence contains the Keyword ---> " << *it << endl;
    }
    calculateTime(start);


    cout << "----- Boyer-Moore -------" << endl;
    /* After few research, I found the Boyer-Moore string search algorithm. 
    This algorithm is a combination of a couple of approaches: 
        1 - Bad character heuristic. 
        2 - Good suffix heuristic.
    In mathematical optimizations and computer science, heuristic is a technique that's designed
    for solving a problem more quickly when classic methods are slow. */

    it = vec.begin();
    start = high_resolution_clock::now();
    for (; it != vec.end(); ++it) {
        boyerMooreSearch(*it, pattern);
    }
    calculateTime(start);


    cout << "----- Naive Search Optimization ------" << endl;
    /* Since the search algorithm didn't work as expected.
    I decided to try and optimize the naive algorithm and make it skip using length or something */
    it = vec.begin();
    start = high_resolution_clock::now();
    for (; it != vec.end(); ++it) {
        naiveOptimizedSearch(pattern, *it);
    }
    calculateTime(start);


    /* Thread usage as last resort xD */
    
    
    return EXIT_SUCCESS;
}