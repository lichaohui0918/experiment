#include<iostream>
using namespace std;
class Date
{private:
    int year,  month,  day;
public:
    Date(int=2006 , int=10 , int=17 );
    void Display( );
};
Date::Date(int y, int m, int d )               		£º
{   cout<<"Executing constructor¡­\n";

    year = y;
    month = m;
    day = d;
}
void Date::Display()
{   cout<< year << "-" << month << "-" << day << endl;
}
int main()
{   Date today;
    cout<<"Today is:";
    today.Display();
    return 0;
}
