#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node *first;
void Init()
{
	first = NULL;
}
void process_list()
{
	Node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p ->link;
	}
	cout << endl;
}
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p ->info != x)
	{
		p = p ->link;
	}
	return p;
}
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = first;
	first = p;
}
int delete_first()
{
	if (first != NULL)
	{
		Node *p = first;
		first = first ->link;
		delete p;
		return 1;
	}
	return 0;
}
void insert_last(int x)
{
	Node *p;
	p = new Node;
	p ->info = x;
	p ->link = NULL;
	if( first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while ( q->link != NULL )
			q = q->link;
		q->link = p;
	}
}
int delete_last()
{
	if( first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p ->link;
		}
		if( p != first)
			q ->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
int searchAnddelete( int x)
{
	if( first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if( p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if( p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				if( p->link == NULL && p->info == x)
				{
					q->link = NULL;
					delete p;
					return 1;
				}
				else return 0;
	}
	return 0;
}
void swap(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}
void sort()
{
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while( q != NULL)
		{
			if( q->info < min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}
void sortdics()
{
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while( q != NULL)
		{
			if( q->info > min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout << "----------BAI TAP 3 CHUONG 2 DANH SACH LIEN KET DON------------" << endl;
	cout << "1.Khoi tao DSLK DON rong " << endl;
	cout << "2.Them phan tu vao dau DSLK DON " << endl;
	cout << "3.Them phan tu vao cuoi DSLK DON " << endl;
	cout << "4.Xoa phan tu vao dau DSLK DON " << endl;
	cout << "5.Xoa phan tu vao cuoi DSLK DON " << endl;
	cout << "6.Xuat DSLK DON " << endl;
	cout << "7.Tim gia tri phan tu co trong DSLK DON " << endl;
	cout << "8.Tim mot phan tu va xoa phan tu do trong DSLK DON " << endl;
	cout << "9.Sap xep tang dan DSLK DON " << endl;
	cout << "10.Sap xep giam dan DSLK DON " << endl;
	cout << "11.Thoat " << endl;
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao DSLK DON rong thanh cong! " << endl;
			break;
		case 2:
			cout << "Nhap gia tri x: ";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them la: ";
			process_list();
			break;
		case 3:
			cout << "Nhap gia tri x: ";
			cin >> x;
			insert_last(x);
			cout << "Danh sach sau khi them la: ";
			process_list();
			break;
		case 4:
			i = delete_first();
			if( i == 0)
				cout << "Danh sach rong khong the xoa! " << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau trong DSLK DON !" << endl;
				cout << "Danh sach sau khi xoa la: ";
				process_list();
			}
			break;
		case 5:
			{
				i = delete_last();
			if( i == 0)
				cout << "Danh sach rong khong the xoa! " << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi trong DSLK DON !" << endl;
				cout << "Danh sach sau khi xoa la: ";
				process_list();
			}
			break;
			}
		case 6:
			cout << "Danh sach hien tai la: ";
			process_list();
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim ";
			cin >> x;
			p = Search(x);
			if(p != NULL)
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 8:
			cout << "Nhap gia tri x: ";
			cin >> x;
			i = searchAnddelete(x);
			if ( i == 1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong " << endl;
				cout << "Danh sach sau khi xoa: ";
				process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 9:
			sort();
			cout << "Danh sach sau khi duoc sap xep tang dan la: ";
			process_list();
			break;
		case 10:
			sortdics();
			cout << "Danh sach sau khi duoc sap xep giam dan la: ";
			process_list();
			break;
		case 11:
			cout << "Goodbye.....!" << endl;
			break;
		default:
			break;
		}
	} while(choice != 11);
	return 0;
	}