#include<iostream>
#include<iomanip>
#include <cmath>
using namespace std;
void printmonth(int m);    	// 打印每月日历
void printhead(int m);		//打印每月的日历头（判定起始位置）
int daysofmonth(int m);		//每月的天数计算
int firstday(int y);		//判断某年元旦是星期几
int year,weekday;			// year表示年份，weekday表示星期几
int main()
{
    int i;
    cout<<"请输入年份:"<<endl;
	cin>>year;
	cout<<year<<"年日历\n";
	weekday=firstday(year);
	for(i=1;i<=12;i++)
	{
		printmonth(i);
	cout<<endl;
	}
	return 0;
}
void printmonth(int m)  //打印每月日历
{
	int i,days;
	printhead(m);//调用打印每月日历头的函数
	days=daysofmonth(m);//调用函数求每月的天数
	for(i=1;i<=days;i++)
	{
		cout<<setw(5)<<i;
		weekday++;
		if(weekday==7)//每输出一天，表示星期几的变量weekday需增加，每满7天输出一个换行。
		{
			cout<<endl;
			weekday=0;
		}
	}
}
void printhead(int m) //打印每月的日历头（判定起始位置）
{
	int i;
cout<<endl<<setw(5)<<m<<"月"<<endl;   
cout<<setw(5)<<"日"<<setw(5)<<"一"<<setw(5)<<"二"<<setw(5)<<"三"<<setw(5)<<"四"<<setw(5)<<"五"<<setw(5)<<"六"<<endl;
	for(i=0;i<weekday;i++)
	cout<<setw(5)<<" ";  
}
int daysofmonth(int m)  //每月的天数计算
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
int firstday(int year)  //判断某年元旦是星期几
{
    int w;
    w=(year-1+(year-1)/4-(year-1)/100+(year-1)/400+1)%7;
    return w;//根据年份y的值求出元旦是星期几（0代表星期日,1代表星期一,）
}
