//Bai 3, chuong 2: Danh sach lien ket don
#include <iostream>
using namespace std;

//Cau 3.1: Khai bao cau truc danh sach
struct Node
{
	int info;
	Node* link;
};
Node* first;
//Cau 3.2: Khoi tao danh sach rong
void init()
{
	first = NULL;
}
//Cau 3.3: Xuat cac phan tu trong danh sach
void process_List()
{
	Node* p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}
//Cau 3.4: Tim 1 phan tu trong danh sach
Node* search(int x)
{
	Node* p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}
//Cau 3.5: Them phan tu vao dau danh sach
void insert_First(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}
//Cau 3.6: Xoa phan tu dau danh sach
int delete_First()
{
	if (first != NULL)
	{
		Node* p = first;
		first = first->link;
		delete p;
			return 1;
	}
	return 0;
}
//Cau 3.7: Them phan tu cuoi danh sach
void insert_Last(int x)
{
	Node* p;
	p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node* q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}
//Cau 3.8: Xoa phan tu cuoi danh sach
int delete_Last()
{
	if (first != NULL)
	{
		Node* p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//Cau 3.9: Tim kiem va xoa
int searchAndDelete(int x)
{
	if (first != NULL)
	{
		Node* p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else
			if (p == first)
			{
				first = p->link;
				delete p;
				return 1;
			}
			else
				return 0;
	}
	return 0;
}
//Ham doi gia tri cua 2 phan tu
void swap(Node* a, Node* b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}
//Cau 3.10: Sap xep tang dan
void sort()
{
	Node* p, * q, * min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}
//Cau 3.10: Sap xep giam dan
void sortDesc()
{
	Node* p, * q, * min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info > min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int choice;
	int x, i;
	Node* p;
	system("cls");
	cout << "-------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET --------\n";
	cout << "1. Khoi tao DSLK DON rong\n2. Them phan tu vao dau DSLK DON\n3. Them phan tu vao cuoi DSLK DON\n4. Xoa phan tu dau DSLK DON\n5. Xao phan tu cuoi DSLK DON\n6. Xuat DSLK DON\n7. Tim mot phan tu gia tri x trong DSLK DON\n8. Tim mot phan tu voi gia tri x va xoa no neu co\n9. Sap xep DSLK DON tang dan\n10. Sap xep DSLK DON giam dan\n11. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao danh sach rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri x = ";
			cin >> x;
			insert_First(x);
			cout << "Danh sach sau khi them la: ";
			process_List();
			break;
		case 3:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			insert_Last(x);
			cout << "Danh sach sau khi them la: ";
			process_List();
			break;
		case 4:
			i = delete_First();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa\n";
			else
			{
				cout << "Da xao thanh cong phan tu dau DSLK DON\n";
				cout << "Danh sach sau khi xoa la: ";
				process_List();
			}
			break;
		case 5:
			i = delete_Last();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa\n";
			else
			{
				cout << "Da xao thanh cong phan tu cuoi DSLK DON\n";
				cout << "Danh sach sau khi xoa la: ";
				process_List();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: ";
			process_List();
			break;
		case 7:
			cout << "Nhap gia tri can tim x = ";
			cin >> x;
			p = search(x);
			if (p != NULL)
				cout << "Tim thay phan tu co gia tri x = " << x << endl;
			else
				cout << "Khong tim thay phan tu co gia ti x = " << x << endl;
			break;
		case 8:
			cout << "Nhap gia tri can tim x = ";
			cin >> x;
			i = searchAndDelete(x);
			if (i == 1)
			{
				cout << "Tim thay x = " << x << " va da xoa thanh cong";
				cout << "Danh sach sau khi xoa la: ";
				process_List();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x = " << x << endl;
			break;
		case 9:
			sort();
			cout << "Danh sach sau khi sap xep tang dan la: ";
			process_List();
			break;
		case 10:
			sortDesc();
			cout << "Danh sach sau khi sap xep giam dan la: ";
			process_List();
			break;
		case 11:
			cout << "Tam biet\n";
			break;
		default:
			break;
		}
	} while (choice != 11);
	return 0;
}