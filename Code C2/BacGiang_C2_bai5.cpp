#include <iostream>
using namespace std;
# define MAX 100
int a[MAX];
int n;
void init(int a[], int &n)
{
	n = -1;
}

int isFull(int a[], int n)
{
	if(n == MAX - 1)
		return 1;
	return 0;
}
int isEmpty( int a[], int n)
{
	if( n == -1)
		return 1;
	return 0;
}
int them1( int a[], int &n, int x)
{
	if( n < MAX - 1)
	{
		a[++n] = x;
		return 1;
	}
	return 0;
}
int xoa1( int a[], int &n, int &x)
{
	if(n != -1)
	{
		x = a[n--];
		return 1;
	}
	return 0;
}
void xuat( int a[], int n)
{
	for( int i = 0; i < n + 1; i++)
	{
		cout << a[i] <<"\t";
	}
	cout << endl;
}
int convert(int so)
{
	init(a,n);
	int np = 0;
	while( so != 0)
	{
		int du = so % 2;
		if( them1(a,n,du) == 1)
			so /= 2;
		else break;
	}
	while (isEmpty(a,n) == 0)
	{
		int x;
		if(xoa1(a,n,x) == 1)
			np = np * 10 + x;
		else
			break;
	}
	return np;
}
int main()
{
	int a[MAX];
	int chon,n,x,i,tp;
	cout << "----------MENU---------" << endl;
	cout << "1.Khoi tao Stack rong" << endl;
	cout << "2.Kiem tra Stack co rong hay khong" << endl;
	cout << "3.Kiem tra Stack co day hay khong" << endl;
	cout << "4.Them phan tu vao Stack" << endl;
	cout << "5.Lay phan tu ra khoi Stack" << endl;
	cout << "6.Xuat Stack" << endl;
	cout << "7.Doi mot so sang he thap phan" << endl;
	cout << "8.Thoat" << endl;
	do{
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init(a,n);
			cout << "Ban vua khoi tao Stack rong thanh cong" << endl;
			break;
		case 2:
			i = isEmpty(a,n);
			if( i == 0)
				cout << "Stack khong rong\n";
			else
				cout << "Stack rong\n";
			break;
		case 3:
			i = isFull(a,n);
			if( i == 0)
				cout << "Stack chua day\n";
			 else
				cout << "Stack da day\n";
			break;
		case 4:
			cout << "Nhap gia tri phan tu can them: ";
			cin >> x;
			i = them1(a,n,x);
			cout << "Stack sau khi them la: ";
			xuat(a,n);
			break;
		case 5:
			int x;
			i = xoa1(a,n,x);
			cout << "Phan tu can lay ra khoi Stack la: " << x << endl;
			cout << "Stack sau khi lay ra la: ";
			xuat(a,n);
			break;
		case 6:
			cout << "Stack hien tai la: ";
			xuat(a,n);
			break;
		case 7:
			cout << "Nhap gia tri can chuyen:";
			cin >> tp;
			cout << "Gia tri thap phan tuong ung la: " << convert(tp) << endl;
			break;
		case 8:
			break;
		default:
			break;
		}
	}while(chon != 8);
	return 0;
}
