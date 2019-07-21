#include <iostream>
using namespace std;
//cau 10.1
struct Node
{
	int info;
	Node* link;
};
Node* sp;
//cau 10.2
void init()
{
	sp = NULL;
}
//cau 10.3
int isEmpty()
{
	if (sp == NULL)
		return 1;
	return 0;
}
//cau 10.4
void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
//cau 10.5
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
//xuat
void Process_stack()
{
	Node* p = sp;
	do {
		cout << p->info << "	";
		p = p->link;
	} while (p != NULL);
	cout << endl;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "---------MENU--------\n";
	cout << "1. Khoi tao stack rong\n";
	cout << "2. Them phan tu vao Queue\n";
	cout << "3. Lay phan tu ra khoi Queue\n";
	cout << "4. Xuat\n";
	cout << "5. Thoat\n";
	do {
		cout << "Vui long chon thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao stack rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			push(x);
			cout << "Stack sau khi them la: ";
			Process_stack();
			break;
		case 3:
			i = pop(x);
			cout << "Phan tu lay ra tu pop la x = " << x << endl;
			cout << "Stack sau khi lay ra la: ";
			Process_stack();
			break;
		case 4:
			cout << "Stack hien tai la: ";
			Process_stack();
			break;
		case 5:
			cout << "Goodbye!!!\n";
			break;
		default:
			break;
		}
	} while (choice < 5);
	system("pause");
	return 0;
}