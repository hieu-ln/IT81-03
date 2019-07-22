#include <iostream>
using namespace std;

//Khai bao cau truc STACK
struct Node
{
	int info;
	Node *link;
};
Node *sp;

//Khoi tao STACK rong
void init()
{
	sp = NULL;
}

//Kiem tra STACK rong
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}

//Them phan tu vao STACK
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

//Lay phan tu ra khoi STACK
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

//Xuat STACK
void Process_stack()
{
	Node *p =  sp;
	do {
		cout << p->info << "\t";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}


//Doi tu he thap phan sang he nhi phan
int decimalToBinary(int x)
{
	init();
	while(x != 0)
	{
		int r = x % 2;
		Push(r);
		x /= 2;
	}
	int bin = 0;
	while (!isEmpty())
	{
		int y;
		if (Pop(y))
			bin = bin * 10 + y;
	}
	return bin;
}

//Giai bai toan thap Ha Noi
void HNtower(int n, char x, char y, char z)
{
	if (n == 1)
	{
		cout << "\t" << x << "\t\t" << y << endl;
		return;
	}
	HNtower(n - 1, x, y, z);
    HNtower(1, z, y, z);
    HNtower(n - 1, y, x, z);
}

int main()
{
	int choice, x;
	char  a = 'A', b = 'B', c = 'C';
	system("cls");
	cout << " ----------	BAI TAP 10, CHUONG 2, STACK (NGAN XEP - DSLK)	---------\n";
	cout << "1. Khoi tao STACK rong\n";
	cout << "2. Them phan tu vao STACK\n";
	cout << "3. Lay phan tu ra khoi STACK\n";
	cout << "4. Xuat STACK\n";
	cout << "5. Doi 1 so tu he thap phan sang he nhi phan\n";
	cout << "6. Giai bai toan thap Ha Noi\n";
	cout << "7. Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vau khoi tao STACK rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Push(x);
			cout << "STACK sau khi them la: ";
			Process_stack();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra tu STACK x = " << x << endl;
			cout << "STACK sau khi lay ra: ";
			Process_stack();
			break;
		case 4:
			cout << "STACK hien tai la: ";
			Process_stack();
			break;
		case 5:
			cout << "Nhap gia tri thap phan can doi sang nhi phan: ";
			cin >> x;
			cout << x << " co dang nhi phan la: " << decimalToBinary(x) << endl;
			break;
		case 6:
			cout << "Nhap so luong dia: ";
			cin >> x;
			HNtower(x, a, b, c);
			break;
		case 7:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
	} while (choice != 7);
	return 0;
}