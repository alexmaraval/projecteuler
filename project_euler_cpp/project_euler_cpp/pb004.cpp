//
//  pb004.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb004.hpp"

void int_to_vec(int n, std::vector<int> &vec)
{
    for(int i=10; i<1e9; i*=10)
    {
        if(n%i != n)
        {
            vec.push_back((n%i)/(i/10));
        }
        if(n%i == n)
        {
            vec.push_back((n%i)/(i/10));
            break;
        }
    }
}

bool is_pal(int n)
{
    std::vector<int> v;
    int_to_vec(n, v);
    int diff = 0;
    
    for(int i=0; i<v.size()/2; i++)
    {
        if(v[i] != v[v.size()-1-i])
        {
            diff++;
        }
    }
    if(diff == 0) {return true;}
    return false;
}

void pb4()
{
    long int pal=0;
    for(int i=100; i<=999; i++)
    {
        for(int j=100; j<=999; j++)
        {
            if(is_pal(i*j) and i*j>pal)
            {
                pal = i*j;
            }
        }
    }
    std::cout << "PB4 : largest palindrome made out of 3-digit numbers : " << pal << std::endl;
}
