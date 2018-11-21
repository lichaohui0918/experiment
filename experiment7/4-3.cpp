#include<iostream>
 using namespace std;
 #include "4_03.h"
 int main()
 {
 	Circle c1(3.5),c2;
 	cout<<"area of c1="<<c1.Area()<<",circumference of c1="<<c1.Circumference()<<endl;
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
 };
 #endif
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
