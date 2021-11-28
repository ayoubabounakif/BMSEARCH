/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabounak <aabounak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:41:03 by aabounak          #+#    #+#             */
/*   Updated: 2021/11/27 19:49:38 by aabounak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Header.hpp"

vector<string> parse( string path ) {
    vector<string> tmp;
    string data;
    ifstream myFile(path);
    while (getline(myFile, data))
        tmp.push_back(data);
    myFile.close();
    return tmp;
}