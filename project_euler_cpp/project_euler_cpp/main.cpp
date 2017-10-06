//
//  main.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 13.09.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb001.hpp"
#include "pb002.hpp"
#include "pb003.hpp"
#include "pb004.hpp"
#include "pb005.hpp"
#include "pb006.hpp"
#include "pb007.hpp"
#include "pb008.hpp"
#include "pb009.hpp"
#include "pb010.hpp"
#include "pb011.hpp"
#include "pb012.hpp"
#include "pb013.hpp"
#include "pb014.hpp"
#include "pb015.hpp"
#include "pb016.hpp"
#include "pb137.hpp"
#include "pb201.hpp"

int main(int argc, const char * argv[]) {
    
//    pb001();
//    pb002(4000000);
//    pb003(600851475143);
//    pb004();
//    pb005();
//    pb006();
//    pb007();
//    pb008();
//    pb009();
//    pb010();
//    pb011();
//    pb012();
//    pb013();
//    pb014();
//    pb015();
    pb016();
    
//    // logical operators bigint with bigint
//    bool operator==(const bigint &b) const;
//    bool operator<(const bigint &b) const;
//    bool operator>(const bigint &b) const;
//    bool operator<=(const bigint &b) const;
//    bool operator>=(const bigint &b) const;
    
    bigint a("2"), b("10");
    std::cout << (bool) (a == b) << std::endl;
    std::cout << (bool) (a < b) << std::endl;
    std::cout << (bool) (a > b) << std::endl;
    std::cout << (bool) (a <= b) << std::endl;
    std::cout << (bool) (a >= b) << std::endl;
    
//    // arithmetic operators bigint with bigint
//    bigint operator+(const bigint &b) const;
//    bigint operator-(const bigint &b) const;
//    bigint operator*(const bigint &b) const;
//    bigint operator^(const bigint &b) const;
    std::cout << a + b << std::endl;
    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;
    std::cout << (bigint) (a^b) << std::endl;
    
//    // unilateral operator
//    bigint operator-() const;
//    bigint operator+() const;
    
    
//    // assignment and conversion
//    bigint &operator= (const bigint &b);
//    bigint &operator= (const std::string &s);
//    bigint &operator++();
//    bigint &operator--();
//    bigint &operator+=(const bigint &b);
//    bigint &operator-=(const bigint &b);
//    bigint &operator*=(const bigint &b);
    
    
//    // operators bigint with int
//    bigint operator+(const int &n) const;
//    bigint operator-(const int &n) const;
//    bigint operator*(const int &n) const;
    


//    pb137();
//    pb201();
    
    return 0;
}
