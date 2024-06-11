#include<iostream>
#include<string>
using namespace std;

class Time {
    private:
    int hour;
    int minute;
    int second;

    public:
    Time(int hour, int minute, int second){
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    void SetTime(int hour, int minute, int second){
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    int getHour(){
        return hour;
    }
    void setHour(int hour){
        this->hour = h;
    }
    int GetMinute(){
        return minute;
    }
    void setMinute(int minute){
        this->minute = m;
    }
    int getSecond(){
        return second;
    }
    void setSecond(int second){
        this->second=s;
    }
    void previousSecond(){
        if(hour == 0 && minute == 0 && second == 0){
            hour = 23;
            minute = 59;
            second = 59;
            return;
        }
        if(minute == 0 && second == 0){
            hour --;
            minute = 59;
            second = 59;
            return;
        }
        if(second == 0){
            minute --;
            second = 59;
            return;
        }
        second--;
    }
    void nextSecond(){
        if (hour == 23&& minute == 59 && second == 59){
            hour = 0;
            minute = 0;
            second = 0;
            return;
        }
        if (second == 59){
            minute++;
            second = 0;
            return;
        }
        second++;
    }
    void display(){
        string hour = to string(this->hour);
        string minute = to string(this->minute);
        string second = to string(this->second);
        if(hour.length() == 1)
        hour = "0"+hour;
        if(minute.length() == 1)
        minute = "0"+minute;
        if(second.length() == 1)
        second = "0"+second;
        cout<<hour +":" <<minute + ":" + second << endl;
    }
}