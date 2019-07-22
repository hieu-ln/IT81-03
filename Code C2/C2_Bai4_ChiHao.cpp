#include <iostream>
using namespace std;

//Khai bao cau truc danh sach
struct Node
{
	int info;
	Node *link;
};
Node *first;

//Khoi tao danh sach rong
void Init()
{
	first = NULL;
}

//Them 1 phan tu vao danh sach
void Insert(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

void Insert_list(int x)
{
	Node *p, *q, *before;
	p = new Node; 
	p->info = x;
	q = first;
	while(q != NULL && q->info>x)
	{
		before = q;
		q = q->link;
	}
	if(q == first)
		first = p;
	else
		before->link = p;
	p->link = q;
}

//Xuat cac phan tu trong danh sach
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

//Tim 1 phan tu trong danh sach
Node *Search(int x)
{
	Node *p = first;
	while (p != NULL && p ->info != x)
	{
		p = p ->link;
	}
	return p;
}

//Xoa dau
int Delete_first()
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

//Xoa cuoi
int Delete_last()
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

//Tim 1 phan tu trong danh sach, xoa phan tu neu co
int Search_Delete(int x)
{
	if (Search(x) != NULL)
	{
		Node *p = Search(x);
		if (p == first)
		{
			if(Delete_first())
				return 1;
		}
		else
			if (p->link == NULL)
			{
				if(Delete_last())
					return 1;
			}
			else
			{
				Node *q = first, *r = first;
				while (r != p)
				{
					q = r;
					r = r->link;
				}
				q->link = p->link;
				delete p;
				return 1;
			}
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	Insert(1);
	Insert(4);
	Insert(6);
	Insert(8);
	Insert(9);
	Insert(11);
	system("cls");
	cout << "----------	BAI TAP 4, CHUONG 2 (NGAN XEP, DSLKD)	---------\n";
	cout << "1.Khoi tao danh sach rong\n";
	cout << "2.Them 1 phan tu vao vi tri phu hop\n";
	cout << "3.Xuat danh sach\n";
	cout << "4.Tim 1 phan tu\n";
	cout << "5.Tim va xoa 1 phan tu\n";
	cout << "6.Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			Init();
			cout << "Ban vua khoi tao danh sach rong thanh cong!\n";
			break;
		case 2:
			cout << "Nhap phan tu can them: ";
			cin >> x;
			Insert_list(x);
			cout << "Danh sach sau khi them phan tu vao vi tri phu hop la: ";
			process_list();
			break;
		case 3:
			cout << "Danh sach hien tai la: ";
			process_list();
			break;
		case 4:
			cout << "Vui long nhap gia tri can tim ";
			cin >> x;
			p = Search(x);
			if(p != NULL)
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 5:
			cout << "Nhap gia tri x: ";
			cin >> x;
			i = Search_Delete(x);
			if (i == 1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong " << endl;
				cout << "Danh sach sau khi xoa: ";
				process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 6:
			cout << "Goodbye...!\n";
			break;
		default:
			break;
		}
	} while(choice != 6);
	return 0;
}