//
//  pb017.hpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 08.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#ifndef pb017_hpp
#define pb017_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void number_decompose(int n, std::vector<int>& N);
std::string number_to_words(int n);
void decompose_to_words(std::vector<int>& N, std::vector<std::string>& W);
void pb017();

#endif /* pb017_hpp */
