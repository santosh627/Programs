#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int convert (string tmp)
{
    tmp = tmp.replace(2,1,"");
    tmp = tmp.replace(4,1,"");
    return atoi(tmp.c_str());
}

void calDiff (string s1, string s2)
{
    int time1 = convert(s1);
    int time2 = convert(s2);

    int hr = time1/10000 - time2/10000 -1;
    int minutes = (time1%10000)/100 - (time2%10000)/100 + 60 -1;
    if (minutes >= 60)
    {
        hr++;
        minutes = minutes - 60;
    }

    int seconds = (time1%100) - (time2%100) +60;
    if (seconds >= 60)
    {
        minutes++;
        seconds = seconds - 60;
    }

    cout << "Time difference:-> "<<hr<<":"<<minutes<<":"<<seconds<<endl;
}

int main()
{
    string str1 = "12:02:18";
    string str2 = "11:03:15";
    calDiff (str1, str2);
    cout << "Hello world!" << endl;
    return 0;
}
