 #include"iostream"
  #include"windows.h"
  using namespace std;
  int main()
  {
  	int *p,a = 0, b = 0,sum1=0;
  	float sum2 = 0,mean,variance;
  	p = new int[20];
 	for (int i = 0; i < 20; i++)
  	{
  		cin >> p[i];
  		sum1 += p[i];
  		if (p[i] > 0)a++;
  		if (p[i] < 0)b++;
  	}
  	mean = sum1 / 20;
  	for (int j = 0; j < 20; j++)
  		sum2 += (mean - p[j])*(mean - p[j]);
  	variance = sum2 / 20;
  	for(int m=0;m<20;m++)
  		for (int n = m; n < 20; n++)
  		{
  			if (p[m] > p[n])
  			{int t = p[m]; p[m] = p[n]; p[n] = t;}
  		}
  	cout << "���մ�С�����˳������Ϊ��" << endl;
  	for (int x = 0; x < 20; x++)
  		cout << p[x] << "��";
  	cout << endl;
  	cout << "����Ϊ" << a << "����" << endl;
  	cout << "����Ϊ" << b << "����" << endl;
  	cout << "��ֵΪ��" << mean << "��" << endl;
  	cout << "����Ϊ��" << variance<< "��" << endl;
  	delete[]p;
  	system("pause");
  	return 0;
  }
