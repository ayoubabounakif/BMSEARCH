/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:38:15 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/28 13:10:17 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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

# include <pthread.h>

using namespace std;
using namespace std::chrono;

vector<string>  parse( string path );
void            naiveSearch( string pat, string txt );
void            naiveOptimizedSearch( string pat, string txt );
void            boyerMooreSearch( string text, string pat );