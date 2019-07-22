#include <iostream>
using namespace std;
//cau 11.1
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
//cau 11.2
void init()
{
	front = NULL;
	rear = NULL;
}
//cau 11.3
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}
//cau 11.4
void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
//ccau 11.5
int pop(int &x)
{
	if (front != NULL)
	{
		Node* p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//xuat 
void Process_queue()
{
	if (front != NULL)
	{
		Node* p = front;
		cout << "<--	";
		do {
			cout << p->info << "	";
			p = p->link;
		} while (p != NULL);
		cout << "<--	";
	}
	cout << endl;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << "-----------MENU----------\n";
	cout << "1. Khoi tao rong\n";
	cout << "2. Them phan tu vao Queue\n";
	cout << "3. Lay phan tu ra khoi Queue\n";
	cout << "4. Kiem tra Queue co rong hay khong\n";
	cout << "5. Xuat\n";
	cout << "6. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao Queue rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			push(x);
			cout << "Queue sau khi them la: ";
			Process_queue();
			break;
		case 3:
			i = pop(x);
			cout << "Phan tu lay ra tu Queue la x = " << x << endl;
			cout << "Queue sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << "Queue khong rong \n";
			else
				cout << "Queue rong\n";
			break;
		case 5:
			cout << "Queue hien tai la: ";
			Process_queue();
			break;
		case 6:
			cout << "Goodbye!!!\n";
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}