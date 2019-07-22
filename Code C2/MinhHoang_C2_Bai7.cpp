//Bai 7, chuong 2: DS han che, hang doi, QUEUE
//QUEUE su dung danh sach dac
#include <iostream>
using namespace std;

#define MAX 100

//Cau 7.2: Khoi tao QUEUE rong
void init(int a[], int& front, int& rear)
{
	front = -1;
	rear = -1;
}
//Cau 7.3: Kiem tra QUEUE rong
int isEmpty(int a[], int& front, int& rear)
{
	if (front == rear)
		return 1;
	return 0;
}
//Cau 7.4: Kiem tra QUEUE day
int isFull(int a[], int& front, int& rear)
{
	if (front == 0 && rear == MAX - 1 || front - rear == 1)
		return 1;
	return 0;
}
//Cau 7.5: Them phan tu vao QUEUE
int push(int a[], int& front, int& rear, int x)
{
	if (rear - front == MAX - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
	return 0;
}
//Cau 7.6: Lay 1 phan tu ra khoi QUEUE
int pop(int a[], int& front, int& rear, int& x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
	return 0;
}
//Xuat QUEUE
void process_Queue(int a[], int f, int r)
{
	cout << "f= " << f << "\t r= " << r << endl;
	if (f <= r && f != -1)
	{
		cout << "<--\t";
		for (int i = f; i < r + 1; i++)
		{
			cout << a[i] << "\t";
		}
		cout << "<--\n";
	}
}

int main()
{
	int a[MAX];
	int choice, f, r, x, i;
	system("cls");
	cout << "-------- BAI TAP 7, CHUONG 2, QUEUE (HANG DOI) --------\n";
	cout << "1. Khoi tao QUEUE rong\n2. Them phan tu vao QUEUE\n3. Lay phan tu ra khoi QUEUE\n4. Kiem tra QUEUE co rong hay khong\n5. Kiem tra QUEUE co day hay khong\n6. Xuat QUEUE\n7. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, f, r);
			cout << "Khoi tao QUEUE rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri x = ";
			cin >> x;
			i = push(a, f, r, x);
			cout << "QUEUE sau khi them la: ";
			process_Queue(a, f, r);
			break;
		case 3:
			i = pop(a, f, r, x);
			cout << "Phan tu lay ra tu QUEUE la: " << x << endl;
			cout << "QUEUE sau khi lay ra la: ";
			process_Queue(a, f, r);
			break;
		case 4:
			i = isEmpty(a, f, r);
			if (i == 0)
				cout << "QUEUE khong rong\n";
			else
				cout << "QUEUE rong\n";
			break;
		case 5:
			i = isFull(a, f, r);
			if (i == 0)
				cout << "QUEUE chua day\n";
			else
				cout << "QUEUE da day\n";
			break;
		case 6:
			cout << "QUEUE hien tai la: ";
			process_Queue(a, f, r);
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