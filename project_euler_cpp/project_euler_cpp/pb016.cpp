//
//  pb016.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 04.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb016.hpp"

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------- CORE FUNCTIONS --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

std::string manual_sum(const std::string &a, const std::string &b)
{
    std::string sum = "";                                   // result of the sum
    std::string _a = a, _b = b;                             // temporary copies of arguments
    
    while(_a.size() < _b.size())                            // adjust size of _a
    {
        _a = "0" + _a;
    }
    while(_a.size() > _b.size())                            // adjust size of _b
    {
        _b = "0" + _b;
    }
    
    _a = "0" + _a;                                          // add one 0 in front of both _a and _b in case we have a
    _b = "0" + _b;                                          // remainder at the last iteration of the following loop
    int s = 0, d = 0, r = 0;                                // temporary sum, digit and eventual reminder
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        s = (_a[i-1] - '0') + (_b[i-1] - '0') + r;          // sum of digits in column i plus remainder of previous sum, in [0,19]
        d = s%10;                                           // result digit(s)
        sum = std::to_string(d) + sum;
        r = (s-d)/10;                                       // remainder
    }
    
    if (sum[0] == '0')                                      // remove the useless occasional "0" in front of the number
    {
        sum.erase(0,1);
    }
        
    return sum;
}


std::string manual_prod(const std::string &a, const std::string &b)
{
    std::string prod = "";                                  // result of the product
    std::string sum = "";
    std::string _a = a, _b = b;                             // temporary copies of arguments
    
    if(_a.size() > _b.size())                               // exchange _a and _b so that _a is always the smallest
    {
        std::string _c = _b;
        _b = _a;
        _a = _c;
    }
    
    while(_a.size() < _b.size())                            // adjust size of _a filling with zeros to reach size of _b
    {
        _a = "0" + _a;
    }
    
    _a = "0" + _a;                                          // add one 0 in front of both _a and _b in case we have a
    _b = "0" + _b;                                          // remainder at the last iteration of the following loop
    int p = 0, d = 0, r = 0;                                // temporary prod, digit and eventual reminder
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        if(i == _a.size() - a.size()) {break;}              // no need to continue the loop when we reach the part of _a composed of only 0
        
        if(_a[i-1] == '0')                                  // if there is a 0 at the end or in the middle of _a no need to enter the loop
        {
            sum = "0" + sum;
        }
        else
        {
            for(unsigned long j = _a.size(); j>0; j--)
            {
                p = (_a[i-1] - '0') * (_b[j-1] - '0') + r;  // product of digits in column i plus remainder of previous sum, in [0,82]
                d = p%10;                                   // result digit(s)
                prod = std::to_string(d) + prod;
                r = (p-d)/10;                               // remainder
            }
            sum = manual_sum(sum, prod);
        }
        prod.clear();
        prod = std::string(_a.size()-i+1, '0');
    }
    
    while (sum[0] == '0')                                   // remove the useless occasional "0" in front of the number
    {
        sum.erase(0,1);
    }
    
    return sum;
}


// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------- BIGINT CLASS ---------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ----------------------------------------------------------
// -------------------- OSTREAM OPERATOR --------------------
// ----------------------------------------------------------
std::ostream &operator<< (std::ostream &os, const bigint &b)
{
    os << b._number;
    return os;
}


// ----------------------------------------------------------
// ------------------- CONSTRUCTORS et al -------------------
// ----------------------------------------------------------
bigint::bigint(std::string num){ this->_number = num;}


// ----------------------------------------------------------
// ---------------------- GET FUNCTION ----------------------
// ----------------------------------------------------------
std::string bigint::get_str_num()
{
    return (this->_number);
}

// ----------------------------------------------------------
// ----------------------- OPERATORS ------------------------
// ----------------------------------------------------------
bigint bigint::operator+(const bigint &b)
{
    return bigint(manual_sum(this->_number, b._number));
}


bigint bigint::operator*(const bigint &b)
{
    return bigint(manual_prod(this->_number,b._number));
}


// ----------------------------------------------------------
// ------------------ ASSIGNMENT OPERATORS ------------------
// ----------------------------------------------------------
bigint &bigint::operator= (const bigint &b)
{
    if(this != &b)
    {
        this->_number = b._number;
    }
    return *this;
};


bigint &bigint::operator= (const std::string &s)
{
    if(this->_number != s)
    {
        this->_number = s;
    }
    return *this;
};

// ----------------------------------------------------------
// ------------------- OPERATORS WITH INT -------------------
// ----------------------------------------------------------
bigint bigint::operator+(const int &n)
{
    return bigint(manual_sum(this->_number, std::to_string(n)));
}


bigint bigint::operator*(const int &n)
{
    return bigint(manual_prod(this->_number,std::to_string(n)));
}


int bigint::digit_sum()
{
    int dsum = 0;
    
    for(int i = 0; i<_number.size(); i++)
    {
        dsum += _number[i] - '0';
    }
    return dsum;
}

// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------- PB016 SOLUTION --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void pb016()
{
    bigint n("2");
    
    std::cout << "2^1 = " << n << "." << std::endl;
    for (int i=2; i<=1000; i++)
    {
        n = n * 2;
        //std::cout << "sum of digits of 2^" << i << " = " << n.digit_sum() << std::endl;
    }
    std::cout << "PB016: sum of digits of 2^100 = " << n.digit_sum() << std::endl;
}
