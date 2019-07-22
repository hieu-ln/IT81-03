#include <iostream>
#include <stdio.h>
using namespace std;
struct Node
{
	int info;
	Node *link;
};
Node *sp;
//khoi tao stack rong 
void init()
{
	sp=NULL;
}
//kiem tra stack rong
int isemty()
{
	if(sp==NULL)
		return 1;
	return 0;
}
//them phan tu vao satck
void push(int x)
{
	Node *p= new Node;
	p ->info=x;
	p ->link = sp;
	sp=p;
}

int pop(int &x)
{
	if(sp != NULL)
	{
		Node *p =sp;
		x=p->info;
		sp = p ->link;
		delete p;
		return 1;
	}
	return 0;
}
//xuat stack
void process_stack()
{
	Node *p =sp;
	do{
		cout<<p->info <<" " ;
		p = p -> link;
	}
	while(p!=NULL);
		cout<< endl;
}

int main()
{
		
		int choice , x,i;
		system("cls");
		cout<<"-----------bai tap 10----------------" << endl;
		cout<<"1.khoi tao stack rong " << endl;
		cout<<"2.them phan tu vao stack " << endl;
		cout<<"3.lay phan tu ra khoi stack " << endl;
		cout<<"4.xuat stack " << endl;
		cout<<"5.thoat " << endl;
		do{
			cout<<"nhap so can thuc hien " << endl ;
			cin >> choice;
			switch(choice)
			{
				case 1:
					init();
					cout<<"ban vua khoi tao stack rong thanh cong " << endl;
					break;
				case 2:
					cout<<"vui long nhap gia tri x= " << endl;
					cin >> x ;
					push(x);
					cout<<"stack sau khi them " << endl;
					process_stack();
					break;
				case 3:
					pop(x);
					cout<<"phan tu lay ra tu stack x= " << x << endl;
					cout<<"stack sau khi lay ra la " << endl;
					process_stack();
					break;
				case 4:
					cout<<"stacl hien tai la" << endl;
					process_stack();
					break;
				case 5:
					cout<<"chao tam biet " << endl;
				default:
					break;
			}
			}while(choice != 5 );
			return 0;
		
}









