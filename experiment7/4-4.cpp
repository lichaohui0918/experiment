#include<iostream>
 using namespace std;
 #include "4_04.h"
 int main()
 {
 	Circle c1(3.5),c2;
 	cout<<"radius of c1="<<c1.GetRadius();
 	cout<<"area of c1="<<c1.Area()<<",circumference of c1="<<c1.Circumference()<<endl;
 	cout<<"radius of c2="<<c2.GetRadius();
 	cout<<"area of c2="<<c2.Area()<<",circumference of c2="<<c2.Circumference()<<endl;
 	return 0;
 }

 #ifndef _Circle
 #define _Circle
class Circle
 {
 private:
 	double Radius;
	const double PI;
 public:
 	Circle(double r=0): PI(3.1415926)
 	{
 		Radius=r;
 	}
 	double Area();
 	double Circumference();
 	double GetRadius()const;
 };
 #endif

 #include<iostream>
 #include<string>
 using namespace std;
 class Person
 {
 private:
 	int age;
 	char *name;
 public:
 	Person(int n=1,char *na="Zhuli");
 	~Person();
 	void Print();
 	void Print() const;
 	void ModifyAge();
 };
 Person::Person(int n,char *na)
 {
 	age=n;
 	name=new char[strlen(na)+1];
 	strcpy(name,na);
 }
 Person::~Person()

 {
 	delete []name;
 }
 void Person::Print()
 {
 	cout<<"age:"<<age<<"name:"<<name<<endl;
 	cout<<"This is general Print()."<<endl;
 }
 void Person::Print() const
 {
 	cout<<"age:"<<age<<"name:"<<name<<endl;
 	cout<<"This is const Print()."<<endl;
 }
 void Person::ModifyAge()  {
 	age++;
 }
 int main()
 {
 	const Person p1(17,"wu");
 	cout<<"Output const object p1"<<endl;
 	p1.Print();
 	Person p2(18,"zhang");
 	cout<<"Output general object p2"<<endl;
 	p2.ModifyAge();
 	p2.Print();
 	return 0;
 }
