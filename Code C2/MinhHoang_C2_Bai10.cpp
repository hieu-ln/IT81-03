//Bai 10, chuong 2: DS han che, hang doi, STACK
//STACK su dung DSLK DON
#include <iostream>
using namespace std;

//Cau 10.1: Khai bao cau truc STACK
struct Node
{
	int info;
	Node* link;
};
Node* sp;
//Cu 10.2: Khoi tao STACK rong
void init()
{
	sp = NULL;
}
//Cau 10.3: Kiem tra STACK rong
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//Cau 10.4: Them phan tu vao STACK
void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//Cau 10.5: Lay phan tu ra khoi STACK
int pop(int& x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//Xuat STACK
void process_Stack()
{
	Node* p = sp;
	do {
		cout << p->info << "\t";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "-------- BAI TAP 10, CHUONG 2, STACK (NGAN XRP - DSLK) --------\n";
	cout << "1. Khoi tao STACK rong\n2. Them phan tu vao STACK\n3. lay phan tu ra khoi STACK\n4. Xuat STACK\n5. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao STACK rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri x = ";
			cin >> x;
			push(x);
			cout << "STACK sau khi them la: ";
			process_Stack();
			break;
		case 3:
			pop(x);
			cout << "Phan tu lay ra tu STACK la: " << x << endl;
			cout << "STACK sau khi lay ra la: ";
			process_Stack();
			break;
		case 4:
			cout << "STACK hien tai la: ";
			process_Stack();
			break;
		case 5:
			cout << "Tam biet\n";
		default:
			break;
		}
	} while (choice != 5);
	system("pause");
	return 0;
}