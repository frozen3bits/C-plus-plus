#include<iostream>
#include<string>
#include<map>
using namespace std;
int GetLength(int tmp)
{
	int count=0;
	while( tmp/10 != 0 ){
		count++;
		tmp/=10;
	} 
	return ++count;
}
int main(){
	int a;
	cin>>a;
	int m = GetLength(a) ;
	int* array = new int[m];
	for(int i = 0;i<m;i++ ){
		array[i] = a%10;
		a/=10;
	}
	map <int,string> s;
	s.insert(pair<int, string>(1, "yi "));
	s.insert(pair<int, string>(2, "er "));
	s.insert(pair<int, string>(3, "san "));
	s.insert(pair<int, string>(4, "si "));
	s.insert(pair<int, string>(5, "wu "));
	s.insert(pair<int, string>(6, "liu "));
	s.insert(pair<int, string>(7, "qi "));
	s.insert(pair<int, string>(8, "ba "));
	s.insert(pair<int, string>(9, "jiu "));
	
	switch(m){
		case 10:
			if(m == 10&&array[9] == 1){
				cout<<"shi ";
			}
			else{
				cout<<s[array[9]]<<"shi ";
			}
		case 9:
			if(array[8] != 0){
				cout<<s[array[8]];
			}
			cout<<"yi ";
		case 8:
			if(array[7] != 0){
				cout<<s[array[7]]<<"qian ";
			}
			if(array[7] == 0 && array[8] != 0){
				cout<<"ling ";
			}
		case 7:
			if(array[6] != 0){
				cout<<s[array[6]]<<"bai ";
			}
			if(array[6] == 0 && array[7] != 0){
				cout<<"ling ";
			}
		case 6:
			if(m == 6&&array[5] == 1){
				cout<<"shi ";
			}
			else if(array[5] != 0){
				cout<<s[array[5]]<<"shi ";
			}
			else if(array[8] == 0 && array[9] != 0){
				cout<<"ling ";
			}
		case 5:
			if(array[4] != 0){
				cout<<s[array[4]];
			}
			if(!(array[4] == 0&&array[5] == 0&&array[6] == 0&&array[7] == 0))
				cout<<"wan ";
		case 4:
			if(array[3] != 0){
				cout<<s[array[3]]<<"qian ";
			}
			if(array[3] == 0 && array[4] != 0){
				cout<<"ling ";
			}
		case 3:
			if(array[2] != 0){
				cout<<s[array[2]]<<"bai ";
			}
			if(array[2] == 0 && array[3] != 0){
				cout<<"ling ";
			}
		case 2:
			if(m == 2&&array[1] == 1){
				cout<<"shi ";
			}
			else if(array[1] != 0){
				cout<<s[array[1]]<<"shi ";
			}
			else if(array[8] == 0 && array[9] != 0){
				cout<<"ling ";
			}
		case 1:
			if(array[0] != 0){
				cout<<s[array[0]];
			}
	}
} 
