#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *sp;
void init()
{
	sp = NULL;
}

int isEmpty()
{
	if( sp == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node *p = new Node;
	p ->info = x;
	p ->link = sp;
	sp = p;
}
int Pop( int &x)
{
	if( sp != NULL)
	{
		Node *p = sp;
		x = p ->info;
		sp = p ->link;
		delete p;
		return 1;
	}
	return 0;
}
void Xuat()
{
	Node *p = sp;
	do{
		cout << p ->info << "\t";
		p = p->link;
	}while(p != NULL);
	cout << endl;
}

int main()
{
	int choice,x,i;
	system("cls");
	cout << "---------------MENU--------------"<< endl;
	cout << "1.Khoi tao Stack rong\n";
	cout << "2.Them phan tu vao Stack\n";
	cout << "3.Lay phan tu ra khoi Stack\n";
	cout << "4.Xuat Stack\n";
	cout << "5.Thoat\n";
	do{
		cout << "Ban chon: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init();
			cout << "Tao Stack rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			Push(x);
			cout << "Stack sau khi them la: ";
			Xuat();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra tu Stack la: " << x << endl;
			cout << "Stack sau khi lay ra la: ";
			Xuat();
			break;
		case 4:
			cout << "Stack hien tai la: ";
			Xuat();
		case 5:
			break;
		default:
			break;
		}
	}while(choice != 5);
	system("pause");
	return 0;
}