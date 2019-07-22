//Bai 6, chuong 2: Dung stack doi so he thap phan sang nhi phan
#include <iostream>
using namespace std;

#define MAX 100
//Cau 5.2: Khoi tao stack rong
void init(int a[], int& sp)
{
	sp = -1;
}
//Cau 5.5: Them phan tu va ngan xep
int push(int a[], int& sp, int x)
{
	if (sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
//Cau 5.6: Xoa 1 phan tu
int pop(int a[], int& sp, int& x)
{
	if (sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
//Xuat stack nguoc
void process_Stack(int a[], int sp)
{
	for (int i = sp; i >= 0; i--)
	{
		cout << a[i];
	}
	cout << endl;
}

int main()
{
	int a[MAX];
	int sp, n;
	init(a, sp);
	cout << "CHUONG TRINH DOI 1 SO TU HE THAP PHAN SANG HE NHI PHAN\n";
	do {
		cout << "Nhap so thap phan can chuyen: ";
		cin >> n;
		if (n < 0)
			cout << "Nhap 1 so lon hon hoac bang 0\n";
	} while (n < 0);
	if (n == 0)
		cout << "So nhi phan la: 0";
	else
	{
		while (n != 0)
		{
			int m = n % 2;
			push(a, sp, m);
			n = n / 2;
		}
		cout << "So nhi phan la: ";
		process_Stack(a, sp);
	}
		return 0;
}