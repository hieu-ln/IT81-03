#include <iostream>
using namespace std;
//cau 5.1
#define MAX 100
int a[100];
int sp;
//cau 5.2
void init(int a[], int& sp)
{
	sp = -1;
}
//cau 5.3
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
//cau 5.4
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
//cau 5.5
int push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//cau 5.6
int pop(int a[], int& sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//xuat stack
void Process_stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << "\t";
	cout << endl;
}

int main()
{
	int choice, x, i;
	cout << "--------MENU-------\n";
	cout << "1. Khoi tao danh sach rong\n";
	cout << "2. Them phan tu vao stack\n";
	cout << "3. Lay phan tu ra khoi stack\n";
	cout << "4. Kiem tra stack co rong hay khong\n";
	cout << "5. Kiem tra stack co day hay khong\n";
	cout << "6. Xuat stack\n";
	cout << "7. Thoat\n";
	do {
		cout << "Vui long chon thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, sp);
			cout << "Ban vua khoi tao stack rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			i = push(a, sp, x);
			cout << "Stack sau khi them la: ";
			Process_stack(a, sp);
			break;
		case 3:
			i = pop(a, sp, x);
			cout << "Phan tu lay ra tu pop la x = " << x << endl;
			cout << "Stack sau khi lay ra la: ";
			Process_stack(a, sp);
			break;
		case 4:
			i = isEmpty(a, sp);
			if (i == 0)
				cout << "Stack khong rong\n";
			else
				cout << "Stack rong\n";
			break;
		case 5:
			i = isFull(a, sp);
			if (i == 0)
				cout << "Stack chua day\n";
			else
				cout << "Stack day\n";
			break;
		case 6:
			break;
		case 7:
			cout << "Goodbye!!!\n";
			break;
		default:
			break;
		}
	} while (choice < 7);
	system("pause");
	return 0;
};