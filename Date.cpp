#include "Date.h"

const int STARTING_VALUE = 0;

Date::Date(int year, int month,int day,
        int hour, int minute, int second):array(std::vector(ARRAY_LENGTH,STARTING_VALUE)){
    array[YEAR] = year;
    array[MONTH] = month;
    array[HOUR] = hour;
    array[DAY] = day;
    array[MINUTE] = minute;
    array[SECOND] = second;
}

Date::Date():array(std::vector(ARRAY_LENGTH,STARTING_VALUE)){}

/*
 * returns the date minus 1 second
 * if the seconds are 0 we decrement the minutes by 1 and turn the seconds to 59 and so on
 */
Date& Date::countDown() {
    bool carry = true;
    int i=0;
    if(dateISZero()){
        return *this;
    }else{
        while((carry)&&(i<ARRAY_LENGTH)){
            if(array[i] == 0){
                array[i] = 59;
                i++;
                continue;
            }else{
                array[i] -= 1;
                carry = false;
            }
        }
        return *this;
    }

}



Date& Date::operator-=(const Date &date) {
    *this = (*this) - date;
    return *this;
}

bool Date::dateISZero()const {
    for(int i=0;i<ARRAY_LENGTH;i++){
        if(array[i]!=0){
            return false;
        }
    }
    return true;
}

void Date::printDate()const {
    std::cout<<"Months:"<<array[MONTH]<<" Days:"<<array[DAY]<<" Hours:"<<array[HOUR]<<
                    " Minutes:"<<array[MINUTE]<<" Seconds"<<array[SECOND]<<std::endl;
}

bool Date::operator<(const Date &date)const {
    for(int i=ARRAY_LENGTH-1;i>=0;){
        if(array[i]<date.array[i]){
            return true;
        }else if(array[i]>date.array[i]){
            return false;
        }else{
            i--;
        }
    }
    return false;
}


Date Date::operator-(const Date &date)const {
    if(*this < date){
        // if the date is already reached we just have to return date with all zeros
        return Date();
    }else{
        int date1_days = dateToDays(*this);
        int date2_days = dateToDays(date);
        int date1_seconds = dateToSeconds(*this);
        int date2_seconds = dateToSeconds(date);
        int new_date_days = date1_days - date2_days;
        int new_date_seconds = date1_seconds - date2_seconds;
        if(new_date_seconds < 0){
            new_date_days -= 1;
            new_date_seconds += 86400;
        }
        Date new_date;
        new_date.fillDays(new_date_days);
        new_date.fillHours(new_date_seconds);
        return new_date;
    }
}

void Date::fillHours(int seconds) {
    array[HOUR] = seconds / 3600;
    seconds = seconds - 3600 * array[HOUR];
    array[MINUTE] = seconds / 60;
    array[SECOND] = seconds % 60;
}
void Date::fillDays(int days) {
    array[DAY] = days % 30;
    array[MONTH] = days / 30;
}

int Date::dateToDays(const Date& date){
    int days=0;
    days += date.array[DAY];
    for(int month=1;month<date.array[MONTH];month++){
        days += daysInMonth(month,date.array[YEAR]);
    }
    days += daysInYear(date.array[YEAR]);
    return days;
}

int Date::dateToSeconds(const Date& date){
    int seconds =0;
    seconds += date.array[SECOND];
    seconds += date.array[MINUTE] * 60;
    seconds += date.array[HOUR] * 60 * 60;
    return seconds;
}

int Date::daysInYear(int year){
    return (365*year + year/4 );
}

int Date::daysInMonth(int month, int year){
    switch(month){
        case 1:return 31;
        case 2:return isLoopYear(year) + 28;
        case 3:return 31;
        case 4:return 30;
        case 5:return 31;
        case 6:return 30;
        case 7:return 31;
        case 8:return 31;
        case 9:return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
        default: return 0;

    }
}

int Date::isLoopYear(int year){
    if(year%4==0){
        if(year%100==0){
            if(year%400==0){
                return 1;
            }
        }
    }
    return 0;
}