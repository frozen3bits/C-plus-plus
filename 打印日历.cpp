#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
void printmonth(int m);    	// ��ӡÿ������
void printhead(int m);		//��ӡÿ�µ�����ͷ���ж���ʼλ�ã�
int daysofmonth(int m);		//ÿ�µ���������
int firstday(int y);		//�ж�ĳ��Ԫ�������ڼ�
int year,weekday;			// year��ʾ��ݣ�weekday��ʾ���ڼ�
int main()
{
    int i;
    cout<<"���������:"<<endl;
	cin>>year;
	cout<<year<<"������\n";
	weekday=firstday(year);
	for(i=1;i<=12;i++)
	{
		printmonth(i);
	cout<<endl;
	}
	return 0;
}
void printmonth(int m)  //��ӡÿ������
{
	int i,days;
	printhead(m);//���ô�ӡÿ������ͷ�ĺ���
	days=daysofmonth(m);//���ú�����ÿ�µ�����
	for(i=1;i<=days;i++)
	{
		cout<<setw(5)<<i;
		weekday++;
		if(weekday==7)//ÿ���һ�죬��ʾ���ڼ��ı���weekday�����ӣ�ÿ��7�����һ�����С�
		{
			cout<<endl;
			weekday=0;
		}
	}
}
void printhead(int m) //��ӡÿ�µ�����ͷ���ж���ʼλ�ã�
{
	int i;
cout<<endl<<setw(5)<<m<<"��"<<endl;   
cout<<setw(5)<<"��"<<setw(5)<<"һ"<<setw(5)<<"��"<<setw(5)<<"��"<<setw(5)<<"��"<<setw(5)<<"��"<<setw(5)<<"��"<<endl;
	for(i=0;i<weekday;i++)
	cout<<setw(5)<<" ";  
}
int daysofmonth(int m)  //ÿ�µ���������
{
	int a;
	switch(m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		a=31;break;
		case 4: case 6: case 9: case 11:
		a=30;break;
		case 2:
		a=28;
	}
	if(year%4==0&&year%100!=0||year%400==0)
	{
		if(a==28)
		{	a++;}
	}
	return a;
}
int firstday(int year)  //�ж�ĳ��Ԫ�������ڼ�
{
    int w;
    w=(year-1+(year-1)/4-(year-1)/100+(year-1)/400+1)%7;
    return w;//�������y��ֵ���Ԫ�������ڼ���0����������,1��������һ,��
}
