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
	cout<<"���øú����Ķ����thisָ����";
    cout<<this<<endl;
    cout<<"��ǰ����year��Ա����ʼ��ַ: ";
    cout<<&year<<endl;
    cout<<"��ǰ����month��Ա����ʼ��ַ: ";
    cout<<&month<<endl;
    cout<<"year="<<year<<" ,month="<<month<<endl;
}
int main()
{
	Date DateA , DateB;
    DateA.SetDate(2011,7,24);
    DateB.SetDate(2010,10,1);
    cout<<"DateA��ַ:"<<&DateA<<endl ;
    DateA.Display();
    cout<<"DateB��ַ:"<<&DateB<<endl ;
    DateB.Display();
	return 0;
}
