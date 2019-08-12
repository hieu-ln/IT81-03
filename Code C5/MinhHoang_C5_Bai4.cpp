#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];
int n;
char vertex[MAX];

//DSLK su dung cho  stack va queue
struct node
{
	int info;
	node *link;
};
node *sp;
node *front, *rear;
//QUEUE
void initQueue()
{
	front = NULL;
	rear = NULL;
}
int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}
void pushQ(int x)
{
	node *p = new node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int popQ(int &x)
{
	if(front != NULL)
	{
		node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
		{
			rear = NULL;
		}
		delete p;
		return 1;
	}
	return 0;
}
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
void pushS(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = sp;
	sp = p;
}
int popS(int &x)
{
	if(sp!= NULL)
	{
		node *p = sp;
		x = p -> info;
		sp= p ->link;
		delete p;
		return x;
	}
	return 0;
}

void initGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("matranke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i < n; i++)
			myfile >> vertex[i];
		for(int i = 0; i < n; i++)
		{
			for(int j =0; j < n; j++)
				myfile >> A[i][j];
		}
	}
}
//Cau 4.1: Ham nhap ma tran ke
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap vao dong thu " << i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
	}
}
//Cau 4.2: Xuat ma tran
void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[i] << " ";
}
//Cau 4.3: Duyet do thi theo chieu rong
int C[100];
int bfs[100];
int nbfs = 0;
void initC()
{
	for(int i = 0; i < n; i++)
		C[i] = 1;
}
void BFS(int v)
{
	int w, p;
	pushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
			if(C[v] && A[p][w] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}
//Cau 4.4: Duyet do thi theo chieu sau
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	pushS(s);
	dfs[ndfs] = s;
	ndfs++;
	C[s] = 0;
	int v = 1, u = s;
	while(isEmptyS() == 0)
	{
		if(v == n)
			popS(u);
		for(v = 0; v < n; v++)
			if(A[u][v] != 0 && C[v] == 1)
		{
			pushS(u);
			pushS(v);
			dfs[ndfs] = v;
			ndfs++;
			C[v] = 0;
			u = v;
			break;
		}
	}
}
//Cau 4.5: Dung DFS tim x tren do thi
void search_By_Bfs(int x, int v)
{
	int w, p;
	pushQ(v);
	C[v] = 0;
	while(front != NULL)
	{
		popQ(p);
		if(x == p)
		{
			cout << "Tim thay " << x << endl;
			return;
		}
		for(w = 0; w < n; w++)
			if(C[w] && A[p][w] == 1)
			{
				pushQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int choice, x;
	system("cls");
	cout << "-------- Bai tap 4, chuong 5, do thi --------\n";
	cout << "1. Khoi tao ma tran ke rong\n";
	cout << "2. Nhap ma tran ke tu file text\n";
	cout << "3. Nhap ma tran ke\n";
	cout << "4. Xuat ma tran ke\n";
	cout << "5. Duyet do thi theo chieu rong (BFS)\n";
	cout << "6. Duyet do thi theo chieu sau (DFS)\n";
	cout << "7. Tim dinh co gia tri x theo BFS\n";
	cout << "8. Thoat\n";
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout << "Khoi tao danh sach rong thanh cong\n";
			break;
		case 2:
			inputGraphFromText();
			cout << "Nhap ma tran ke tu file text thanh cong:\n";
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
			cout << "thu tu sau khi duyet BFS:\n";
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
			cout << "Vui long nhap gia tri can tim: ";
			cin >> x;
			initQueue();
			initC();
			nbfs = 0;
			search_By_Bfs(x, 0);
			break;
		case 8:
			cout << "Tam biet\n";
			break;
		default:
			break;
		}
	}while(choice != 8);
	return 0;
}