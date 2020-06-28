#include<windows.h>
#include<iostream>
using namespace std;
void gotoXY(short x, short y){
	COORD pos = { y, x };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}
int main(){
	for(int i=0;i<20;i++){
		cout<<" "<<endl;
	} 
	for(int i=16;i>6;i--){
		for(int j=19;j>0;j--){
			_sleep(50);
			gotoXY(i,j+10);
			if(j>=i-6&&j<=20-i+6){
				cout<<'*';
			}
			else{
				cout<<' ';
			}
		}
	}
	
	for(int i=6;i>3;i--){
		for(int j=19;j>0;j--){
			_sleep(50);
			gotoXY(i,j+10);
			if(j>=8-i&&j<=3+i||j>=17-i&&j<=13+i){
				cout<<'*';
			}
			else{
				cout<<' ';
			}
		}
		
		
	}
	_sleep(2000000);
} 
