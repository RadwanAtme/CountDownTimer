#include <iostream>
#include <windows.h>
#include "CountDownTimer.h"

int main(){
    CountDownTimer application;
    application.requestEventDate();
    while(!application.countIsFinished()){
        application.countDown();
        sleep(1);
        application.printTimer();
    }
    std::cout<<"The Event Has Been Reached"<<std::endl;
}