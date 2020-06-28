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
            ch2=getch();//第一次调用getch()，返回值224
            switch (ch2){//第二次调用getch()
            	case 72: printf("The key you Pressed is : ↑ \n");break;//上  
            	case 80: printf("The key you Pressed is : ↓ \n");break;//下 
            	case 75: printf("The key you Pressed is : ← \n");break;//左 
            	case 77: printf("The key you Pressed is : → \n");break;//右                                 
            	default: printf("No direction keys detected \n",ch2);break;
                break;
            }
        }  
    }
    return 0;
}

