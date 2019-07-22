#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
	int info;
	Node *next,
	*previous;
};
Node *first, *last;
void init()
{
	first=NULL;
	last=NULL;
}
Node *ds;
void xuat()
{
	Node *p= new Node;
	p=ds;
	while(p!=NULL)
	{
		cout << p->info << "  ";
		p=p->next;                   //HAM NAY SAI, XEM LAI.
	}
	cout <<endl;
}
void themDau(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=first;
	p->previous=NULL;
	if(first!=NULL)
		first -> previous=p;
	else //ds rong. truoc khi them p
		last =p; // sau khi them p, ds co 1 phan tu
	first=p;
}
void themCuoi(int x)
{
	Node *p;
	p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if(last!= NULL)
		last->next=p;
	else //ds rong truoc khi them p
		first=p; // sau khi them p, ds co 1 phan tu
	last =p;
}
int xoaDau()
{
	if(first != NULL)
	{
		Node *p=first;
		first =first->next;
		delete p;
		if(first != NULL)
			first->previous;
		else
			last=NULL;
		return 1;
	}
	return 0;
}
int xoaCuoi()
{
	if(last !=NULL)
	{
		Node *p=last;
		last=last-> previous;
		if(last !=NULL)
			last->next=NULL;
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}
Node *Search(int y)
{
	Node *p;
	p=first;
	while((p!=NULL)&&(p->info!=y))
		p=p->next;
	return p;
}
int xoa(int y)
{
	Node *p=Search(y);
	if(p!=NULL)
	{
		if(p==first)
		{
			if(xoaDau())
				return 1;
			else return 0;
		}
		else if(p==last)
		{
			if(xoaCuoi())
				return 1;
			else return 0;
		}
		else 
		{
			Node *q;
			q=p->previous;
			q->next=p->next;
			(p->next)->previous=q;
			delete p;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1.Khoi tao danh sach rong\n2.Xuat danh sach\n3.Them 1 phan tu vao dau danh sach\n4.Them 1 phan tu cuoi danh sach\n5.Xoa phan tu dau\n6.Xoa phan tu cuoi\n7.Tim va xoa phan tu\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
				cout << "Khoi tao ds rong thanh cong!";
				break;
		case 2:
			cout << "Danh sach hien tai la: ";
			xuat();
			break;
		case 3:
			int x;
			cout << "Nhap gia tri can them dau:";
			cin >>x;
			themDau(x);
			cout << "Them thanh cong ";
			break;
		case 4:
			cout << "Nhap gia tri can them cuoi:";
			cin >>x;
			themCuoi(x);
			cout << "Them thanh cong ";
			break;
		case 5:
			xoaDau();
			cout << "Danh sach sau khi xoa dau: ";
			xuat();
			break;
		case 6:
			xoaCuoi();
			cout << "Danh sach sau khi xoa cuoi: ";
			xuat();
			break;
		case 7:
			int y;
			cout << "Nhap phan tu can xoa: ";
			cin >> y;
			if(Search(y)==NULL)
				cout << "Khong co phan tu can tim.";
			else
			{
				xoa(y);
				cout << "Xoa thanh cong. Danh sach hien tai la: ";
				xuat();
			}
			break;

		}
		cout << "Ban co muon tiep tuc? (Y/N)";
		cin >> tt;
	}while(tt=='y' || tt=='Y');
	system("pause");
	return  0;
}
