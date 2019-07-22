//Chuong2. bai15
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX = 100;
int a[MAX], b[MAX];
void khoitao(int a[], int &n)
{
	for(int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}	
}
void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
	}
	cout << endl;
}
void xuatgiao(int a[], int b[], int na, int nb)
{
	for(int i = 0; i < na; i++)
	{
		for(int j = 0; j < nb; j++)
		{
			int value;
			if(a[i] != value && a[i] == b[j])
			{
				cout << a[i] << "\t";					
				value = a[i];
			}
		}
	}
}
void xuatbua(int a[], int b[], int na, int nb)
{
	for(int i = 0; i < na; i++)
	{
		int value;
		int j = 0;
		int dem = 0;
		while(j < nb)
		{
			if(a[i] != b[j])
				dem++;
			j++;						
		}
		if(a[i] != value && dem == j)
		{
			cout << a[i] << "\t";
			value = a[i];
		}
	}
}
void xuatbub(int a[], int b[], int na, int nb)
{
	for(int j = 0; j < nb; j++)
	{
		int value;
		int i = 0;
		int dem = 0;
		while(i < na)
		{
			if(b[j] != a[i])
				dem++;
			i++;						
		}
		if(b[j] != value && dem == i)
		{
			cout << b[j] << "\t";
			value = b[j];
		}
	}
}
int main()
{
	int na, nb, nc;
	cout << "Nhap so phan tu cua mang thu nhat: ";
	cin >> na;
	khoitao(a, na);
	cout << "Nhap so phan tu cua mang thu hai: ";
	cin >> nb;
	khoitao(b, nb);
	xuat(a, na);
	xuat(b, nb);
	cout << "Mang giao nhau cua hai mang vua nhap la: \n";
	xuatgiao(a, b, na, nb);
	cout << endl;
	cout << "Mang bu cua a: \n";
	xuatbua(a,b,na,nb);
	cout << endl;
	cout << "Mang bu cua b: \n";
	xuatbub(a,b,na,nb);
}
