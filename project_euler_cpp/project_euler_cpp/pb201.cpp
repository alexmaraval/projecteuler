//
//  pb201.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 04.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb201.hpp"

void print_vec(std::vector<int> &v)
{
    for(long int i=0; i<v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void pb201()
{
    std::vector<int> S = {1};
    for(int i=2; i<=100; i++)
    {
        S.push_back(i*i);
    }
    print_vec(S);
}
