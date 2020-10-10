#include<iostream>
#include<queue>
using namespace std;

struct pcb{
	int id;//����ID 
	int pr;//�������ȼ� 0��3���� 
	int ntime;//��������ʱ�� 
	int rtime;//����Ŀǰ����ʱ�� 
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

void check(int t){//��鵱ǰʱ���Ƿ��н��̾���,������������ 
	if(timeline[t].checked == true){
		return;
	}
	if(timeline[t].next != NULL){ 
		timeblock *tp = timeline[t].next;
		while(tp != NULL){
			p[tp->p->pr].push(*(tp->p));
			cout<<"		"<< tp->p->id<<"�Ž��� ����"<<endl; 
			tp = tp->next;
		}
	}
	timeline[t].checked = true;
}

int choose(){//�����һ�����еĽ������ĸ����� 
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
		return 100;//����ȫ�� 
	}
}

int run(pcb* a){
	cout<<"		"<< a->id<<"�Ž��� ��ʼ����"<<endl; 
	for(int i=0;i<ts[a->pr];i++){
		cout<<"��"<<t+i<<"��"<<endl; 
		check(t+i);
//		for(int j=0;j<4;j++){
//			cout<<p[j].size()<<endl;
//		}
		int x = choose();
//		cout<<x<<endl;
		if(x < a->pr){
			cout<<"		"<< a->id<<"�Ž��� ������ֹ"<<endl; 
			p[a->pr].push(*a); 
			return i-1; 
		}
		cout<<"		"<< a->id<<"�Ž��� ��ǰʱ��Ƭ����"<<i+1<<"/"<<ts[a->pr]<<"��"<<endl; 
		a->rtime++;
		if(a->rtime >= a->ntime){
			cout<<"		"<< a->id<<"�Ž��� �������"<<endl; 
			return i+1;
		}
	}
	cout<<"		"<< a->id<<"�Ž��� ʱ��Ƭ�� ������ֹ"<<endl; 
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
	cout<<"������̸���" <<endl; 
	cin>>n;
	for(int i=0;i<n;i++){
		pcb* x = new pcb;
		x->id = i;
		int tt;
		cout<<"���������"<<i<<"�����ȼ���0-3��������ʱ�䣨1-10���;���ʱ�䣨0-19��"<<endl;
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
	cout<<"���ʱ����"<<endl;
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
	
	while(t<30){            //���� 
		
		check(t);
//		for(int i=0;i<4;i++){
//			cout<<p[i].size()<<endl;
//		}	
		int next = choose();

		cout<<"��"<<t<<"��"<<endl; 

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
