#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//Khai bao ma tran
#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void initGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("matrantrongso1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i =0; i< n; i++)
			myfile >> vertex[i];
		for(int  i =0; i< n; i++)
		{
			for(int j = 0; j< n;j++)
				myfile >> a[i][j];
		}
	}
}

//Nhap ma tran ke
void inputGraph()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i =0; i< n; i++)
		cin >> vertex[i];
	for(int i= 0; i< n;i++)
	{
		cout << "Nhap dong thu" << i+1 << ": ";
		for(int j = 0; j< n; j++)
			cin >> a[i][j];
	}
}

void outputGraph()
{
	cout << setw(6)<<left;
	for(int i = 0; i< n; i++)
	{
		for(int j= 0 ; j< n; j++)
			cout << a[i][j] << setw(6) <<left;
		cout << endl;
	}
}

//khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;

//khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

void swap(int &x, int &y)
{
	int c;
	c =x;
	x=y;
	y=c;

}

int tontai(int d, int D[], int nD)
{
	for(int i= 0; i< n; i++)
		if(D[i] == d)
			return 1;
	return 0;
}

void xoavitri(int i)
{
	for(int j= i; j< nE; j++)
	{
		E1[j] = E1 [j+1];
		E2[j] = E2 [j+1];
		wE[j] = wE [j+1];
	}
	nE--;
}

void xoacanh(int u, int v)
{
	for(int i= 0; i< n; i++)
		if(E1[i] == u && E2[i] == v)
		{
			xoavitri(i);
			break;
		}
}

void taoE()
{
	for(int i = 0; i< n; i++)
		for(int j = 0 ; j<n;j++)
			if(a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE]  =a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

void sapxepE()
{
	for(int i = 0; i< nE-1; i++)
		for(int j= i+1;j < nE-1; j++)
			if(wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E2[j]);
				swap(E2[i], E2[j]);
			}
}

void Kruskla()
{
	for(int i= 0; i<n;i++)
	{
		if(tontai(E1[i], T1,nT) == 1 && tontai(E2[i],T2,nT) == 1)
			continue;
		if(tontai(E1[i], T2, nT) == 1 && tontai(E2[i],T1,nT)==1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT==n-1)
			break;
	}
}

void output(bool VertextName)
{
	int tong = 0;
	for(int i = 0; i<n ; i++)
	{
		if(VertextName)
			cout <<endl <<"( "<<vertex[T1[i]] << ", "<<vertex[T2[i]] << ") "<<wT[i];
		else
			cout <<endl <<"( "<<T1[i]<<","<<T2[i]<<") "<<wT[i];
		tong+=wT[i];
	}
	cout <<"\n Tong=" <<tong<<endl;
}

int main()
{
	int choice, x, i;
	cout << "1.Khoi tao ma tran rong" <<endl;
	cout << "2.Nhap ma tran ke tu file" <<endl;
	cout << "3.Nhap ma tran ke " <<endl;
	cout << "4.Xuat ma tran ke "<<endl;
	cout << "5.Tim cay khung toi thieu" <<endl;
	cout << "6.Thoat "<<endl;
	do{
		cout << "Vui long chon so de thuc thi chuong trinh : "<<endl;
		cin >> choice;
		switch(choice)
		{
		case 1:
			initGraph();
			cout << "Khoi tao ma tran rong thanh cong " <<endl;
			break;
		case 2:
			inputGraphFromText();
			cout <<"Ban vua nhap ma tran ke thanh cong " <<endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			taoE();
			Kruskla();
			cout << "Cay khung toi thieu " <<endl;
			output(true);
			break;
		case 6:
			cout << "Goodbye !!! "<<endl;
			break;
		}
	}while(choice != 6);
	return 0;
}