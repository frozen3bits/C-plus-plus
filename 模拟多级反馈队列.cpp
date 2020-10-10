#include<iostream>
#include<queue>
using namespace std;

struct pcb{
	int id;//任务ID 
	int pr;//任务优先级 0到3降低 
	int ntime;//任务所需时间 
	int rtime;//任务目前运行时间 
};
struct timeblock{
	pcb* p;
	timeblock* next;
	bool checked; 
};
queue<pcb> p[4];
timeblock timeline[20];
int ts[4]={2,4,6,8};
int t = 0;

void check(int t){//检查当前时刻是否有进程就绪,并将其放入队列 
	if(timeline[t].checked == true){
		return;
	}
	if(timeline[t].next != NULL){ 
		timeblock *tp = timeline[t].next;
		while(tp != NULL){
			p[tp->p->pr].push(*(tp->p));
			cout<<"		"<< tp->p->id<<"号进程 就绪"<<endl; 
			tp = tp->next;
		}
	}
	timeline[t].checked = true;
}

int choose(){//检测下一个运行的进程在哪个队列 
	if(p[0].empty() == false){
		return 0;
	} 
	else if(p[1].empty() == false){
		return 1;
	} 
	else if(p[2].empty() == false){
		return 2;
	} 
	else if(p[3].empty() == false){
		return 3;
	} 
	else{
		return 100;//队列全空 
	}
}

int run(pcb* a){
	cout<<"		"<< a->id<<"号进程 开始运行"<<endl; 
	for(int i=0;i<ts[a->pr];i++){
		cout<<"第"<<t+i<<"秒"<<endl; 
		check(t+i);
//		for(int j=0;j<4;j++){
//			cout<<p[j].size()<<endl;
//		}
		int x = choose();
//		cout<<x<<endl;
		if(x < a->pr){
			cout<<"		"<< a->id<<"号进程 运行终止"<<endl; 
			p[a->pr].push(*a); 
			return i-1; 
		}
		cout<<"		"<< a->id<<"号进程 当前时间片运行"<<i+1<<"/"<<ts[a->pr]<<"秒"<<endl; 
		a->rtime++;
		if(a->rtime >= a->ntime){
			cout<<"		"<< a->id<<"号进程 运行完毕"<<endl; 
			return i+1;
		}
	}
	cout<<"		"<< a->id<<"号进程 时间片到 运行终止"<<endl; 
	p[a->pr].push(*a); 
	return ts[a->pr];
}

int main(){
	int n;
	timeblock* tp;
	for(int i=0;i<20;i++){
		timeline[i].next = NULL;
		timeline[i].p = NULL;
		timeline[i].checked = false;
	}
	cout<<"输入进程个数" <<endl; 
	cin>>n;
	for(int i=0;i<n;i++){
		pcb* x = new pcb;
		x->id = i;
		int tt;
		cout<<"请输入进程"<<i<<"的优先级（0-3）和运行时间（1-10）和就绪时间（0-19）"<<endl;
		cin>>x->pr>>x->ntime>>tt;
		x->rtime = 0;
		tp = &timeline[tt];
		while(tp->next!=NULL){
			tp = tp->next; 
		}
		tp->next = new timeblock;
		tp = tp->next;
		tp->next = NULL;
		tp->p = x;
	} 
	cout<<"输出时间线"<<endl;
	for(int i=0;i<20;i++){
		int a=0;
		tp = &timeline[i];
		while(tp->next!=NULL){
			tp = tp->next; 
			a++;
		}
		cout<<a;
	}
	cout<<endl;
	
	while(t<30){            //运行 
		
		check(t);
//		for(int i=0;i<4;i++){
//			cout<<p[i].size()<<endl;
//		}	
		int next = choose();

		cout<<"第"<<t<<"秒"<<endl; 

		if(next != 100){
			pcb* ptr = new pcb;
			ptr->id = p[next].front().id;
			ptr->pr = p[next].front().pr;
			ptr->ntime = p[next].front().ntime;
			ptr->rtime = p[next].front().rtime;
			p[next].pop();
			t += run(ptr);
		}
		t++;
	}
	
}
