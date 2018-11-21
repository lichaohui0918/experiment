#include<iostream>
using namespace std;
class Date
{
private:
	int year, month, day;
public:
	void  SetDate(int y,  int m,  int d);
    void  Display( );
};
void Date:: SetDate(int y,  int m,  int d)
{
	year=y;
    month=m;
    day=d;
}
void Date:: SetDate(int y,  int m,  int d)
{
	this->year=y;
    this->month=m;
    this->day=d;
}


void Date::Display( )
{
	cout<<"调用该函数的对象的this指针是";
    cout<<this<<endl;
    cout<<"当前对象year成员的起始地址: ";
    cout<<&year<<endl;
    cout<<"当前对象month成员的起始地址: ";
    cout<<&month<<endl;
    cout<<"year="<<year<<" ,month="<<month<<endl;
}
int main()
{
	Date DateA , DateB;
    DateA.SetDate(2011,7,24);
    DateB.SetDate(2010,10,1);
    cout<<"DateA地址:"<<&DateA<<endl ;
    DateA.Display();
    cout<<"DateB地址:"<<&DateB<<endl ;
    DateB.Display();
	return 0;
}
