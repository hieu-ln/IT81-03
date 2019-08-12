#include <iostream>
#include <fstream>
using namespace std;

//Khai bao cau truc ma tran ke
#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

//DSLK su dung cho STACK va QUEUE
struct Node
{
	int info;
	Node *link;
};

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

void initGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}

//Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "Nhap so dinh co thi n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}

//Xuat ma tran cua do thi
void outputGraph()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
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
	int w, p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

//Duyet do thi theo chieu sau DFS (Dung STACK va DSLK Don)
int dfs[100];;
int ndfs = 0;
void DFS (int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v= -1, u = s;
	while (isEmptyS() == 0)
	{
		if (v == n)
			PopS(u);
		for (v = 0; v < n; v++)
			if (A[u][v] != 0 && C[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
	}
}

//Dung BFS tim x tren do thi
void search_by_BFS(int x, int v)
{
	int w, p;
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
		for (w = 0; w < n; w++)
			if (C[w] && A[p][w] == 1)
			{
				PushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int choice, x;
	system("cls");
	cout << "---------	BAI TAP 4, CHUONG 5, DO THI	---------\n";
	cout << "1. Khoi tao MA TREN KE rong\n";
	cout << "2. Nhap MA TRAN KE tu file text\n";
	cout << "3. Nhap MA TRAN KE\n";
	cout << "4. Xuat MA TRAN KE\n";
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
			initGraph();
			cout << "Ban vau khoi tao MA TRAN KE rong thanh cong\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file : \n";
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