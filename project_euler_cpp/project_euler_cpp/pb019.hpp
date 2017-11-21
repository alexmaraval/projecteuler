//
//  pb019.hpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 21.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#ifndef pb019_hpp
#define pb019_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

static std::vector<std::string> days =
{
    "Monday   ",
    "Tuesday  ",
    "Wednesday",
    "Thursday ",
    "Friday   ",
    "Saturday ",
    "Sunday   "
};
static std::vector<std::string> months =
{
    "January  ",
    "February ",
    "March    ",
    "April    ",
    "May      ",
    "June     ",
    "July     ",
    "August   ",
    "September",
    "October  ",
    "November ",
    "December "};

class Date
{
    friend std::ostream &operator<<(std::ostream &os, Date const &d);
private:
    int _day;
    int _month;
    int _year;
    int _weekday;
    bool _leap_year;
public:
    Date(int d = 1, int m = 0, int y = 1900, int wd = 0);
    bool check_date();
    void next_day();
    int get_day();
    int get_wd();
    int get_month();
    int get_year();
};

void pb019();

#endif /* pb019_hpp */
