//
//  big_class.cpp
//  big
//
//  Created by Alexandre Maraval on 06.10.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "big_class.hpp"
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                                                                                          BIGINT CLASS
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                      OSTREAM OPERATOR
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
std::ostream &operator<< (std::ostream &os, const bigint &b)
{
    os << b._sign << b._number;
    return os;
}


// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                      CONSTRUCTORS et al.
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

// ----------------------------------------------
// CONSTRUCTORS
// ----------------------------------------------
bigint::bigint(std::string num, std::string sign)
{
    _sign = sign;
    if(num[0] == '-')                                                                               // in case user has put the sign in the number directly, allows to initialise bigint a = "-12"
    {
        _sign = "-";
        num.erase(0,1);
    }
    
    _number = num;
    while (_number[0] == '0' and _number.size() > 1)                                                // remove the useless occasional "0" in front of the number
    {
        _number.erase(0,1);
    }
    if (_number == "0") {_sign = "";}
}


// ----------------------------------------------
// COPY CONSTRUCTOR
// ----------------------------------------------
bigint::bigint(const bigint &b)
{
    _sign = b._sign;
    _number = b._number;
}


// ----------------------------------------------
// DESTRUCTOR
// ----------------------------------------------

// ----------------------------------------------
// PRIVATE MANUAL OPERATORS
// ----------------------------------------------


bigint bigint::manual_sum(const bigint &b) const                                                    // just does the sum of two positive integers !!!! manage sign outside of the function
{
    std::string sum = "";                                                                           // result of the sum
    std::string _a = _number, _b = b._number;                                                       // temporary copies of arguments
    int s = 0, d = 0, r = 0;                                                                        // temporary sum, digit and eventual reminder
    while(_a.size() < _b.size()) { _a = "0" + _a; }                                                 // adjust size of _a
    while(_a.size() > _b.size()) { _b = "0" + _b; }                                                 // adjust size of _b
    _a = "0" + _a;                                                                                  // add one 0 in front of both _a and _b in case we have a
    _b = "0" + _b;                                                                                  // remainder at the last iteration of the following loop
    
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        s = (_a[i-1] - '0') + (_b[i-1] - '0') + r;                                                  // sum of digits in column i plus remainder of previous sum, in [0,19]
        d = s%10;                                                                                   // result digit(s)
        sum = std::to_string(d) + sum;
        r = (s-d)/10;                                                                               // remainder
    }
    
    return bigint(sum);
}

bigint bigint::manual_diff(const bigint &b) const                                                   // performs difference of two positive integers
{
    std::string diff = "";                                                                          // result of the difference
    std::string _a = _number, _b = b._number;                                                       // temporary copies of arguments
    int s = 0, d = 0, r = 0;                                                                        // temporary sum, digit and eventual reminder
    std::string sign_flip_flag = "";                                                                // to correct the sign of the result
    
    if (*this < b)                                                                                  // swap numbers if *this is smaller than b
    {
        std::string temp(_a);
        _a = _b;
        _b = temp;
        sign_flip_flag = "-";                                                                       // keep track we have swapped numbers for further correction
    }
    
    while(_a.size() < _b.size()) { _a = "0" + _a; }                                                 // adjust size of _a
    while(_a.size() > _b.size()) { _b = "0" + _b; }                                                 // adjust size of _b
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        s = (_a[i-1] - '0') - (_b[i-1] - '0') + r;
        
        if(s<0)                                                                                     // distinct cases when sum is < 0 or >= 0
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
    return bigint(diff, sign_flip_flag);
}

bigint bigint::manual_prod(const bigint &b) const                                                   // performs the product of integers both positive (or both negative for that matter)
{
    std::string prod = "";                                                                          // result of the product
    std::string sum = "";                                                                           // intermediary sum after each intermediary product
    int p = 0, d = 0, r = 0;                                                                        // temporary prod, digit and eventual reminder
    std::string _a = _number, _b = b._number;                                                       // temporary copies of arguments
    
    if(_a.size() > _b.size())                                                                       // exchange _a and _b so that _a is always the smallest
    {
        std::string _c = _b;
        _b = _a;
        _a = _c;
    }
    
    while(_a.size() < _b.size()) { _a = "0" + _a; }                                                 // adjust size of _a filling with zeros to reach size of _b
    _a = "0" + _a;                                                                                  // add one 0 in front of both _a and _b in case we have a
    _b = "0" + _b;                                                                                  // remainder at the last iteration of the following loop
    
    for(unsigned long i = _a.size(); i>0; i--)
    {
        if(i == _a.size() - _number.size()) {break;}                                                // no need to continue the loop when we reach the part of _a composed of only 0
        if(_a[i-1] == '0') { sum = "0" + sum; }                                                     // if there is a 0 at the end or in the middle of _a no need to enter the loop
        else
        {
            for(unsigned long j = _a.size(); j>0; j--)
            {
                p = (_a[i-1] - '0') * (_b[j-1] - '0') + r;                                          // product of digits in column i plus remainder of previous sum, in [0,89]
                d = p%10;                                                                           // result digit(s)
                prod = std::to_string(d) + prod;
                r = (p-d)/10;                                                                       // remainder
            }
            sum = (bigint(sum) + bigint(prod))._number;
        }
        prod.clear();
        prod = std::string(_a.size()-i+1, '0');
    }
    return bigint(sum);
}

bigint bigint::manual_div(const bigint &b) const
{
    return bigint();
}


// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                        GET FUNCTIONS
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
std::string bigint::get_num()
{
    return _number;
}

std::string bigint::get_sign()
{
    return _sign;
}


// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                     OPERATORS WITH BIGNUM
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

// ----------------------------------------------
// LOGICAL OPERATORS
// ----------------------------------------------
bool bigint::operator<(const bigint &b) const                                                       // Can it be optimised?
{
    if(_sign == "-" and b._sign == "")                                                              // four distinct cases
    {
        return true;
    }
    else if (_sign == "" and b._sign == "-")
    {
        return false;
    }
    else if (_sign == "" and b._sign == "")
    {
        if(_number.size() < b._number.size())
        {
            return true;
        }                                                                                           // if string length of this is smaller, number is clearly smaller
        else if(_number.size() == b._number.size())                                                 // if both strings have same length,
        {
            int i = 0;
            while(_number[i] == b._number[i] and i < _number.size()) { i++; }                       // compare each digit until a difference is found
            return(_number[i] < b._number[i]);                                                      // it will return the result of this logical test (a boolean)
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(_number.size() > b._number.size())
        {
            return true;
        }
        else if(_number.size() == b._number.size())
        {
            int i = 0;
            while(_number[i] == b._number[i] and i < _number.size()) { i++; }
            return(_number[i] > b._number[i]);
        }
        else
        {
            return false;
        }
    }
}


bool bigint::operator==(const bigint &b) const
{
    return(_number == b._number and _sign == b._sign);
}

bool bigint::operator!=(const bigint &b) const
{
    return (!(*this == b));
}

bool bigint::operator>(const bigint &b) const                                                       // returns the negation of the < operator
{
    return(!(*this < b) and !(*this == b));
}


bool bigint::operator<=(const bigint &b) const
{
    return(*this == b or *this < b);
}


bool bigint::operator>=(const bigint &b) const
{
    return(*this == b or *this > b);
}


// ----------------------------------------------
// ARITHMETIC OPERATORS
// ----------------------------------------------
bigint bigint::operator+(const bigint &b) const
{
    bigint _a = *this, _b = b;
    
    if(_sign == b._sign)
    {
        return _a.manual_sum(_b);
    }
    else
    {
        if(_a < _b)
        {
            return _b.manual_diff(-_a);
        }
        else if (_b < _a)
        {
            return _a.manual_diff(-_b);
        }
        else
        {
            return bigint();
        }
    }
}


bigint bigint::operator-(const bigint &b) const
{
    bigint _a = *this, _b = b;
    
    if (_a._sign == "" and _b._sign == "")
    {
        return _a.manual_diff(_b);
    }
    else if (_a._sign == "-" and _b._sign == "")
    {
        return _a + _b;
    }
    else                                                                                            // remain the cases where (_a._sign == "-" or _a._sign == "") and _b._sign == "-"
    {
        return _a + (-_b);                                                                          // whatever the case, the returned operation is the same so we merged both cases
    }
}


bigint bigint::operator*(const bigint &b) const
{
    bigint _a = *this, _b = b;
    
    if (_a._sign == _b._sign)
    {
        return _a.manual_prod(_b);
    }
    else
    {
        return -_a.manual_prod(_b);
    }
}

bigint bigint::operator^(const bigint &b) const
{
    bigint i("1"), pow(*this);
    if (b == bigint()) {return i;}
    while (i<b._number) { pow *= *this; i++; }
    return pow;
}


// ----------------------------------------------
// UNILATERAL OPERATORS
// ----------------------------------------------
bigint bigint::operator- () const
{
    if (_sign == "-") { return bigint(_number); }
    else { return bigint(_number, "-"); }
}


bigint bigint::operator+ () const
{
    return bigint(_number, _sign);
}


// ----------------------------------------------
// INCREMENT OPERATORS
// ----------------------------------------------
bigint &bigint::operator++()
{
    *this = *this + 1;
    return *this;
}


bigint bigint::operator++(int)
{
    bigint temp(*this);
    ++(*this);
    return temp;
}


bigint &bigint::operator--()
{
    *this = *this - 1;
    return *this;
}


bigint bigint::operator--(int)
{
    bigint temp(*this);
    --(*this);
    return temp;
}


// ----------------------------------------------
// ASSIGNMENT OPERATORS
// ----------------------------------------------
bigint &bigint::operator= (const bigint &b)
{
    if(this != &b)
    {
        _number = b._number;
        _sign = b._sign;
    }
    return *this;
};


bigint &bigint::operator= (const std::string &s)
{
    bigint num(s);
    if(*this != num) { *this = num; }
    return *this;
};


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


// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                     OPERATORS WITH INT
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------

// ----------------------------------------------
// LOGICAL OPERATORS
// ----------------------------------------------
bool bigint::operator==(const int &n) const
{
    return (*this == bigint(std::to_string(n)));
//    std::string _n = std::to_string(n);
//    
//    if(_number.size() == _n.size())
//    {
//        int i = 0;
//        while(_number[i] == std::to_string(n)[i] and i < _number.size()) { i++; }
//        return(i == _number.size());
//    }
//    return false;
}

bool bigint::operator!=(const int &n) const
{
    return !(*this == n);
}


bool bigint::operator<(const int &n) const
{
    return (*this < bigint(std::to_string(n)));
//    std::string _n = std::to_string(n);
//    if(_number.size() < std::to_string(n).size()) { return true; }                                  // if string length of this is smaller, number is clearly smaller
//    else if(_number.size() == std::to_string(n).size())                                             // if both strings have same length,
//    {
//        int i = 0;
//        while(_number[i] == std::to_string(n)[i] and i < _number.size()) { i++; }                   // compare each digit until a difference is found
//        return(_number[i] < b._number[i]);                                                          // it will return the result of this logical test (a boolean
//    }
//    else { return false; }
}


bool bigint::operator>(const int &n) const                                                          // returns the negation of the < operator
{
    return(!(*this < n) and !(*this == n));
}


bool bigint::operator<=(const int &n) const
{
    return(*this == n or *this < n);
}


bool bigint::operator>=(const int &n) const
{
    return(*this == n or *this > n);
}



// ----------------------------------------------
// ARITHMETIC OPERATORS
// ----------------------------------------------
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
    return (*this * bigint(std::to_string(n)));
}


// ----------------------------------------------
// ASSIGNMENT OPERATORS
// ----------------------------------------------
bigint &bigint::operator=(const int &n)
{
    bigint t(std::to_string(n));
    if(*this != t)
    {
        *this = t;
    }
    return *this;
}

bigint &bigint::operator+=(const int &n)
{
    return (*this += bigint(std::to_string(n)));
}

bigint &bigint::operator-=(const int &n)
{
    return (*this -= bigint(std::to_string(n)));
}

bigint &bigint::operator*=(const int &n)
{
    return (*this *= bigint(std::to_string(n)));
}


// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
//                                            METHODS
// ---------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------
int bigint::digit_sum()
{
    int dsum = 0;
    
    for(int i = 0; i<_number.size(); i++)
    {
        dsum += _number[i] - '0';
    }
    return dsum;
}
