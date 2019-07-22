//Chuong 2 bai 02
#include <iostream>
using namespace std;
const int MAX = 100;
int a[MAX];
void nhap(int a[], int &n)
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i + 1 << "]: ";
		cin >> a[i];
	}
}
void them(int a[], int &n)
{
	int x;
	cout << "Nhap so can chen: ";
	cin >> x;
	for(int i = 0; i < n; i ++)
	{
		if(a[i] <= x && a[i + 1] >= x)
		{
			for(int j = n; j > i + 1; j--)
			{
				a[j] = a[j - 1];
			}
			a[i + 1] = x;
			break;				
		}
				
	}
	n++;
}
void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << a[i] << "\t";
		
	}
	cout << endl;
}
// Tim kiem tuan tu
int timy(int a[], int n)
{
	int y;
	cout << "Nhap so can tim: ";
	cin >> y;
	for(int i = 0; i < n; i++)
	{
		if(a[i] == y)
			return 1;
	}
	return 0;
}
// Tim kiem nhi phan
int timx(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid;		
	while (left <= right) {
		mid = (left + right) / 2;
		if (x == a[mid])
		{ 
			return 1;
			break;
		}
		else if (x < a[mid]) 
			right = mid - 1;
		else if (x > a[mid]) 
			left = mid + 1;
		}
	return 0;
}
void xoa(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
	{
		if(a[i] == x)
		{
			for(int j = i; j < n; j++)
				a[j] = a[j + 1];
		}
	}
	n--;
}
int main()
{
	int n;
	int x;
	int z;
	nhap(a, n);
	xuat(a, n);
	them(a, n);
	xuat(a, n);	
	if(timy(a, n) == 1) 
		cout << "Co ton tai " << endl;
	else
		cout << "Khong ton tai" << endl;
	cout << "Nhap so can tim trong danh sach: ";
	cin >> x;
	if(timx(a, n, x) == 1) 
		cout << "Co ton tai " << endl;
	else
		cout << "Khong ton tai" << endl;
	cout << "Nhap so can xoa ";
	cin >> z;
	if(timx(a, n, z) == 1)
		xoa(a, n, z);
	xuat(a, n);
}
















