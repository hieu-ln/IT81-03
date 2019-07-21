#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *next, *previous;
};
Node *first, *last;

void init()
{
	first = NULL;
	last = NULL;
}

void Process_list()
{
	Node *p;
	p = first;
	while (p!=NULL)
	{
		cout << p->info << "\t";
		p=p->next;
	}
	cout << endl;
}

void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = first;
	p->previous = NULL;
	if(first != NULL)
		first->previous = p;
	else last = p;
	first = p;
}

void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if(last != NULL)
		last->next = p;
	else first = p;
	last = p;
}

int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if(first != NULL)
			first->previous = NULL;
		else last = NULL;
		return 1;
	}
	return 0;
}

int Delete_last()
{
	if(last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if(last != NULL)
			last->next = NULL;
		else first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

Node *Search(int x)
{
	Node *p;
	p = first;
	while( (p!=NULL) && (p->info != x))
		p=p->next;
	return p;
}

int Del(int x)
{
	Node *p = Search(x);
	if (p != NULL)
	{
		if (p == first)
		{
			if (Delete_first())
				return 1;
			else 
				return 0;
		}
		else if (p == last)
		{
			if (Delete_last())
				return 1;
			else
				return 0;
		}
		else
		{
			Node *q;
			q = p->previous;
			q->next = p->next;
			(p->next)->previous = q;
			delete p;
			return 1;
		}
	}
	return 0;
}

//int Insert (Node *p, int x)
//{
//	if (p==first)
//	{
//		Insert_first(x);
//		return 1;
//	}
//	else 
//	{
//		Node *n = new Node;
//		n->info = x;
//		n->next = p;
//		p->previous = n;
//	}
//}

int main()
{
	int ch, x, a;
	cout << "-----------------MENU------------------\n";
	cout << "1. Khoi tao danh sach rong\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Them phan tu vao dau danh sach\n";
	cout << "4. Them phan tu cuoi danh sach\n";
	cout << "5. Xoa phan tu dau danh sach\n";
	cout << "6. Xoa phan tu cuoi danh sach\n";
	cout << "7. Tim va xoa 1 phan tu\n";
	cout << "8. \n";
	cout << "9. Thoat\n";
	do
	{
		cout << "Chon so de thuc hien: ";
		cin >> ch;
		switch(ch)
		{
		case 1: 
			init();
			cout << "Khoi tao danh sach rong thanh cong!\n";
			break;
		case 2:
			cout << "Danh sach hien tai:\n";
			Process_list();
			break;
		case 3: 
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_first(x);
			cout << "Them phan tu thanh cong!\n";
			break;
		case 4: 
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_last(x);
			cout << "Them phan tu thanh cong!\n";
			break;
		case 5:
			Delete_first();
			cout << "Xoa phan tu thanh cong!\n";
			break;
		case 6:
			Delete_last();
			cout << "Xoa phan tu thanh cong!\n";
			break;
		case 7:
			cout << "Nhap phan tu can tim va xoa: ";
			cin >> a;
			if(Del(a))
				cout << "Xoa phan tu thanh cong\n";
			else
				cout << "Khong tim phan phan tu " << a << endl;
			break;
		case 9:
			cout << "Chuong trinh ket thuc..." << endl;
			break;
		default: 
			break;
		}
	} while (ch!=9);
}