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
    d.clear();
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
        {
            d.push_back(i);
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
void amicable(std::vector<int> &ami, int min, int max)
{
    ami.clear();
    std::vector<int> div_list;
    std::vector<int> p(max-min);
    
    for(int i=min; i<=max; i++)
    {
        divisors(div_list, i);
        p[i-min] = sum_div(div_list);
    }
    
    for(int j=0; j<=max-min; j++)
    {
        if(p[j] >= min and p[j] <= max and p[p[j]-min] == j+min and p[j] != j+min)
        {
            ami.push_back(j+min);
        }
    }
}

void pb021()
{
    std::vector<int> d;
    int n = 6;
    divisors(d, n);
    std::cout << std::endl;
    std::cout << "sum of divisors for " << n << " is " << sum_div(d) << std::endl;
    std::cout << std::endl;
    
    n = 28;
    divisors(d, n);
    std::cout << std::endl;
    std::cout << "sum of divisors for " << n << " is " << sum_div(d) << std::endl;
    std::cout << std::endl;
    
    std::cout << "--------------------------" << std::endl;
    std::vector<int> ami;
    amicable(ami, 1,10000);
    
    int total_sum = 0;
    for(int i=0; i<ami.size(); i++)
    {
        std::cout << ami[i] << " ";
        total_sum += ami[i];
    }
    std::cout << std::endl;
    std::cout << "PB021 : Sum of amicable numbers between 1 and 10000 is : " << total_sum << std::endl;

}
