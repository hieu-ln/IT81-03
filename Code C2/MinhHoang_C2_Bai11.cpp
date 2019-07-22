//Bai 11, chuong 2: DS han che, hang doi, QUEUE
//QUEUE su dung DSLK
#include <iostream>
using namespace std;

//Cau 11.1: Khai bao cau truc QUEUE
struct Node
{
	int info;
	Node* link;
};
Node* front, * rear;
//Cau 11.2: Khoi tao QUEUE rong
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
//Cau 11.4: Them phan tu vao QUEUE
void push(int x)
{
	Node* p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear = NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
//Cau 11.5: Lay phan tu ra khoi QUEUE
int pop(int& x)
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
//Xuat QUEUE
void process_Queue()
{
	if (front != NULL)
	{
		Node* p = front;
		cout << "<--\t";
		do {
			cout << p->info << "\t";
			p = p->link;
		} while (p != NULL);
		cout << "<--\n";
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "-------- BAI TAP 11, CHUONG 2, QUEUE (HANG DOI - DSLK) --------\n";
	cout << "1. Khoi tao QUEUE rong\n2. Them phan tu vao QUEUE\n3. Lay phan tu ra khoi QUEUE\n4. Kiem tra QUEUE co rong hay khong\n5. Xuat QUEUE\n6. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao QUEUE rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri x = ";
			cin >> x;
			push(x);
			cout << "QUEUE sau khi them la: ";
			process_Queue();
			break;
		case 3:
			pop(x);
			cout << "Phan tu lay ra tu QUEUE la: " << x << endl;
			cout << "QUEUE sau khi lay ra la: ";
			process_Queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << "QUEUE khong rong\n";
			else
				cout << "QUEUE rong\n";
			break;
		case 5:
			cout << "QUEUE hien tai la: ";
			process_Queue();
			break;
		case 6:
			cout << "Tam biet\n";
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}