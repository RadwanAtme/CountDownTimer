#ifndef COUNTDOWN_DATE_H
#define COUNTDOWN_DATE_H

#include <vector>
#include <iostream>

enum TimeType{
    SECOND,
    MINUTE,
    HOUR,
    DAY,
    MONTH,
    YEAR,
    ARRAY_LENGTH
};

class Date{
    std::vector<int> array;
public:
    Date(int year,int month,int day,int hour,int minute,int second);
    Date();
    ~Date() = default;
    Date(const Date& date) = default;
    Date& countDown();
    void printDate()const;
    Date operator-(const Date& date)const;
    Date& operator-=(const Date& date);
    bool dateISZero()const;
    bool operator<(const Date& date)const;
    void fillDays(int days);
    void fillHours(int seconds);

    static int dateToDays(const Date& date);
    static int dateToSeconds(const Date& date);
    static int daysInYear(int year);
    static int daysInMonth(int month, int year);
    static int isLoopYear(int year);







    };
#endif //COUNTDOWN_DATE_H
