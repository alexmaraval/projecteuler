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
bigint::bigint(std::string num)
{
    while (num[0] == '0')                                       // remove the useless occasional "0" in front of the number
    {
        num.erase(0,1);
    }
    if (num == "") {num = "0";}                                 // replace empty string by zero string
    this->_number = num;
}


// ----------------------------------------------------------
// ---------------------- GET FUNCTION ----------------------
// ----------------------------------------------------------
std::string bigint::get_str_num()
{
    return (this->_number);
}

// ----------------------------------------------------------
// -------------------- LOGICAL OPERATORS -------------------
// ----------------------------------------------------------
bool bigint::operator==(const bigint &b) const
{
    if(_number.size() == b._number.size())
    {
        int i = 0;
        while(_number[i] == b._number[i] and i < _number.size())
        {
            i++;
        }
        return(i == _number.size());
    }
    return false;
}


bool bigint::operator<(const bigint &b) const
{
    if(_number.size() < b._number.size())                       // if string length of this is smaller, number is clearly smaller
    {
        return true;
    }
    else if(_number.size() == b._number.size())                 // if both strings have same length,
    {
        int i = 0;
        while(_number[i] == b._number[i] and i < _number.size())
        {
            i++;                                                // compare each digit until a difference is found
        }
        return(_number[i] < b._number[i]);                      // it will return the result of this logical test (a boolean
    }
    else
    {
        return false;
    }
}


bool bigint::operator>(const bigint &b) const                   // returns the negation of the < operator
{
    return(!(*this < b));
}


bool bigint::operator<=(const bigint &b) const
{
    return(*this == b or *this < b);
}


bool bigint::operator>=(const bigint &b) const
{
    return(*this == b or *this > b);
}

// ----------------------------------------------------------
// ------------------ ARITHMETIC OPERATORS ------------------
// ----------------------------------------------------------
bigint bigint::operator+(const bigint &b) const
{
    std::string sum = "";                                       // result of the sum
    std::string _a = _number, _b = b._number;                   // temporary copies of arguments
    
    while(_a.size() < _b.size())                                // adjust size of _a
    {
        _a = "0" + _a;
    }
    while(_a.size() > _b.size())                                // adjust size of _b
    {
        _b = "0" + _b;
    }
    _a = "0" + _a;                                              // add one 0 in front of both _a and _b in case we have a
    _b = "0" + _b;                                              // remainder at the last iteration of the following loop
    
    int s = 0, d = 0, r = 0;                                    // temporary sum, digit and eventual reminder
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        s = (_a[i-1] - '0') + (_b[i-1] - '0') + r;              // sum of digits in column i plus remainder of previous sum, in [0,19]
        d = s%10;                                               // result digit(s)
        sum = std::to_string(d) + sum;
        r = (s-d)/10;                                           // remainder
    }
    
    return bigint(sum);
}


bigint bigint::operator-(const bigint &b) const
{
    std::string diff = "";                                      // result of the difference
    std::string _a = _number, _b = b._number;                   // temporary copies of arguments
    std::string sign_flip_flag = "";
    
    if (*this < b)                                              // swap numbers if *this is smaller than b
    {
        std::string temp(_a);
        _a = _b;
        _b = temp;
        sign_flip_flag = "-";                                   // keep track we have swapped numbers
    }
    
    while(_a.size() < _b.size())                                // adjust size of _a
    {
        _a = "0" + _a;
    }
    while(_a.size() > _b.size())                                // adjust size of _b
    {
        _b = "0" + _b;
    }
    
    int s = 0, d = 0, r = 0;                                    // temporary sum, digit and eventual reminder
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        s = (_a[i-1] - '0') - (_b[i-1] - '0') + r;
        
        if(s<0)                                                 // distinguish cases when sum is < 0 or >= 0
        {
            s += 10;
            d = s%10;
            r = -1;
            diff = std::to_string(d) + diff;
        }
        else
        {
            d = s%10;
            diff = std::to_string(d) + diff;
            r = (s-d)/10;
        }
    }
    
    return bigint(sign_flip_flag + bigint(diff)._number);
}


bigint bigint::operator*(const bigint &b) const
{
    std::string prod = "";                                      // result of the product
    std::string sum = "";
    std::string _a = _number, _b = b._number;                   // temporary copies of arguments
    
    if(_a.size() > _b.size())                                   // exchange _a and _b so that _a is always the smallest
    {
        std::string _c = _b;
        _b = _a;
        _a = _c;
    }
    
    while(_a.size() < _b.size())                                // adjust size of _a filling with zeros to reach size of _b
    {
        _a = "0" + _a;
    }
    
    _a = "0" + _a;                                              // add one 0 in front of both _a and _b in case we have a
    _b = "0" + _b;                                              // remainder at the last iteration of the following loop
    int p = 0, d = 0, r = 0;                                    // temporary prod, digit and eventual reminder
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        if(i == _a.size() - _number.size()) {break;}            // no need to continue the loop when we reach the part of _a composed of only 0
        
        if(_a[i-1] == '0')                                      // if there is a 0 at the end or in the middle of _a no need to enter the loop
        {
            sum = "0" + sum;
        }
        else
        {
            for(unsigned long j = _a.size(); j>0; j--)
            {
                p = (_a[i-1] - '0') * (_b[j-1] - '0') + r;      // product of digits in column i plus remainder of previous sum, in [0,89]
                d = p%10;                                       // result digit(s)
                prod = std::to_string(d) + prod;
                r = (p-d)/10;                                   // remainder
            }
            sum = (bigint(sum) + bigint(prod))._number;
        }
        prod.clear();
        prod = std::string(_a.size()-i+1, '0');
    }
    
    return bigint(sum);
}

bigint bigint::operator^(const bigint &b) const
{
    bigint i("1");
    bigint pow = *this;
    
    while (i<b)
    {
        pow *= *this;
        i++;
    }
    return pow;
}


// ----------------------------------------------------------
// ------------------ UNILATERAL OPERATORS ------------------
// ----------------------------------------------------------
bigint bigint::operator- () const
{
    return bigint("-" + _number);
}


bigint bigint::operator+ () const
{
    return bigint(_number);
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

bigint &bigint::operator++()
{
    *this = *this + 1;
    return *this;
}


bigint &bigint::operator++(int)
{
    return ++*this;
}


bigint &bigint::operator--()
{
    *this = *this - 1;
    return *this;
}


bigint &bigint::operator--(int)
{
    return --*this;
}


bigint &bigint::operator+=(const bigint &b)
{
    *this = *this + b;
    return *this;
}


bigint &bigint::operator-=(const bigint &b)
{
    *this = *this - b;
    return *this;
}


bigint &bigint::operator*=(const bigint &b)
{
    *this = *this * b;
    return *this;
}


// ----------------------------------------------------------
// ------------------- OPERATORS WITH INT -------------------
// ----------------------------------------------------------
bigint bigint::operator+(const int &n) const
{
    return (*this + bigint(std::to_string(n)));
}


bigint bigint::operator-(const int &n) const
{
    return (*this - bigint(std::to_string(n)));
}


bigint bigint::operator*(const int &n) const
{
    return (*this * bigint(std::to_string(n)));}



// ----------------------------------------------------------
// ------------------------- METHODS ------------------------
// ----------------------------------------------------------

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
    
    for (int i=2; i<=1000; i++)
    {
        n = n * 2;
        //std::cout << "sum of digits of 2^" << i << " = " << n.digit_sum() << std::endl;
    }
    std::cout << "PB016: sum of digits of 2^1000 = " << n.digit_sum() << std::endl;
}
