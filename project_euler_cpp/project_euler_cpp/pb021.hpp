//
//  pb021.hpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 23.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#ifndef pb021_hpp
#define pb021_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

void divisors(std::vector<int> &d,int n);
int sum_div(std::vector<int> &d);
void amicable(std::vector<int> &ami, int min, int max);
void pb021();

#endif /* pb021_hpp */
