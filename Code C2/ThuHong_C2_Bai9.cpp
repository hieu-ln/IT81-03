#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
#define max 100
typedef int num;
typedef char elem;

typedef struct{
    num e[max];
    elem a[max];
    elem b[max];
    elem c[max];
    int top;
}stack;
//-------------------
void creatstack(stack &s)
{   s.top=-1;}
//-------------------
int emptystack(stack s)
{   return (s.top==-1);}
//-------------------
void push(stack &s, num &x, elem &a, elem &b, elem &c)
{
    if (s.top==max-1) exit(0);
    memcpy(&s.e[++s.top],&x,sizeof(num));
    memcpy(&s.a[s.top],&a,sizeof(elem));
    memcpy(&s.b[s.top],&b,sizeof(elem));
    memcpy(&s.c[s.top],&c,sizeof(elem));
}
//-------------------
void pop(stack &s, num &x, elem &a, elem &b, elem &c)
{
    if (s.top==-1) exit(0);
    memcpy(&x,&s.e[s.top],sizeof(num));
    memcpy(&a,&s.a[s.top],sizeof(elem));
    memcpy(&b,&s.b[s.top],sizeof(elem));
    memcpy(&c,&s.c[s.top--],sizeof(elem));
}

void main()
{
    stack s;
    int n,l,k=1;
    char a='A';
    char b='B';
    char c='C';
    cout<<"Nhap so: ";cin>>n;
    creatstack(s);
    push(s,n,a,b,c);
    while(!emptystack(s))
    {
        pop(s,n,a,b,c);
        if(n==1)
            cout<<"\nChuyen "<<a<<" qua "<<c;
        else
        {
            l=n-1;
            push(s,l,b,a,c);
            push(s,k,a,b,c);
            push(s,l,a,c,b);
        }
    }
	cout << endl;
}
