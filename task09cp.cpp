#include <iostream>
using namespace std;

string checkPointPosition(int h, int x, int y);

int main()
{
    int h,x,y;
    cout << "Enter height: ";
    cin >> h;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    cout << checkPointPosition(h, x, y);
    return 0;
}

string checkPointPosition(int h, int x, int y)
{
    if ((y == 0 && x >= 0 && x <= 3*h) ||
    ((x == 0 || x == 3*h) && (y >= 0 && y <= 2)) ||
    ((x == h || x == 2*h) && (y >= h && y <= 4*h)) ||
    ((y == h) && (x >= 0 && x <= h && x >= 2*h && x <= 3*h)) ||
    ((y == 4*h) && (x >= h && x <= 2*h)))
    {
        return "Border";
    }
    else if (((x > 0 && x < 3*h) && (y > 0 && y < h)) ||
    ((x > h && x < 2*h) && (y > h && y < 4*h)))
    {
        return "Inside";
    }
    return "Outside";
}