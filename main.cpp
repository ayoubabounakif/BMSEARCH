/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:59:13 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/25 15:24:40 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <fstream>

# include <string>
# include <vector>
# include <list>
# include <map>
# include <set>

# include <algorithm>
# include <cmath>

# include <chrono>

using namespace std;
using namespace std::chrono;
  
void stringGenerator(vector <string> &vec, int howManyStringsToGenerate, int n)
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

template <typename T>
void    calculate_time( T start ) {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "---------------" << endl <<
        "Execution time ---> || " << duration.count() << " microseconds ||" << endl;
    cout << "---------------" << endl;
}

/* 
    Compiling instructions: (C++11)
        g++ -std=c++11 main.cpp ; ./a.out
*/

int main( void ) {

    string needle = "sol";

    vector<string> vec;
    vector<string>::iterator it;

    string data;
    ifstream myFile("lorem_ipsum--1000--.txt");

    // stringGenerator(vec, 5000, 85);

    auto start = high_resolution_clock::now();

    while (getline(myFile, data))
        vec.push_back(data);
    myFile.close();

    it = vec.begin();

    for (; it != vec.end(); ++it) {
        if (it->find(needle) != string::npos)
            cout << "This sentence contains the Keyword ---> " << *it << endl;
        else
            cout << "False" << endl;
    }

    calculate_time(start);

    return EXIT_SUCCESS;
}