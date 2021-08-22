#ifndef COUNTDOWN_COUNTDOWNTIMER_H
#define COUNTDOWN_COUNTDOWNTIMER_H

#include "Date.h"
#include <ctime>
#include <iostream>
#include <string>

class CountDownTimer {
    Date expected_date;
    Date time_difference;
public:
    CountDownTimer():expected_date(Date()),time_difference(Date()){}
    ~CountDownTimer() = default;
    void requestEventDate();
    bool countIsFinished()const;
    void countDown();
    void printTimer()const;

    static Date stringToDate(const std::string& time);
    static int stringToMonth(const std::string& month);
    static int stringToNum(const std::string& string);
    static int charToNum(const char& num);
    static int stringToYear(const std::string& string);

};


#endif //COUNTDOWN_COUNTDOWNTIMER_H
