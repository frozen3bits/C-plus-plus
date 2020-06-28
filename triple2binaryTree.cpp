#include<iostream>
using namespace std;

class node{
public:
	char data;
	node* left;
	node* right;
	
	node(char d, node* l = NULL, node* r = NULL){
		data = d;
		left = l;
		right = r;
	}
};

node* root;
node* now;
node* p;

void pre(node* now, char c){
	if(now->data == c){
		p = now;
		return;
	}
	if(now->left != NULL){
		pre(now->left, c);
	}
	if(now->right != NULL){
		pre(now->right, c);
	}
}
void brackets(node* now){
	if(now == NULL){
		return;
	}
	cout<<now->data;
	if(now->left != NULL && now->right != NULL){
		cout<<'(';
		brackets(now->left);
		cout<<',';
		brackets(now->right);
		cout<<')';
	}
	else if(now->left == NULL && now->right != NULL){
		cout<<'(';
		cout<<',';
		brackets(now->right);
		cout<<')';
	}
	else if(now->left != NULL && now->right == NULL){
		cout<<'(';
		brackets(now->left);
		cout<<')';
	}
	else{
		return;
	}
}
int main(){
	char a,b,c;
	while(1){
		cin>>a>>b>>c;
		if(a == '^' && b == '^'){
			break;
		}
		else if(a == '^'){
			root = new node(b);
		}
		else{
			pre(root,a);
			if(c == 'L'){
				p->left = new node(b);
			}
			else{
				p->right = new node(b);
			}
		}
	}
	brackets(root);
} 
