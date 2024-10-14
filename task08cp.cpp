#include <iostream>
using namespace std;

int calculateVolleyBallGames(string year_type, float holidays, float homeWeekends);

int main ()
{
    string yearType;
    float holidays,homeWeekends;
    cout << "Enter year type: ";
    cin >> yearType;
    cout << "Enter holidays: ";
    cin >> holidays;
    cout << "Enter home town weekends: ";
    cin >> homeWeekends;
    cout << calculateVolleyBallGames(yearType,holidays,homeWeekends);
    return 0;
}

int calculateVolleyBallGames(string year_type, float holidays, float homeWeekends)
{
    float volleyBallGames = ((48-homeWeekends)*3)/4 + homeWeekends + (holidays*2)/3;
    if (year_type == "leap")
        volleyBallGames = volleyBallGames + volleyBallGames*0.15;
    return int(volleyBallGames);
}