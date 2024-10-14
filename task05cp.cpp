#include <iostream>
using namespace std;

float calculateFruitprice(string f,string d,int q);

int main()
{
    string f,day;
    int quantity;
    cout << "Enter fruit name: ";
    cin >> f;
    cout << "Enter day of the week (e.g. Monday, Tuesday): ";
    cin >> day;
    cout << "Enter the quantity: ";
    cin >> quantity;
    if ((day == "Monday" || day == "Tuesday" || day == "Wednesday" || day == "Thursday" || day == "Friday" 
    || day == "Saturday" || day == "Sunday") && (f == "banana" || f == "apple" ||f == "orange" 
    || f == "grapefruit" || f == "kiwi" || f == "pineapple" || f == "grapes"))
    {
        cout << calculateFruitprice(f,day,quantity);
    } 
    else 
        cout << "error";
    return 0;
}

float calculateFruitprice(string f,string d,int q)
{
    if (d != "Sunday" && d != "Saturday")
    {
        if (f == "banana")
            return 2.5*q;
        else if (f == "apple")
            return 1.2*q;
        else if (f == "orange") 
            return  0.85*q;
        else if (f == "grapefruit") 
            return  1.45*q;
        else if (f == "kiwi") 
            return  2.7*q;
        else if (f == "pineapple")
            return  5.5*q;  
        else if (f == "grapes")
            return  3.85*q;
    }
    else
    {
        if (f == "banana")
            return 2.7*q;
        else if (f == "apple")
            return 1.25*q;
        else if (f == "orange") 
            return 0.9*q;
        else if (f == "grapefruit") 
            return 1.6*q;
        else if (f == "kiwi") 
            return 3.0*q;
        else if (f == "pineapple")
            return 5.6*q;
        else if (f == "grapes")
            return 4.2*q;
    }
}