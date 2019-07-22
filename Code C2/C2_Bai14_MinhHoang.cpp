#include <iostream>
#include <string>
using namespace std;


//khai bao cau truc
struct node
{
	int c;
	int power;
	node* prev, * next;
};
node* first, * last;


//khoi tao danh sach lk kep
void init()
{
	first = NULL;
	last = NULL;
}


//Them ptu vao danh sach
int insert(node* p)
{
	if (first == NULL)
	{
		first = p;
		last = p;
		return 1;
	}
	else
	{
		node* q = first;;
		while (q != NULL)
		{
			if (q->power == p->power)
			{
				q->c = p->c;
				break;
			}
			q = q->next;
		}
		if (q != NULL)
			q->c = p->c;
		else
		{
			node* l = last;
			l->next = p;
			p->prev = l;
			p->next = NULL;
			last = p;
			return 1;
		}
	}
	return 0;
}
void output()
{
	string s;
	if (first == NULL)
	{
		cout << "Da thuc rong" << endl;
		return;
	}


	cout << "Da thuc la P(x) = ";
	node* p = first;
	while (p != NULL)
	{
		if (p->power == 0)
			s = "";
		else
			if (p->power == 1)
				s = "x";
			else
			{
				if (p->c > 0)
					cout << " + " << p->c << "x^(" << p->power << ")";
				else
					cout << " - " << 0 - p->c << "x^(" << p->power << ")";
				return;
			}
		if (p->c > 0)
			cout << " + " << p->c << s;
		else
			cout << " - " << 0 - p->c << s;
		p = p->next;
	}

}
void menu()
{
	cout << "-----DA THUC - DSLK KEP------" << endl;
	cout << "1. Tao danh sach rong" << endl;
	cout << "2. Them vao da thuc" << endl;
	cout << "3. thoat" << endl;
}
void main()
{
	int choice, c, pow;




	menu();
	do {
		cout << "Chon 1 so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Tao danh sach rong thanh cong" << endl;
			break;
		case 2:
			cout << "Nhap co so: ";
			cin >> c;
			cout << "Nhap so mu: ";
			cin >> pow;
			node* p = new node;
			p->c = c;
			p->power = pow;
			p->next = NULL;
			p->prev = NULL;
			insert(p);
			output();
			cout << endl;
			delete p;
			break;
		}
	} while (choice != 3);
}
