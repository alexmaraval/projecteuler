//
//  main.cpp
//  tribonacci
//
//  Created by Alexandre Maraval on 31.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include <iostream>
#include "tribonacci.hpp"

int main(int argc, const char * argv[]) {
    long long int Tr = 0, Ti = 0;
    int n = 37;
    time_t start_rec, end_rec;
    start_rec = clock();
    Tr = recursive_tribonacci(n);
    end_rec = clock();
    double dr = difftime(end_rec, start_rec) / CLOCKS_PER_SEC;
    std::cout << "T(" << n << ") = " << Tr << " in " << dr << " second(s), CPU time." << std::endl;
    
    time_t start_iter, end_iter;
    start_iter = clock();
    Ti = iterative_tribonacci(n);
    end_iter = clock();
    double di = difftime(end_iter, start_iter)/ CLOCKS_PER_SEC;
    std::cout << "T(" << n << ") = " << Ti << " in " << di << " second(s), CPU time." << std::endl;
    return 0;
}
