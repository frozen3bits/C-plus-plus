#include<iostream>
using namespace std;
int count=1;//ȫ�ֱ�����������
int count1=0;//�ж���������ĸ���ֵĴ���
int Judge(char str[]);
int Circle(char str[]);
int Circle(char str[]){
    int i,j,k,m,t;
    char a[8000];
    for(i=0;str[i]!='\0';i++)
    {
        continue;
    }
    k=i;
    for(j=0;j<k;j++){
        a[j]=str[--i];
    }
    a[j]='\0';
    for(i=0;i<k;i++){
        if(str[i]==a[i])
            continue;
        else{
            m=i+1;
            while(m!=k-i&&str[i]!=a[m])
            {
                count++;
                m++;
            }
            if(m==k-1-i&&count1==0){
                count1++;
                t=a[m];
                for(int g=m-1;g>=(k+1)/2;g--){
                    a[g+1]=a[g];
                }
                a[(k+1)/2]=t;
            }
            else if(count1!=0){
                cout<<"Impossible"<<endl;
                count=0;
                return 0;
            }
            else{
                t=a[m];
                for(int g=m-1;g>=i;g--){
                    a[g+1]=a[g];
                }
                a[i]=t;
            }
            break;
        }
    }
    if(Judge(a)==1){
        cout<<"�ǻ�����"<<endl;
        for(i=0;a[i]!='\0';i++)
            cout<<a[i];
        cout<<endl;
    }
    else{
        Circle(a);
    }
    return count;
}
int Judge(char str[])
{
    int i,j,k;
    char b[30];
    for(i=0;str[i]!='\0';i++){
        continue;
    }
    k=i;
    for(j=0;j<=k;j++)
    {
        b[j]=str[--i];
    }
    b[j]='\0';
    for(j=0;j<k;j++)
    {
        if(str[j]==b[j])
            continue;
        else
            return 0;
    }
    return 1;
}
int main()
{
    char str[30];
    int k;
    cin>>str;
    k=Circle(str);
    if(k!=0)
    {
        cout<<k<<endl;
    }
    return 0;
}

