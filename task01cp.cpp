#include <iostream>
using namespace std;
 
string decideActivity(string t,string h);

int main()
{
    string t,h;
    cout << "Enter temperature (warm/cold): ";
    cin >> t;
    cout << "Enter humidity (dry/humid): ";
    cin >> h;
    cout << "Recommended activity: " << decideActivity(t,h);
}

string decideActivity(string t,string h)
{
    if (t == "warm")
    {
        if (h == "dry")
            return "Play tennis";
        else if (h == "humid")
            return "Swim";
    }
    else if (t == "cold")
    {
         if (h == "dry")
            return "Play basketball";
        else if (h == "humid")
            return "Watch TV";
    }
}
