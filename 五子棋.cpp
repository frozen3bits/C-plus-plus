#include<iostream> 
#include<iomanip>
#include<cstring>
using namespace std;

int flag=0;
class player;
class chessBoard{
public:
	char z[20][20];
	friend class player;
	chessBoard(){
		for(int i=1;i<20;i++){
			for(int j=1;j<20;j++){
				z[i][j]='+';
			}
		}
		printq();	
	}
	void printq(){
		cout<<"  ";
		for(int i=1;i<20;i++){
			cout<<setw(4)<<i;
		}
		cout<<endl<<endl;
		for(int i=1;i<20;i++){
			cout<<setw(2)<<i;
			for(int j=1;j<20;j++){
				cout<<setw(4)<<z[i][j];
			}
			cout<<endl<<endl;
		}
	}
	void change(int x, int y, char qz){
		z[x][y]=qz;
	} 
	int win(){
		for(int i=1;i<=19;i++){
			for(int j=1;j<=15;j++){
				if(z[i][j]!='+'&&z[i][j]==z[i][j+1]&&z[i][j]==z[i][j+2]&&z[i][j]==z[i][j+3]&&z[i][j]==z[i][j+4]){   //ÐÐ»ñÊ¤ÅÐ¶Ï 
					if(flag==1){
						cout<<"ºÚÆåÊ¤£¡"; 
					}
					else{
						cout<<"°×ÆåÊ¤£¡"; 
					}
					return 1;
				}
				if(z[j][i]!='+'&&z[j][i]==z[j+1][i]&&z[j][i]==z[j+2][i]&&z[j][i]==z[j+3][i]&&z[j][i]==z[j+4][i]){  //ÁÐ»ñÊ¤ÅÐ¶Ï 
					if(flag==1){
						cout<<"ºÚÆåÊ¤£¡"; 
					}
					else{
						cout<<"°×ÆåÊ¤£¡"; 
					}
					return 1;
				}
			}
		}
		for(int i=1;i<=15;i++){
			for(int j=1;j<=15;j++){
				if(z[i][j]!='+'&&z[i][j]==z[i+1][j+1]&&z[i][j]==z[i+2][j+2]&&z[i][j]==z[i+3][j+3]&&z[i][j]==z[i+4][j+4]){  //ÓÒÏÂÐ±»ñÊ¤ÅÐ¶Ï 
					if(flag==1){
						cout<<"ºÚÆåÊ¤£¡"; 
					}
					else{
						cout<<"°×ÆåÊ¤£¡"; 
					}
					return 1;
				}
				if(z[i][20-j]!='+'&&z[i][20-j]==z[i+1][20-j-1]&&z[i][20-j]==z[i+2][20-j-2]&&z[i][20-j]==z[i+3][20-j-3]&&z[i][20-j]==z[i+4][20-j-4]){  //×óÏÂÐ±»ñÊ¤ÅÐ¶Ï 
					if(flag==1){
						cout<<"ºÚÆåÊ¤£¡"; 
					}
					else{
						cout<<"°×ÆåÊ¤£¡"; 
					}
					return 1;
				}
			}
		} 
		return 0;
	}
};

class player{
public:
	string name; 
	char qz;
	
	player(string n, char q){
		name=n;
		qz=q;
	}
	void turn(chessBoard& c){
		int x,y;
		while(1){   //ÅÐ¶¨ÊäÈë×ø±êÊÇ·ñÕýÈ· 
			cout<<"ÂÖµ½"<<name<<"ÊäÈëÏÂÆå×ø±ê£º"; 
			cin>>x>>y;
			if(x<1||x>19||y<1||y>19){
				cout<<"ÊäÈë´íÎó"<<endl;
			}
			else{
				break;
			}
		}
		c.change(x,y,qz);
		if(flag==0){
			flag=1;
		}
		else{
			flag=0;
		}
	}
};

int main(){
	chessBoard c;
	player b("ºÚÆå",'O') ,w("°×Æå", 'X');
	while(1){
		b.turn(c);
		c.printq();
		if(c.win()==1)
			return 0;
		w.turn(c);
		c.printq();
		if(c.win()==1)
			return 0;
	}
}
