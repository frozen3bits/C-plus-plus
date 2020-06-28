#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<stdio.h>  
#include<windows.h>
#include<conio.h>
#include<ctime>
#include <iomanip>
using namespace std;
int full[31] = { 0 };
int N;
struct members
{
	char name[30];
	int Class[31];
	int num;
	int mark;
}stu[61];
void gotoXY(short, short);
void dfs(int);
void print_form();
void print_name();
bool cmp(members a, members b) { return a.num > b.num; }
int main()
{

	cout << "�����Ա����(������С�ڵ���60): ";
	cin >> N;
	cout << "�����������˵��������γ���Ϣ(�п���1���޿���0����һ������һ�����겻�ո���������Ϣ�س�����)" << endl;
	for (int i = 1; i <= N; i++)
	{
		int space = 0;
		cout << "�������" << i << "���˵�����" << endl;
		char con[30];
		cin >> con;
		for (int p = 0; p < 30; p++)
			stu[i].name[p] = con[p];
		cout << "�������" << i << "���˵Ŀγ���Ϣ" << endl;
		char a[31];
		cin >> a;
		for (int k = 0; k < 30; k++)
		{

			stu[i].Class[k + 1] = a[k] - '0';
			if (stu[i].Class[k + 1] == 1)
				space++;
		}
		stu[i].num = space;
		stu[i].mark = 0;
	}

	system("cls");
	sort(stu + 1, stu + 1 + N, cmp);
	dfs(1);
	gotoXY(1, 30);
	cout << "û����һ����,";
	system("pause");
}

void dfs(int n)
{

	if (n == N + 1)
	{

		print_form();
		print_name();
		gotoXY(1, 29);
		cout << "��������鿴��һ�ű�:";
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 1; i <= 30; i++)
		{
			if (stu[n].Class[i] == 0 && full[i] < 2)
			{
				full[i]++;
				stu[n].mark = i;
				dfs(n + 1);
				full[i]--;
				stu[n].mark = 0;
			}
		}
		return;
	}
}
void gotoXY(short x, short y)
{
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void print_form()
{
	gotoXY(9, 1);
	for (int i = 0; i < 46; i++)
		cout << "-";
	cout << endl;
	gotoXY(1, 3);
	for (int i = 0; i < 54; i++)
		cout << "-";
	cout << endl;
	gotoXY(1, 7);
	for (int i = 0; i < 54; i++)
		cout << "-";
	cout << endl;
	gotoXY(1, 11);
	for (int i = 0; i < 54; i++)
		cout << "-";
	cout << endl;
	gotoXY(1, 15);
	for (int i = 0; i < 54; i++)
		cout << "-";
	cout << endl;
	gotoXY(1, 19);
	for (int i = 0; i < 54; i++)
		cout << "-";
	gotoXY(1, 23);
	for (int i = 0; i < 54; i++)
		cout << "-";
	gotoXY(1, 27);
	for (int i = 0; i < 54; i++)
		cout << "-";
	//-----------------------------------------
	gotoXY(9, 5);
	for (int i = 0; i < 46; i++)
		cout << "-";
	gotoXY(2, 5);
	cout << "��һ��";
	gotoXY(9, 9);
	for (int i = 0; i < 46; i++)
		cout << "-";
	gotoXY(2, 9);
	cout << "�ڶ���";
	gotoXY(9, 13);
	for (int i = 0; i < 46; i++)
		cout << "-";
	gotoXY(2, 13);
	cout << "������";
	gotoXY(9, 17);
	for (int i = 0; i < 46; i++)
		cout << "-";
	gotoXY(2, 17);
	cout << "���Ľ�";
	gotoXY(9, 21);
	for (int i = 0; i < 46; i++)
		cout << "-";
	gotoXY(2, 21);
	cout << "�����";
	gotoXY(9, 25);
	for (int i = 0; i < 46; i++)
		cout << "-";
	gotoXY(2, 25);
	cout << "������";
	//-----------------------------------------
	gotoXY(11, 2);
	cout << "����һ";
	gotoXY(20, 2);
	cout << "���ڶ�";
	gotoXY(29, 2);
	cout << "������";
	gotoXY(38, 2);
	cout << "������";
	gotoXY(47, 2);
	cout << "������";
	//------------------------------------------
	for (int i = 1; i <= 27; i++)
	{
		gotoXY(0, i);
		cout << "|";
		gotoXY(9, i);
		cout << "|";
		gotoXY(18, i);
		cout << "|";
		gotoXY(27, i);
		cout << "|";
		gotoXY(36, i);
		cout << "|";
		gotoXY(45, i);
		cout << "|";
		gotoXY(54, i);
		cout << "|";
	}
	gotoXY(0, 1);
	cout << " ";
	gotoXY(0, 2);
	cout << " ";
	struct tm t;   //tm�ṹָ��
	time_t now;  //����time_t���ͱ���
	time(&now);      //��ȡϵͳ���ں�ʱ��
//	localtime_s(&t, &now);   //��ȡ�������ں�ʱ��
	gotoXY(33, 28);
	cout << t.tm_year + 1900 << "��" << t.tm_mon + 1 << "��" << t.tm_mday << "��  " << setw(2) << t.tm_hour << "��" << setw(2) << t.tm_min << "��" << endl;
}

void print_name()
{
	int form[31] = { 0 };
	for (int i = 1; i <= N; i++)
	{
		int l = 0;
		int h = stu[i].mark;
		while (h > 6)
		{
			l++;
			h -= 6;
		}
		gotoXY(11 + 9 * l, 4 * h + 2 * form[stu[i].mark]);
		cout << stu[i].name;
		form[stu[i].mark]++;
	}
}
