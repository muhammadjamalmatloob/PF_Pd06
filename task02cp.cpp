#include <iostream>
#include <string>
using namespace std;

float calculateAverage(float eng,float math,float chem,float ss,float bio);

string calculateGrade(float avg);

int main()
{
    string name;
    float eng,math,chem,ss,bio,percent;
    cout << "Enter Student name: ";
    getline(cin,name);
    cout << "Enter marks for English: ";
    cin >> eng;
    cout << "Enter marks for Mathematics: ";
    cin >> math;
    cout << "Enter marks for Chemistry: ";
    cin >> chem;
    cout << "Enter marks for Social Science: ";
    cin >> ss;
    cout << "Enter marks for Biology: ";
    cin >> bio;
    percent = calculateAverage(eng,math,chem,ss,bio);
    cout << "Student Name: " << name << endl;
    cout << "Percentage: " << percent << endl;
    cout << "Grade: " << calculateGrade(percent);
    return 0;
}

float calculateAverage(float eng,float math,float chem,float ss,float bio)
{
    return (eng+math+chem+ss+bio)/5;
}

string calculateGrade(float avg)
{
    if (avg >=90 && avg <=100)
        return "A+";
    else if (avg >= 80)
        return "A";
    else if (avg >= 70)
        return "B+";
    else if (avg >= 60)
        return "B";
    else if (avg >= 50)
        return "C";
    else if (avg >= 40)
        return "D";
    else if (avg < 40)
        return "F";
}