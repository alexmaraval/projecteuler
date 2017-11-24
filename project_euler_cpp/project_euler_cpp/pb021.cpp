//
//  pb021.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 23.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb021.hpp"
// finds all the divisors of a positive integer and stores into a vecor
void divisors(std::vector<int> &d,int n)
{
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
        {
            d.push_back(i);
            std::cout << i << " divides " << n << std::endl;
        }
    }
}

int sum_div(std::vector<int> &d)
{
    int sum = 0;
    for(int i=0; i<d.size(); i++)
    {
        sum += d[i];
    }
    return sum;
}

// finds the divisors of all numbers between min and max, then sums them and list them in a 2D vector,
// i.e. if we call (as in the exercise) d(n) the sum of the proper divisors of n, we store the pair (n, d(n)).
void amicable(std::vector<std::vector<int>> &pair, int min, int max)
{
    pair.clear();
    std::vector<int> r = {0};
    pair.push_back(r);
    pair[0].push_back(0);
    
    std::vector<int> div_list;
    std::vector<int> p;
    for(int i=0; i<max-min; i++)
    {
        divisors(div_list, i);
        p[i] = sum_div(div_list);
        std::cout << p[i] << std::endl;
        std::cout << std::endl;
    }
    for(int j=0; j<max-min; j++)
    {
        if(p[j] == j+min)
        {
            pair[0][j] = j+min;
            pair[1][j] = p[j];
        }
    }
}

void pb021()
{
    std::vector<int> d;
    int n = 225;
    divisors(d, n);
    std::cout << std::endl;
    std::cout << "sum of divisors for " << n << " is " << sum_div(d) << std::endl;
    std::cout << std::endl;
    
    n = 284;
    divisors(d, n);
    std::cout << std::endl;
    std::cout << "sum of divisors for " << n << " is " << sum_div(d) << std::endl;
    std::cout << std::endl;
    
//    amicable(1,10);
}
