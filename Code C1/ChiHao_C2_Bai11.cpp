//QUEUE su dung DSLK
#include <iostream>
using namespace std;

//Khai bao cau truc QUEUE
struct Node
{
	int info;
	Node *link;
};
Node *front, *rear;

//Khoi tao QUEUE rong
void init()
{
	front = NULL;
	rear = NULL;
}

//Kiem tra QUEUE rong
int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

//Them phan tu vao QUEUE
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

//Lay phan tu ra khoi QUEUE
int Pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Xuat QUEUE
void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		cout << "<--\t";
		do {
			cout << p->info << "\t";
			p = p->link;
		} while (p != NULL);
		cout << "<--" << endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "---------	BAI TAP 11, CHUONG 2, QUEUE (HANG DOI - DSLK)	---------\n";
	cout << "1. Khoi tao QUEUE rong\n";
	cout << "2. Them phan tu vao QUEUE\n";
	cout << "3. Lay phan tu ra khoi QUEUE\n";
	cout << "4. Kiem tra QUEUE co rong hay khong\n";
	cout << "5. Xuat QUEUE\n";
	cout << "6. Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khi tao QUEUE rong thanh cong\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			Push(x);
			cout << "QUEUE sau khi them la: ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra tu QUEUE la x = " << x << endl;
			cout << "QUEUE sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << "QUEUE khong rong!\n";
			else
				cout << "QUEUE rong!\n";
			break;
		case 5:
			cout << "QUEUE hien tai la: ";
			Process_queue();
			break;
		case 6:
			cout << "Goodbye...!\n";
			break;
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}