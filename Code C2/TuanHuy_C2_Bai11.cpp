#include <iostream>
#include <stdio.h>
using namespace std;

//khai bao cau truc queue
struct Node{
	int info;
	Node *link;
};
Node *front , *rear;
//khoi tao queue rong
void init()
{
	front=NULL;
	rear=NULL;
}
//kiem tra queue rong
int isemty()
{
	if(front==NULL)
		return 1;
	return 0;
}
//them phan tu vao queue
void push(int x)
{
	Node *p= new Node;
	p ->info=x;
	p ->link = NULL;
	if(rear==NULL)
		front=p;
	else
		rear->link=p;
	rear=p;
}

//lay phan tu ra khoi queue
int pop(int &x)
{
	
	if(front != NULL)
	{
		Node *p =front;
		x=p->info;
		front = p ->link;
		if(front == NULL)
		{
			rear=NULL;
		}
	
		delete p;
		return 1;
}
	return 0;
}

void process_queue()
{
	if(front !=NULL)
	{
		Node *p = front;
		cout<<"<-----" ;
		do{
			cout<<p->info <<" " ;
			p = p -> link;
		}while(p!=NULL);
		cout<<"<---" << endl;
	}
}

int main()
{
	int choice , x,i;
		system("cls");
		cout<<"-----------bai tap 11----------------" << endl;
		cout<<"1.khoi tao queue rong " << endl;
		cout<<"2.them phan tu vao queue " << endl;
		cout<<"3.lay phan tu ra khoi queue " << endl;
		cout<<"4.kiem tra queue co rong hay khong" << endl;
		cout<<"5.xuat queue " << endl;
		cout<<"6.thoat "<< endl;
		do{
			cout<<"vui long chon so thuc hien " << endl;
			cin >> choice;
			switch(choice)
			{
			case 1:
				init();
				cout<<"ban vua khoi tao queue rong thanh cong " << endl;
				break;
			case 2:
				cout<<"vui long nhap gia tri x= " << x << endl;
				cin >> x;
				push(x);
				cout<<"queue sau khi lay ra la" << endl;
				process_queue();
				break;
			case 3:
				pop(x);
				cout<<"phan tu lay ra tu queue x= " << x << endl;
				cout<<"queue sau khi lay ra " << endl;
				process_queue();
				break;
			case 4:
				i=isemty();
				if(i==0)
					cout<<"queue khong rong " << endl;
				else
					cout<<"queue rong " << endl;
				break;
			case 5:
				cout<<"queue hien tai la" << endl;
				process_queue();
				break;
			case 6:
				cout<<"chao tam biet " << endl;
			default:
				break;
			}
		}while(choice!=6);
			return 0;
}