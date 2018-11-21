 #include "score.h"
10  #include <math.h>
11  #include <stdlib.h>
12  #include <stdio.h>
13

14  /*----------------��������-------------*/
15

16  //1.��ȡѧ����������
17  //void readData(SS stu[], int N)
18  //{
19  //
20  //	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");
21  //
22  //	for (int i = 0; i < N; i++)
23  //	{
24  //		printf("��%d��ѧ��:", i + 1);
25  //		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
26  //		printf("\n");
27  //	}
28  //
29  //	printf("------�ɼ�¼�����!--------\n");
30  //
31  //
32  //
33  //}
34

35  SS* readDataFromFile(int *N)
36  {
37

38  	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");
39

40  	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ
41

42  	FILE *fp = NULL;
43  	int count = 0;
44  	int index = 0;
45

46  	fp = fopen("data.txt", "r");
47

48  	//1.��ȡѧ����Ŀ
49  	if (fp != NULL)
50  	{
51  		fscanf(fp, "%d", &count);
52  		*N = count;
53  	}
54  	else
55  	{
56  		printf("failed to open the info file\n");
57  		getchar();
58  	}
59

60  	printf("ѧ����ĿΪ:%d\n", count);
61  	getchar();
62

63

64  	//2.������ѧ������洢�ռ�
65  	stu = (SS*)malloc(count * sizeof(SS));
66

67

68  	//3.��ȡÿ��ѧ������Ϣ
69  	while ((!feof(fp)) && (index < count))
70  	{
71

72  		//�����ļ����ݵ��ڴ�
73  		fscanf(fp, "%s%s %f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore,&stu[index].expScore, &stu[index].finalScore);
74

75  		//���ԭʼѧ����Ϣ
76  		printf("* %s	ƽʱ�ɼ���%4.2f��	ʵ��ɼ���%4.2f��	��ĩ�ɼ�:%4.2f��\n", (stu[index].number), stu[index].dailyScore, stu[index].expScore, stu[index].finalScore);
77

78  		index++;
79

80

81  	}
82

83  	fclose(fp);
84

85  	return stu;
86  }
87

88  //2.����N��ѧ�����Ե������ɼ�
89  void calcuScore(SS stu[], int N)
90  {
91

92

93  	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");
94

95  	for (int i = 0; i < N; i++)
96  	{
97  		//�ܳɼ�=0.2\*ƽʱ�ɼ�+0.2\*ʵ��ɼ�+0.6\*��ĩ�ɼ�
98  		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].expScore + 0.6*stu[i].finalScore;
99  		printf("* %s			�ܳɼ�:%4.2f��\n", (stu[i].number),  stu[i].generalScore);
100

101  	}
102  }
103

104

105  //3.���������ɼ�����
106  int cmpBigtoSmall(const void *a, const void *b)
107  {
108

109  	SS *aa = (SS *)(a);
110  	SS *bb = (SS *)(b);
111

112

113

114  	if ((*aa).generalScore < (*bb).generalScore)  return 1;
115

116  	else if ((*aa).generalScore > (*bb).generalScore)  return -1;
117

118  	else
119  		return 0;
120

121  }
122

123  void sortScore(SS stu[], int N)
124  {
125

126  	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);
127

128  }
129

130

131  //4.����һ���ĸ�ʽ���N��ѧ������Ϣ
132  void printOut(SS stu[], int N)
133  {
134

135

136  	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");
137

138  	for (int i = 0; i < N; i++)
139  	{
140

141  		printf("��%d����Ϣ %s			�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]),  stu[i].generalScore);
142  	}
143

144

145  }
146

147  /*-6.����ɼ��ľ�ֵ�ͷ���*/
148  void Ave_Variance(SS stu[],int N)
149  {
150  	float ave;
151  	ave = 0.2*(stu[0].generalScore + stu[1].generalScore + stu[2].generalScore + stu[3].generalScore + stu[4].generalScore);
152  	float variance;
153  	variance = 0.2*(pow(stu[0].generalScore - ave, 2) + pow(stu[1].generalScore - ave, 2) + pow(stu[2].generalScore - ave, 2) + pow(stu[3].generalScore - ave, 2) + pow(stu[4].generalScore - ave, 2));
154

155  	printf("�ܳɼ�ƽ��ֵΪ��%4.2f���ܳɼ�����Ϊ��%4.2f\n", ave,variance);
156
157  }
158

159  /*-7.����ѧ�Ų�ɼ�*/
160  void searchScore(SS stu[])
161  {
162  	char number[10];
163  	printf("������ѧ�ţ�\n");
164  	//printf("%c", stu[0].number[0]);
165
166  	for (int j = 0; j < 10; j++)
167  	{
168  		scanf("%c", &number[j]);
169  	}
170  	getchar();
171
172

173
174  	for (int i = 0; i < 5; i++)
175  	{
176  		for (int j = 0; j < 10; j++)
177  		{
178  			if (number[j] == stu[i].number[j])
179  			{
180  				if (j == 9)
181  				{
182  					printf("* %s	ƽʱ�ɼ���%4.2f��	ʵ��ɼ���%4.2f��	��ĩ�ɼ�:%4.2f��    �ܳɼ�Ϊ:%4.2f��\n", (stu[i].number), stu[i].dailyScore, stu[i].expScore, stu[i].finalScore,stu[i].generalScore);
183  				}
184

185  			}
186  		}
187  	}
188
189  }
