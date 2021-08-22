#include "CountDownTimer.h"

bool CountDownTimer::countIsFinished() const{
    return time_difference.dateISZero();
}

void CountDownTimer::countDown() {
    time_difference.countDown();
}

void CountDownTimer::requestEventDate() {
    std::cout<<"Please Enter The Event Date in The following Order: Year,Month,Day,Hour,Minute,Second"<<std::endl;
    int year,day,month,hour,minute,second;
    std::cin>>year>>month>>day>>hour>>minute>>second;
    expected_date = Date(year,month,day,hour,minute,second);
    //std::cout<<"Please Enter The Current Date in The following Order: Year,Month,Day,Hour,Minute,Second"<<std::endl;
   // std::cin>>year>>month>>day>>hour>>minute>>second;

   // get the current time using time_t library
   std::time_t current_time;
   current_time = time(nullptr);
   std::string time_in_string = ctime(&current_time);

    Date date = stringToDate(time_in_string);
    time_difference = expected_date - date;
}

Date CountDownTimer::stringToDate(const std::string& time){
    int year,month,day,hour,second,minute;
    month = stringToMonth(time.substr(4,3));
    day = stringToNum(time.substr(8,2));
    hour = stringToNum(time.substr(11,2));
    minute = stringToNum(time.substr(14,2));
    second = stringToNum(time.substr(17,2));
    year = stringToYear(time.substr(20,4));
    return Date(year,month,day,hour,minute,second);
}

int CountDownTimer::stringToYear(const std::string& string){
    int year = 0;
    int multiplier = 1;
    for(int i=3;i>=0;i--){
        year += charToNum(string[i]) * multiplier;
        multiplier *= 10;
    }
    return year;
}

int CountDownTimer::stringToNum(const std::string& string){
    int num = charToNum(string[0]) * 10 + charToNum(string[1]);
    return num;
}

int CountDownTimer::charToNum(const char& num){
    switch(num){
        case '0':return 0;
        case '1':return 1;
        case '2':return 2;
        case '3':return 3;
        case '4':return 4;
        case '5':return 5;
        case '6':return 6;
        case '7':return 7;
        case '8':return 8;
        case '9':return 9;
        default: return -1; // change to throwing exceptions

    }
}

int CountDownTimer::stringToMonth(const std::string& month){
    if(month == "Jan")return 1;
    if(month == "Feb")return 2;
    if(month == "Mar")return 3;
    if(month == "Apr")return 4;
    if(month == "May")return 5;
    if(month == "Jun")return 6;
    if(month == "Jul")return 7;
    if(month == "Aug")return 8;
    if(month == "Sep")return 9;
    if(month == "Oct")return 10;
    if(month == "Nov")return 11;
    if(month == "Dec")return 12;
    return -1; // change to throwing exceptions

}

void CountDownTimer::printTimer() const{
    time_difference.printDate();
}