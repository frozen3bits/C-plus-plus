#include <iostream> 
#include <conio.h>
#include <fstream> 
#include <string>
using namespace std;

int main(){   
	ifstream file;
	
	file.open("1.txt",ios::in);
	string s;
	while(getline(file,s)){
		
		cout<<s<<endl;
	}
    int ch1=0;
    int ch2=0;
    while (1){
        if (ch1=getch()){ 
            ch2=getch();//��һ�ε���getch()������ֵ224
            switch (ch2){//�ڶ��ε���getch()
            	case 72: printf("The key you Pressed is : �� \n");break;//��  
            	case 80: printf("The key you Pressed is : �� \n");break;//�� 
            	case 75: printf("The key you Pressed is : �� \n");break;//�� 
            	case 77: printf("The key you Pressed is : �� \n");break;//��                                 
            	default: printf("No direction keys detected \n",ch2);break;
                break;
            }
        }  
    }
    return 0;
}

