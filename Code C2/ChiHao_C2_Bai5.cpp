//Khai bao cau truc stack, khoi tao stack rong, kiem tra stack rong, day, them 1 phan tu vao stack, xoa 1 phan tu trong stack
#include <iostream>
#include <conio.h>
using namespace std;

#define MAX 3

//Khoi tao STACK rong
void init(int a[], int &sp)
{
	sp = -1;
}

//Kiem tra ngan xep day
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}

//Kiem tra ngan xep rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

//Them phan tu vao ngan xep
int Push(int a[], int &sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

//Xoa 1 phan tu
int Pop(int a[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

//Xuat STACK
void Process_stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << "\t";
	cout << endl;
}

int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "-----------	BAI TAP 5, CHUONG 2, STACK (NGAN XEP _ DS DAC)	----------\n";
	cout << "1. Khoi tao STACK rong\n";
	cout << "2. Kiem tra STACK rong hay khong\n";
	cout << "3. Kiem tra STACK day hay khong\n";
	cout << "4. Them 1 phan tu vao STACK\n";
	cout << "5. Lay phan tu ra khoi STACK\n";
	cout << "6. Xuat STACK\n";
	cout << "7. Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			init(a, sp);
			cout << "Ban vua khoi tao STACK rong thanh cong\n";
			break;
		case 2:
			i = isEmpty(a, sp);
			if (i == 0)
				cout << "STACK khong rong!\n";
			else
				cout << "STACK rong!\n";
			break;
		case 3:
			i = isFull(a, sp);
			if (i == 0)
				cout << "STACK chua day!\n";
			else
				cout << "STACK da day!\n";
			break;
		case 4:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			i = Push(a, sp, x);
			cout << "STACK sau khi them la: ";
			Process_stack(a, sp);
			break;
		case 5:
			i = Pop(a, sp, x);
			cout << "Phan tu lay ra tu STACK x = " << x << endl;
			cout << "STACK sau khi lay ra la: ";
			Process_stack(a, sp);
			break;
		case 6:
			cout << "STACK hien tai la: ";
			Process_stack(a, sp);
			break;
		case 7:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
		_getch();
	} while (choice != 7);
	return 0;
}