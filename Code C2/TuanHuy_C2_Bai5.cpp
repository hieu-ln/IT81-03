#include <iostream>
#include <stdio.h>
using namespace std;
#define max 100
void init(int a[] , int &sp )
{
	sp = -1 ;
}
//kiem tra ngan xep rong
int isemty(int a[] , int sp)
{
	if (sp == -1 )
		return 1;
	return 0;
}
//kiem tra ngan xep day
int isfull( int a[] , int sp)
{
	if (sp = max - 1 )
		return 1;
	return 0;
}
// them phan tu vao ngan xep
int push( int a[],int &sp, int x )
{
	if ( sp < max - 1 )
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int pop(int a[] , int &sp, int x )
{
	if(sp != -1)

	{
		x=a[sp--];
	return 1;
	}
	return 0;
}

void process_stack( int a[] , int sp )
{
	for ( int i = 0 ; i < sp + 1; i++ )
	{
		cout<<a[i] <<"\t" ;
		cout<< endl;
	}
}

int main()
{
	int a[max];
	int choice,x,i,sp;
	system("cls");
	cout<<"-------bai tap 5-----------" << endl;
	cout<<"1.khoi tao stack rong" << endl;
	cout<<"2.them ptu vao stach "<< endl;
	cout<<"3.lay phan tu ra khi stack" << endl;
	cout<<"4.kiem tra stack co rong khong" << endl;
	cout<<"5.kiem tra stack co day khong" << endl;
	cout<<"6.xuat stack" << endl;
	cout<<"7.thoat" << endl;
	do{
		cout<<"vui long chon so de thuc hien \n " ;
		cin >> choice;
		switch(choice)
		{
			case 1:
				init(a,sp);
				cout<<"ban vua khoi tao stack rong thanh cong " << endl;
				break;
			case 2:
				cout<<"vui long nhap gia tri x= " <<endl;
				cin>>x;
				i=push(a,sp,x);
				cout<<"stack sau khi them la " << endl;
				process_stack(a,sp);
				break;
			case 3:
				i=pop(a,sp,x);
				cout<<"phan tu lay ra tu stack x= " << x << endl;
				cout<<"stack sau khi lay ra la " << endl;

				process_stack(a,sp);
			case 4:
				i=isfull(a,sp);
				if(i=-0)
					cout<<"stack chua day " <<x<<endl;
				else
					cout<<"stack da day " << endl;
				break;
			case 5:
				i=isemty(a,sp);
				if(i=-0)
					cout<<"stack chua rong " <<x<<endl;
				else
					cout<<"stack rong " << endl;
				break;
			case 6:
				cout<<"stack hien tai la" << endl;
				process_stack(a,sp);
				break;
			case 7:
				cout<<"goodbye"<< endl;
				break;
			default:
				break;
		}
	}while(choice !=7);
	system("pause");
	return 0;
}



