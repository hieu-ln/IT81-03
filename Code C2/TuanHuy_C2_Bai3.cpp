#include <iostream>
#include <stdio.h>
using namespace std;
struct node {
	int info;
	node *link;
};
//khoi tao danh sach rong
node *first ;

void init()
{
	first = NULL;
}

//xuat
void process_list()
{
	node *p;
	p = first ;
	while(p != NULL)
	{
		cout << p->info << "\t ";
		p = p ->link;
	}
	cout << endl;
}
//tim mot phan tu trong danh sach
node *search( int x )
{
	node *p = first;
	while ( p != NULL && p->info != x )
	{
		p = p->link;
	}
	return p;
}

//them dau
void Insert_first(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = first;
	first = p;
}

//xoa dau
int delete_first()
{
	if (first != NULL) // danh sách khác rỗng
	{
		node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

//xoa cuoi
int delete_last()
{
	if (first != NULL)
		{
		node *p, * q;
		p = first; 
		q = NULL;
			while (p->link !=NULL)
			{
				q=p; 
				p=p->link;
			}
			if (p!=first) // p là đầu thì không tồn tại q;		
				q->link = NULL;
			else 
				first = NULL;
				delete p;
			return 1;
		}
	return 0;
}


//them cuoi
void insert_last(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if (first == NULL) //không có phần tử cuối cùng
		first = p;
else
{
	node *q = first;
	while (q-> link!= NULL)
	q = q->link;
	q->link = p;
}
}
//tim va xoa phan tu i
int searchAndDelete ( int x )
{
	if ( first !=NULL)
	{
		node *p , *q ; 
		p = first;
		q = first;
		while( p->info != x && p->link != NULL )
		{
			q=p;
			p=p->link;
		}
		if(p!= first &&p->link !=NULL )
			//phan tu giua danh sach
		{
			if ( p->link != NULL )
				q->link = p ->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if (p->link == NULL && p->info == x )
				//phan tu cuoi danh sach
			{
				q->link = NULL;
				delete p;
				return 1;
			}
			else
				return 0;
	}
}

void swap(node *a , node *b )
{
	int t= a->info;
	a->info= b -> info;
	b ->info = t;
}

void sort()
{
	node *q ,*p,*min;
	p = first;
	q=p->link;
	while ( p != NULL )
	{
		min = p;
		q = p ->link;
	
		while (p!= NULL )
		{
			if ( q->info < min ->info )
				min = q;
			q= q->link;
		}
		swap ( min,p );
		p = p->link;
	}
}
//sap xep giam dan
void sortDesc()
{
	node *q ,*p,*min;
	p = first;
	while (p!= NULL )
	{
		min= p;
		q=p->link;
		while (p!= NULL )
		{
			if ( q->info > min ->info )
				min = q;
			q= q->link;
		}
		swap ( min,p );
		p = p->link;	
	}
}

int main()
{
	int choice= 0 ;
	int x,i;
	node *p;
	system("cls");
	cout<<"-----BAI TAP 3, CHUONG 2 , DANH SACH LK DON --------\n";
	cout<<"1.khoi tao ds lk don rong" << endl;
	cout<<"2.them phan tu vao dau danh sach" << endl;
	cout<<"3.xoa phan tu dau danh sach "<< endl;
	cout<<"4.them phan tu vao cuoi danh sach " << endl;
	cout<<"5.xoa phan tu cuoi danh sach" << endl;
	cout<<"6.xuat danh sach " << endl;
	cout <<"7.tim phan tu voi gia tri x trong danh sach lk " << endl;
	cout<<"8.sap xep tang dan " << endl;
	cout<<"9.sap xep giam dan " << endl;
	cout <<"10.thoat " << endl;
	do
	{
		cout<<"vui long chon so de thuc hien ";
		cin >> choice;
		switch(choice)
		{
			case 1:			
				init();
				cout<<"ban vua khoi tao danh sach lk don thanh cong " << endl;
				break;			
			case 2:			
				cout<<"vui long nhap gia tri x=: \n " << endl;
				cin>>x;
				Insert_first(x);
				cout << " danh sach sau khi them ";
				process_list();
				break;			
			case 3:
				cout<<" vui long nhap x can tim ";
				cin >> x;
				insert_last(x);
				if ( i == - 1 )
				cout << " danh sach sau khi them ";
				process_list();
				break;
			case 4:
				i=delete_first();
				if ( i == 0 )
					cout << " danh sach rong khong the xoa" << endl;
				else
					cout << " xoa thanh cong ";
					cout << " danh sach sau khi xoa";
					process_list();
				break;
			case 5:
				i=delete_last();
				if ( i = 0 )
				cout << " danh sach rong khong the xoa" << endl;
				else
					cout << " xoa thanh cong ";
					cout << " danh sach sau khi xoa";
					process_list();
				break;
			case 6:
				cout << "danh sach hien tai ";
				process_list();
				break;
			case 7:
				cout << " vui long nhap gia tri can tim x= ";
				cin >> x;
				p=search(x);
				if(p!= NULL )
				{
					cout << " thim thay phan tu co gia tri  " << x << endl;
				}
				else
					cout<<"khong tim thay phan tu co gia tri" << x << endl;

				break;
			case 8:
				cout << " vui long nhap gia tri can tim x= ";
				cin >> x;
				i=searchAndDelete(x);
				if ( i=1 )
				{
					cout << " tim tahy x va xoa thanh cong ";
					cout << " danh sach sau khi xoa ";
					process_list();
				}
				else
					cout << " khong tim thay phan tu co gia tri x= " << x << endl;
				break;
			case 9:
				sort();
				cout <<"danh sach sau khi sap xep tang dan ";
				process_list();
				break;
			case 10:
				sortDesc();
				cout<<" danh sach sau khi sap xep giam dan ";
				process_list();
				break;
			case 11:
				cout << " chao tam biet ";
				break;
			default:
				break;
			}
		} while( choice != 11);
		system ("pause");
		return 0;
	}