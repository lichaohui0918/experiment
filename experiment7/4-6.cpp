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
 					cout<<"���޴��ˣ�\n";
 				else
 					array[i].Display();
 				break;
 			case 3:OutputStu(array); break;
 			case 4:if (InsertStu(array))
 					   cout<<"�ɹ�����һ����¼\n";
 				else
 					cout<<"����ʧ�ܣ�\n";
 				break;
 			case 5:
 				cout<<"Input the name deleted:"<<endl;
 				cin>>na;
 				if ( DeleteStu(array,na) )
 					cout<<"�ɹ�ɾ��һ����¼\n";
 				else
 					cout<<"ɾ��ʧ�ܣ�\n";
 				break;
 			default:break;
 		}
 	}while(choice);
 	return 0;
 }
 void menu()
 {
 	cout<<"********1.¼����Ϣ********"<<endl;
 	cout<<"********2.��ѯ��Ϣ********"<<endl;
 	cout<<"********3.�����Ϣ********"<<endl;
 	cout<<"********4.������Ϣ********"<<endl;
 	cout<<"********5.ɾ����Ϣ********"<<endl;
 	cout<<"********0.��    ��********"<<endl;
 }
 void OutputStu(const Student *array)
 {
 	cout<<"ѧ��������="<<Student::GetCount()<<endl;
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
 			cout<<"�����������޷�����¼�룡"<<endl;
 		if (!array[i].GetAge())
 			array[i++].Input();
 		cout<<"���������𣿣�Y or N)"<<endl;
 		cin>>ch;
 	}while(ch=='Y');
 }
 bool InsertStu(Student *array)
 {
 	if (Student::GetCount()==N)
 	{
 		cout<<"�����������޷������¼��"<<endl;
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
 		cout<<"û�м�¼���޷�ɾ����"<<endl;
 		return false;
 	}
 	int i=SearchStu(array,na);
 	if (i==N)
 	{
 		cout<<"���޴��ˣ��޷�ɾ����\n";
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
 	cout<<"��  ����"<<name<<endl;
 	cout<<"���֤��"<<ID<<endl;
 	cout<<"ѧ  �ţ�"<<number<<endl;
 	cout<<"ר  ҵ��"<<speciality<<endl;
 	cout<<"��  �䣺"<<age<<endl<<endl;
 }
 void Student::Input()
 {
 	char na[10];
 	cout<<"������  ����";
 	cin>>na;
 	if(name)
 		delete []name;
 	name=new char[strlen(na)+1];
 	strcpy(name,na);
 	cout<<"�������֤��";
 	cin>>ID;
 	cout<<"������  �䣺";
 	cin>>age;
 	cout<<"����ר  ҵ��";
 	cin>>speciality;
 	cout<<"����ѧ  �ţ�";
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
