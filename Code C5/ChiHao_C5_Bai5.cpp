#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 20

//DSLK su dung cho STACK va DANH SACH KE
struct Node {
	int info;
	Node *link;
};

Node *First[MAX]; //DS cac LK
int n; //so dinh cua do thi
char vertex[MAX]; //ten dinh

Node *sp;
Node *front, *rear;

//STACK
void initStack()
{
	sp = NULL;
}

int isEmptyS()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if (sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}
//end STACK

//Queue
void initQueue()
{
	front = NULL;
	rear = NULL;
}

int isEmpty()
{
	if (front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
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

int PopQ(int &x)
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
//end Queue

void initGraph(int &n)
{
	for (int i = 0; i < n; i++)
		First[i] = NULL;
	n = 0;
}

void insert_last(Node *&first, Node *p)
{
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while (getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while (ss >> u)
			{
				//Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insert_last(First[i - 1], p);
			}
			i++;
		}
	}
}

void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n + 1; i++)
	{
		if (i > 0)
			cout << "Nhap DSK cua dih thu " << i - 1 << " (" << vertex[i - 1] << ") : ";
		int u;
		string str;
		while (getline(cin, str))
		{
			istringstream ss(str);
			while (ss >> u)
			{
				//Dinh u
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				insert_last(First[i - 1], p);
			}
			break;
		}
	}
}

//Xuat ma tran cua do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << ") : ";
		Node *p = First[i];
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->link;
		}
		cout << endl;
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << vertex[a[i]] << "\t";
}

//Duyet do thi theo chieu rong BFS (Dung QUEUE va DSLK Don)
int C[100], bfs[100];
int nbfs = 0;
void initC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int v)
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while (w != NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//Duyet do thi theo chieu sau DFS (Dung STACK va DSLK Don)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int u = s;
	Node *v = NULL;
	while (isEmptyS() == 0)
	{
		if (v == NULL)
			PopS(u);
		v = First[u];
		while (v != NULL)
		{
			if (C[v->info] == 1)
			{
				PushS(u);
				PushS(v->info);
				dfs[ndfs] = v->info;
				ndfs++;
				C[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

//Dung BFS tim x tren do thi
void search_by_BFS(int x, int v)
{
	int p;
	Node *w;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		if (x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		w = First[p];
		while (w != NULL)
		{
			if (C[w->info])
			{
				PushQ(w->info);
				C[w->info] = 0;
			}
			w = w->link;
		}
	}
}

int main()
{
	int choice, x;
	system("cls");
	cout << "---------	BAI TAP 5, CHUONG 5, DO THI	---------\n";
	cout << "1. Khoi tao DANH SACH KE rong\n";
	cout << "2. Nhap DANH SACH KE tu file text\n";
	cout << "3. Nhap DANH SACH KE\n";
	cout << "4. Xuat DANH SACH KE\n";
	cout << "5. Duyet do thi theo chieu rong BFS - DSLK\n";
	cout << "6. Duyet do thi theo chieu sau DFS - DSLK\n";
	cout << "7. Tim dinh co gia tri x theo BFS\n";
	cout << "8. Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			n = 10;
			initGraph(n);
			cout << "Ban vau khoi tao DANH SACH KE rong thanh cong\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap DANH SACH KE tu file : \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			initQueue();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau khi duyet BFS:\n";
			output(bfs, n);
			break;
		case 6:
			initStack();
			initC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS:\n";
			output(dfs, n);
			break;
		case 7:
			initQueue();
			initC();
			nbfs = 0;
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			search_by_BFS(x, 0);
			break;
		case 8:
			cout << "Goodbye...!\n";
			break;
		default:
			break;
		}
	} while (choice != 8);
	return 0;
}