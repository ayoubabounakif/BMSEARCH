/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:38:15 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 17:30:39 by aabounak         ###   ########.fr       */
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

using namespace std;
using namespace std::chrono;

void    naiveOptimizedSearch( string pat, string txt );
void    boyerMooreSearch( string text, string pat );