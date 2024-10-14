#include <iostream>
#include <string>
using namespace std;

string calculateHotelPrices(string month, int stays);

int main()
{
    string month;
    int stays;
    cout << "Enter month (May, June, July ,August, September, October): ";
    cin >> month;
    cout << "Enter number of stays: ";
    cin >> stays;
    cout << calculateHotelPrices(month, stays);
    return 0;
}

string calculateHotelPrices(string month, int stays)
{
    float studio,apartment;
    if (month == "May" || month == "October")
    {
        studio = 50.0*stays;
        apartment = 65.0*stays;
        if (stays > 14)
        {
             studio = studio - studio*0.3;
             apartment = apartment - apartment*0.1;
        }
        else if (stays > 7)
        {
            studio = studio - studio*0.05;
        }
    }
    else if (month == "June" || month == "September")
    {
        studio = 75.2*stays;
        apartment = 68.7*stays;
        if (stays > 14)
        {
             studio = studio - studio*0.2;
             apartment = apartment - apartment*0.1;
        }
    }
    else if (month == "July" || month == "August")
    {
        studio = 76.0*stays;
        apartment = 77.0*stays;
        if (stays > 14)
        {
             apartment = apartment - apartment*0.1;
        }
    }
    return "Apartment: $" + to_string(apartment) + "\nStudio: $" + to_string(studio);
}