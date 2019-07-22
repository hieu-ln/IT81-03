//Bai 5, chuong 2: DS han che, ngan xep, stack
#include <iostream>
using namespace std;

#define MAX 100

//Cau 5.2: Khoi tao stack rong
void init(int a[], int& sp)
{
	sp = -1;
}
//Cau 5.3: Kiem tra ngan xep rong
int isEmpty(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}
//Cau 5.4: Kiem tra ngan xep day
int isFull(int a[], int sp)
{
	if (sp == MAX - 1)
		return 1;
	return 0;
}
//Cau 5.5: Them phan tu va ngan xep
int push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//Cau 5.6: Xoa 1 phan tu
int pop(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//Xuat stack
void process_Stack(int a[], int sp)
{
	for (int i = 0; i < sp + 1; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}

int main()
{
	int a[MAX];
	int choice, sp, x, i;
	system("cls");
	cout << "-------- BAI TAP 5, CHUONG 2, STACK (NGAN XEP - DS DAC) --------\n";
	cout << "1. Khoi tao STACK rong\n2. Them phan tu vao STACK\n3. Lay phan tu ra khoi STACK\n4. Kiem tra STACK co rong hay khong\n5. Kiem tra STACK co day hay khong\n6. Xuat STACK\n7. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao STACK rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri x = ";
			cin >> x;
			i = push(a, sp, x);
			cout << "STACK sau khi them la: ";
			process_Stack(a, sp);
			break;
		case 3:
			i = pop(a, sp, x);
			cout << "Phan tu lay ra tu STACK la: " << x << endl;
			cout << "STACK sau khi lay ra la: ";
			process_Stack(a, sp);
			break;
		case 4:
			i = isEmpty(a, sp);
			if (i == 0)
				cout << "STACK khong rong\n";
			else
				cout << "STACK rong\n";
			break;
		case 5:
			i = isFull(a, sp);
			if (i == 0)
				cout << "STACK chua day\n";
			else
				cout << "STACH da day\n";
			break;
		case 6:
			cout << "STACK hien tai la: ";
			process_Stack(a, sp);
			break;
		case 7:
			cout << "Tam biet\n";
		default:
			break;
		}
	} while (choice != 7);
	system("pause");
	return 0;
}