#include <iostream>
#include <string>

using namespace std;

string checkStudnetStatus(int e_hr, int e_min, int s_hr, int s_min);

int main()
{
    int e_hr,e_min,s_hr,s_min;
    cout << "Exam Starting Time (Hour): ";
    cin >> e_hr;
    cout << "Exam Starting Time (Minute): ";
    cin >> e_min;
    cout << "Student hour of arrival: ";
    cin >> s_hr;
    cout << "Student minute of arrival: ";
    cin >> s_min;
    cout << checkStudnetStatus(e_hr, e_min, s_hr, s_min);
    return 0;
}

string checkStudnetStatus(int e_hr, int e_min, int s_hr, int s_min)
{
    int dif;
    if ((s_hr*60 + s_min) > (e_hr*60 + e_min))
    {
        dif = (s_hr - e_hr)*60 + s_min - e_min;
        if (dif >= 60)
            return "Late\n" + to_string(dif/60) + ":" + to_string(dif%60) + " hours after the start.";
        else
            return "Late\n" + to_string(dif) + " minutes after the start.";
    }
    else if ((s_hr*60 + s_min + 30) >= (e_hr*60 + e_min))
    {
        dif = (e_hr - s_hr)*60 + e_min - s_min;
        if (dif != 0)
            return "On time\n" + to_string(dif) + " minutes before the start.";
        else
            return "On time";
    }
    else if ((s_hr*60 + s_min + 30) < (e_hr*60 + e_min))
    {
        dif = (e_hr - s_hr)*60 + e_min - s_min;
        if (dif >= 60)
            return "Early\n" + to_string(dif/60) + ":" + to_string(dif%60) + " hours before the start.";
        else
            return "Early\n" + to_string(dif) + " minutes before the start.";
    }
}