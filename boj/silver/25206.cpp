#include<iostream>
#include<iomanip>
#include<unordered_map>

using namespace std;

unordered_map<string, double> grade_map
{
    {"A+", 4.5}, {"A0", 4.0},
    {"B+", 3.5}, {"B0", 3.0},
    {"C+", 2.5}, {"C0", 2.0},
    {"D+", 1.5}, {"D0", 1.0},
    {"F", 0.0}
};

int main()
{
    double total_score = 0.0;               
    double total_credit = 0.0;

    for(int i = 0; i<20; i++)
    {
        string _, rating;
        double grade;
        cin >> _ >> grade >> rating;

        if(rating == "P")
            continue;

        total_score += grade * grade_map[rating];
        total_credit += grade;
    }

    cout << fixed << setprecision(6) << total_score/total_credit;
}