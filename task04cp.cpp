#include <iostream>
#include <string>
using namespace std;

float calculateBill(char s_code,char time,float min);

int main()
{
    char s_code,time = 'd';
    float min;
    cout << "Enter the service code (R/r for regular, P/p for premium): ";
    cin >> s_code;
    if (s_code == 'P' || s_code == 'p')
    {
        cout << "Enter the time of the call (D/d for Day, N/n for Night): ";
        cin >> time;
    }
    cout << "Enter the number of minutes used: ";
    cin >> min;
    if (s_code == 'R' || s_code == 'r')
        cout << "Service Type: Regular" << endl;
    if (s_code == 'P' || s_code == 'p')
        cout << "Service Type: Preemium" << endl;
    cout << "Total Minutes Used: " << min << " minutes" << endl;
    cout << "Amount Due: $" << calculateBill(s_code,time,min);
}

float calculateBill(char s_code,char time,float min)
{
    if (s_code == 'P' || s_code == 'p')
    {
        if (time == 'd' || time == 'D')
        {
            if (min <= 75)
                return 25;
            else
                return(25 + (min-75)*0.1);
        }
        else if (time == 'N' || time == 'n')
        {
            if (min <= 100)
                return 25;
            else
                return(25 + (min-100)*0.05);
        }
    }
    else if (s_code == 'R' || s_code == 'r')
    {
        if (min <= 50)
                return 10;
            else
                return(10 + (min-50)*0.2);
    }
} 