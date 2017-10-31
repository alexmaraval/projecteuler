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
    
    int n = 37;
    
    long long int Tr = 0;
    time_t start_rec, end_rec;
    start_rec = clock();
    Tr = recursive_tribonacci(n);
    end_rec = clock();
    double dr = difftime(end_rec, start_rec) / CLOCKS_PER_SEC;
    std::cout << "T(" << n << ") = " << Tr << " in " << dr << " second(s), CPU time." << std::endl;
    
    long long int Ti = 0;
    time_t start_iter, end_iter;
    start_iter = clock();
    Ti = iterative_tribonacci(n);
    end_iter = clock();
    double di = difftime(end_iter, start_iter)/ CLOCKS_PER_SEC;
    std::cout << "T(" << n << ") = " << Ti << " in " << di << " second(s), CPU time." << std::endl;
    
    bigint Tb;
    time_t start_big_iter, end_big_iter;
    start_big_iter = clock();
    Tb = big_iterative_tribonacci(n);
    end_big_iter = clock();
    double dbi = difftime(end_big_iter, start_big_iter)/ CLOCKS_PER_SEC;
    std::cout << "T(" << n << ") = " << Tb << " in " << dbi << " second(s), CPU time." << std::endl;
    return 0;
}
