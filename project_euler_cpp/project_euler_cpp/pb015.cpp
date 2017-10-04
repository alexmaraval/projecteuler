//
//  pb015.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 04.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb015.hpp"

long int nb_paths(int n) // only works for square grids
{
    long int nbp = 0;
    std::vector<long int> row = {};
    
    for(int i=1; i<=n+1; i++)
    {
        row.push_back(i);
    }
    
    if(n <= 1)
    {
        nbp = n;
    }
    else
    {
        int count = n;
        while(count > 1)
        {
            for(int k=1; k<row.size(); k++)
            {
                row[k] = row[k] + row[k-1];
            }
            count--;
        }
        nbp = row[row.size()-1];
    }
    
    return nbp;
}

void pb015()
{
    int n = 20;
    printf("PB015: total number of paths in %d x %d grid is: %ld\n", n, n, nb_paths(n));
}
