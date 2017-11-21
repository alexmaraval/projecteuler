//
//  pb019.cpp
//  project_euler_cpp
//
//  Created by Alexandre Maraval on 21.11.17.
//  Copyright © 2017 Alexandre Maraval. All rights reserved.
//

#include "pb019.hpp"

std::ostream &operator<<(std::ostream &os, Date const &d)
{
    if(d._day<10) { os << "0"; }
    os << d._day << "/" ;
    if(d._month<9) { os << "0"; }
    os << 1+d._month << "/" << d._year << " or " << days[d._weekday] << " the ";
    if(d._day<10) { os << "0"; }
    os << d._day << " of " << months[d._month] << " " << d._year;
    return os;
}

Date::Date(int d, int m, int y, int wd)
{
    _day = d;
    _month = m;
    _year = y;
    _weekday = wd;
    _leap_year = 0;
}

int Date::get_day()
{
    return _day;
}

int Date::get_wd()
{
    return _weekday;
}

int Date::get_month()
{
    return _month;
}

int Date::get_year()
{
    return _year;
}

void Date::next_day()
{
    _weekday = (_weekday+1)%7;
    if(_month == 0 or _month == 2 or _month == 4 or _month == 6 or _month == 7 or _month == 9 or _month == 11)
    {
        if(_day == 31)
        {
            _day = 1;
            _month = (_month+1)%12;
            if(_month == 0)
            {
                _year++;
                if(_year%4 == 0) _leap_year = 1;
            }
        }
        else {_day++;}
    }
    else if(_month == 3 or _month == 5 or _month == 8 or _month == 10)
    {
        if(_day == 30)
        {
            _day = 1;
            _month++;
        }
        else {_day++;}
    }
    else
    {
        if(_leap_year)
        {
            if(_day == 29)
            {
                _day = 1;
                _month++;
            }
            else {_day++;}
        }
        else
        {
            if(_day == 28)
            {
                _day = 1;
                _month++;
            }
            else {_day++;}
        }
    }
}

void pb019()
{
    Date d(1,1,1901);
    int count = 0;
    for(int i=0; i<36565; i++)
    {
        d.next_day();
        if(d.get_wd() == 6 and d.get_day() == 1) count++;
        //std::cout << "The date is " << d << " and the count is " << count << std::endl;
    }
    std::cout << "PB019 : number of Sundays starting a month during the 20th century is : " << count << std::endl;
}
