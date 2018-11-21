#include<iostream>
 using namespace std;
 #include"4_06.h"
 const int N=10;
 void menu();
 void OutputStu(const Student *array);
 void InputStu(Student *array);
 int SearchStu(const Student *array,char *na);
 bool InsertStu(Student *array);
 bool DeleteStu(Student *array,char *na);
 int main()
 {
 	Student array[N];
 	int choice;
 	char na[20];
 	do
 	{
 		menu();
 		cout<<"Please input your choice:";
 		cin>>choice;
 		if( choice>=0 && choice <= 5 )
 			switch(choice)
 		{
 			case 1:InputStu(array);break;
 			case 2:
 				cout<<"Input the name searched:"<<endl;
 				cin>>na;
 				int i;
 				i=SearchStu(array,na);
 				if (i==N)
 					cout<<"查无此人！\n";
 				else
 					array[i].Display();
 				break;
 			case 3:OutputStu(array); break;
 			case 4:if (InsertStu(array))
 					   cout<<"成功插入一条记录\n";
 				else
 					cout<<"插入失败！\n";
 				break;
 			case 5:
 				cout<<"Input the name deleted:"<<endl;
 				cin>>na;
 				if ( DeleteStu(array,na) )
 					cout<<"成功删除一条记录\n";
 				else
 					cout<<"删除失败！\n";
 				break;
 			default:break;
 		}
 	}while(choice);
 	return 0;
 }
 void menu()
 {
 	cout<<"********1.录入信息********"<<endl;
 	cout<<"********2.查询信息********"<<endl;
 	cout<<"********3.浏览信息********"<<endl;
 	cout<<"********4.插入信息********"<<endl;
 	cout<<"********5.删除信息********"<<endl;
 	cout<<"********0.退    出********"<<endl;
 }
 void OutputStu(const Student *array)
 {
 	cout<<"学生总人数="<<Student::GetCount()<<endl;
 	for(int i=0; i<N; i++)
 		if (array[i].GetAge())
 			array[i].Display();
 }
 int SearchStu(const Student *array,char *na)
 {
 	int i,j=N;
 	for(i=0; i<N;i++)
 		if (array[i].GetAge())
 			if( strcmp( array[i].GetName() , na)== 0)
 			{
 				j=i;
 				break;
 			}
 			return j;
 }
 void InputStu(Student *array)
 {
 	char ch;
 	int i=0;
 	do
 	{
 		if (Student::GetCount()==N)
 			cout<<"人数已满，无法继续录入！"<<endl;
 		if (!array[i].GetAge())
 			array[i++].Input();
 		cout<<"继续输入吗？（Y or N)"<<endl;
 		cin>>ch;
 	}while(ch=='Y');
 }
 bool InsertStu(Student *array)
 {
 	if (Student::GetCount()==N)
 	{
 		cout<<"人数已满，无法插入记录！"<<endl;
 		return false;
 }
 for (int i=0; array[i].GetAge() ; i++);
 array[i].Insert();
 return true;
 }
 bool DeleteStu(Student *array,char *na)
 {
 	if (Student::GetCount()==0)
 	{
 		cout<<"没有记录，无法删除！"<<endl;
 		return false;
 	}
 	int i=SearchStu(array,na);
 	if (i==N)
 	{
 		cout<<"查无此人，无法删除！\n";
 		return false;
 	}
 	array[i].Delete();
 	return true;
 }

 #ifndef _STUDENT
 #define _STUDENT
 #include<iostream>
 #include<string>
 using namespace std;
 #define SIZE 80
 class Student
 {
 	char *name;
 	char ID[19];
 	char number[10];
 	char speciality[20];
 	int age;
 	static int count;
 public:
 	Student();
 	Student(char *na,char *id,char *num,char * spec,int ag);
 	Student(const Student &per);
 	~Student();
 	char* GetName()const;
 	char* GetID();
 	char* GetNumber();
 	char* GetSpec();
 	int GetAge()const;
 	void Display()const;
 	void Input();
 	void Insert();
 	void Delete();
 	static int GetCount();
 };
 #endif

 #include"4_06.h"
 int Student::count=0;
 Student::Student()
 {
 	name=NULL;
 	age=0;
 }
 Student::Student(char *na,char *id,char *num,char * spec,int ag)
 {
 	if(na)
 	{
 		name=new char[strlen(na)+1];
 		strcpy(name,na);
 	}
 	strcpy(ID,id);
 	strcpy(number,num);
 	strcpy(speciality, spec);
 	age=ag;
 	count++;
 }
 Student::Student(const Student &per)
 {
 	if(per.name)
 	{
 		name=new char[strlen(per.name)+1];
 		strcpy(name,per.name);
 	}
 	strcpy(ID,per.ID);
 	strcpy(number,per.number);
 	strcpy(speciality,per.speciality);
 	age=per.age;
 	count++;
 }
 Student::~Student()
 {
 	cout<<"disCon"<<endl;
 	if (name)
 		delete []name;
 	count--;
 }
 char* Student::GetName()const
 {
 	return name;
 }
 char* Student::GetID()
 {
 	return ID;
 }
 int Student::GetAge()const
 {
 	return age;
 }
 char* Student::GetSpec()
 {
 	return speciality;
 }
 char* Student::GetNumber()
 {
 	return number;
 }
 void Student::Display()const
 {
 	cout<<"姓  名："<<name<<endl;
 	cout<<"身份证："<<ID<<endl;
 	cout<<"学  号："<<number<<endl;
 	cout<<"专  业："<<speciality<<endl;
 	cout<<"年  龄："<<age<<endl<<endl;
 }
 void Student::Input()
 {
 	char na[10];
 	cout<<"输入姓  名：";
 	cin>>na;
 	if(name)
 		delete []name;
 	name=new char[strlen(na)+1];
 	strcpy(name,na);
 	cout<<"输入身份证：";
 	cin>>ID;
 	cout<<"输入年  龄：";
 	cin>>age;
 	cout<<"输入专  业：";
 	cin>>speciality;
 	cout<<"输入学  号：";
 	cin>>number;
 	count++;
 }
 void Student::Insert()
 {
 	if(!age)
 		Input();
 }
 void Student::Delete()
 {
 	age=0;
 	count--;
 }
 int Student::GetCount()
 {
 	return count;
 }
