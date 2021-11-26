/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:59:13 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/26 18:35:52 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ------------------------------------------------------------------ */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

#define ALPHABET_LEN 256
#define max(a, b) ((a < b) ? b : a)

// BAD CHARACTER RULE.
// delta1 table: delta1[c] contains the distance between the last
// character of pat and the rightmost occurrence of c in pat.
//
// If c does not occur in pat, then delta1[c] = patlen.
// If c is at string[i] and c != pat[patlen-1], we can safely shift i
//   over by delta1[c], which is the minimum distance needed to shift
//   pat forward to get string[i] lined up with some character in pat.
// c == pat[patlen-1] returning zero is only a concern for BMH, which
//   does not have delta2. BMH makes the value patlen in such a case.
//   We follow this choice instead of the original 0 because it skips
//   more. (correctness?)
//
// This algorithm runs in alphabet_len+patlen time.
void make_delta1(ptrdiff_t *delta1, uint8_t *pat, size_t patlen) {
    for (int i=0; i < ALPHABET_LEN; i++) {
        delta1[i] = patlen;
    }
    for (int i=0; i < patlen-2; i++) {
        delta1[pat[i]] = patlen-1 - i;
    }
}

// true if the suffix of word starting from word[pos] is a prefix
// of word
bool is_prefix(uint8_t *word, size_t wordlen, ptrdiff_t pos) {
    int suffixlen = wordlen - pos;
    // could also use the strncmp() library function here
    // return ! strncmp(word, &word[pos], suffixlen);
    for (int i = 0; i < suffixlen; i++) {
        if (word[i] != word[pos+i]) {
            return false;
        }
    }
    return true;
}

// length of the longest suffix of word ending on word[pos].
// suffix_length("dddbcabc", 8, 4) = 2
size_t suffix_length(uint8_t *word, size_t wordlen, ptrdiff_t pos) {
    size_t i;
    // increment suffix length i to the first mismatch or beginning
    // of the word
    for (i = 0; (word[pos-i] == word[wordlen-1-i]) && (i < pos); i++);
    return i;
}

// GOOD SUFFIX RULE.
// delta2 table: given a mismatch at pat[pos], we want to align
// with the next possible full match could be based on what we
// know about pat[pos+1] to pat[patlen-1].
//
// In case 1:
// pat[pos+1] to pat[patlen-1] does not occur elsewhere in pat,
// the next plausible match starts at or after the mismatch.
// If, within the substring pat[pos+1 .. patlen-1], lies a prefix
// of pat, the next plausible match is here (if there are multiple
// prefixes in the substring, pick the longest). Otherwise, the
// next plausible match starts past the character aligned with
// pat[patlen-1].
//
// In case 2:
// pat[pos+1] to pat[patlen-1] does occur elsewhere in pat. The
// mismatch tells us that we are not looking at the end of a match.
// We may, however, be looking at the middle of a match.
//
// The first loop, which takes care of case 1, is analogous to
// the KMP table, adapted for a 'backwards' scan order with the
// additional restriction that the substrings it considers as
// potential prefixes are all suffixes. In the worst case scenario
// pat consists of the same letter repeated, so every suffix is
// a prefix. This loop alone is not sufficient, however:
// Suppose that pat is "ABYXCDBYX", and text is ".....ABYXCDEYX".
// We will match X, Y, and find B != E. There is no prefix of pat
// in the suffix "YX", so the first loop tells us to skip forward
// by 9 characters.
// Although superficially similar to the KMP table, the KMP table
// relies on information about the beginning of the partial match
// that the BM algorithm does not have.
//
// The second loop addresses case 2. Since suffix_length may not be
// unique, we want to take the minimum value, which will tell us
// how far away the closest potential match is.
void make_delta2(ptrdiff_t *delta2, uint8_t *pat, size_t patlen) {
    ssize_t p;
    size_t last_prefix_index = patlen-1;

    // first loop
    for (p=patlen-1; p>=0; p--) {
        if (is_prefix(pat, patlen, p+1)) {
            last_prefix_index = p+1;
        }
        delta2[p] = last_prefix_index + (patlen-1 - p);
    }

    // second loop
    for (p=0; p < patlen-1; p++) {
        size_t slen = suffix_length(pat, patlen, p);
        if (pat[p - slen] != pat[patlen-1 - slen]) {
            delta2[patlen-1 - slen] = patlen-1 - p + slen;
        }
    }
}

// Returns pointer to first match.
// See also glibc memmem() (non-BM) and std::boyer_moore_searcher (first-match).
uint8_t* boyer_moore (uint8_t *string, size_t stringlen, uint8_t *pat, size_t patlen) {
    ptrdiff_t delta1[ALPHABET_LEN];
    ptrdiff_t delta2[patlen]; // C99 VLA
    make_delta1(delta1, pat, patlen);
    make_delta2(delta2, pat, patlen);

    // The empty pattern must be considered specially
    if (patlen == 0) {
        return string;
    }

    size_t i = patlen - 1;        // str-idx
    while (i < stringlen) {
        ptrdiff_t j = patlen - 1; // pat-idx
        while (j >= 0 && (string[i] == pat[j])) {
            --i;
            --j;
        }
        if (j < 0) {
            return &string[i+1];
        }

        ptrdiff_t shift = max(delta1[string[i]], delta2[j]);
        i += shift;
    }
    return NULL;
}

/* ------------------------------------------------------------------ */

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