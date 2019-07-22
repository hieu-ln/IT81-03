#include <iostream>
#include <stdio.h>
using namespace std;
#define max 100
//khoi tao queue rong
void init(int a[], int &front, int &rear )
{
	front= -1;
	rear=-1;
}
int isemty(int a[], int &front, int &rear )
{
	if(front==rear)
		return 1;
	else
	return 0;
}

int isfull(int a[],int &front, int &rear )
{
	if(front==0 &&rear== max - 1 ||(front-rear==1))
		return 1;
	else
		return 0;
}
//them phan tu vao queue
int push(int a[],int &front, int &rear, int x)
{
	if(rear - front== max -  1)
		return 0;
	else
	{
		if(front == -1 )
			front=0;
		if(rear==max-1)
		{
			for(int i=0;i<rear;i++)
			{
				a[i-front]=a[i];
			}
			rear=max-1-front;
			front=0;
	}
	
	a[++rear]=x;
	return 1;
	}
	return 0;

}
//lay 1 phan tu ra khoi queue
int pop(int a[], int &front, int &rear, int &x)
{
	if(front ==-1)
		return 0;
	else
	{
		x=a[front++];
		if(front > rear )
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}
//xuat queue
	void process_queue( int a[] , int &f, int &r )
	{
		cout<<"f=" << f<<"\t"<<"r="<< r << endl;
		if(f<=r && f!=-1)
		{
			cout<<"<---- ";
		for(int i=f;i<r+1; i++)
		{
			cout<<a[i]<<" " ;
		}
		cout<<"<---- " << endl; 
		}
	}
	int main()
	{
		int a[max];
		int choice , x,i,f,r;
		system("cls");
		cout<<"-----------bai tap 7----------------" << endl;
		cout<<"1.khoi tao queue rong " << endl;
		cout<<"2.them phan tu vao queue " << endl;
		cout<<"3.lay phan tu ra khoi queue " << endl;
		cout<<"4.kiem tra queue co rong hay khong " << endl;
		cout<<"5.kiem tra queue co day hay khong " << endl;
		cout<<"6.xuat queue " << endl;
		cout<<"7.thoat " << endl;
		do{
			cout<<"vui long chon so thuc hien " << endl;
			cin >> choice;
			switch(choice)
			{
			case 1:
				init(a,f,r);
				cout<<"ban vua khoi tao queue rong thanh cong " << endl;
				break;
			case 2:
				cout<<"vui long nhap gia tri x= " << x << endl;
				cin >> x;
				i=push(a,f,r,x);
				cout<<"queue sau khi lay ra la" << endl;
				process_queue(a,f,r);
				break;
			case 3:
				i=pop(a,f,r,x);
				cout<<"phan tu lay ra tu queue x= " << x << endl;
				cout<<"queue sau khi lay ra " << endl;
				process_queue(a,f,r);
				break;
			case 4:
				i=isfull(a,f,r);
				if(i==0)
					cout<<"queue chua day " << endl;
				else
					cout<<"queue day " << endl;
				break;
			case 5:
				i=isemty(a,f,r);
				if(i==0)
					cout<<"queue khong rong " << endl;
				else
					cout<<"queue rong " << endl;
				break;
			case 6:
				cout<<"queue hien tai la" << endl;
				process_queue(a,f,r);
				break;
			case 7:
				cout<<"chao tam biet " << endl;
			default:
				break;
			}
		}while(choice!=7);
			return 0;
}





