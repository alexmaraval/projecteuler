//
//  main.cpp
//  prime numbers
//
//  Created by Alexandre Maraval on 14.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include <iostream>
#include "eratosthene.hpp"

int main(int argc, const char * argv[])
{
    std::vector<long int> v;
    long int n = 100000000;
    eratos1(v, n);
    print_vec(v);
    
    return 0;
}
