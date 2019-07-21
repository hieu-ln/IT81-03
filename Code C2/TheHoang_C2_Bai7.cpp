#include <iostream>
#include <stdio.h>
using namespace std;
 
#define MAX 100

void init( int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
int isEmpty( int a[], int &front, int &rear)
{
	if( front == rear)
		return 1;
	else
		return 0;
}
int isFull( int a[], int &front, int &rear)
{
	if((front == 0 && rear == MAX -1 || (front-rear == 1)))
		return 1;
	else
		return 0;
}
int Push( int a[], int &front, int &rear, int x)
{
	if( rear - front == MAX -1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if( rear == MAX - 1)
		{
			for( int i = front; i <= rear; i++)
			{
				a[ i - front] = a[i];
			}
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}
int Pop( int a[], int &front, int &rear, int &x)
{
	if( front == -1)
		return 0;
	else
	{
		x = a[front++];
		if( front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}
void Xuat( int a[], int f, int r)
{
	cout << "f = " << f << "\t" << r << endl;
	if( f <= r && f != 1)
	{
		cout << " <--  ";
		for( int i = f; i < r + 1; i++)
		{
			cout << a[i] << "\t";
		}
		cout << " <--  " << endl;
	}
}

int main()
{
	int a[MAX];
	int choice, f, r, x, i;
	system("cls");
	cout << "--------MENU-----------" << endl;
	cout << "1.Khoi tao Queue rong\n";
	cout << "2.Them phan tu vao Queue\n";
	cout << "3.Lay phan tu ra khoi Queue\n";
	cout << "4.Kiem tra Queue co rong hay khong\n";
	cout << "5.Kiem tra Queue co day hay khong\n";
	cout << "6.Xuat Queue\n";
	cout << "7.Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a,f,r);
			cout << "Khoi tao Queue rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			i = Push(a,f,r,x);
			cout << "Queue sau khi them la: ";
			Xuat(a,f,r);
			break;
		case 3:
			i = Pop(a,f,r,x);
			cout << "Phan tu lay ra tu Queue la: " << x << endl;
			cout << "Queue sau khi lay ra la: ";
			Xuat(a,f,r);
			break;
		case 4:
			i = isFull(a,f,r);
			if( i == 0)
				cout << "Queue chua day\n";
			else
				cout << "Queue da day\n";
			break;
		case 5:
			i = isEmpty(a,f,r);
			if( i == 0)
			{
				cout << "Queue khong rong\n";
			}
			else
				cout << "Queue rong\n";
			break;
		case 6:
			cout << "Queue hien tai la: ";
			Xuat(a,f,r);
			break;
		case 7:
			break;
		default:
			break;
		}
	}while(choice != 7);
	system("pause");
	return 0;
}