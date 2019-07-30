#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#define MAX 100
int a[MAX];
int n;
void input (int a[], int &n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap cac phan tu cua danh sach: " << endl;
	for (int i=0; i < n; i++) {
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void InsertionSort(int a[], int n)
{
	int x, i, j;
	for(int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[i + j] = a[j];
			j--;
		}
		a[i + j] = x;
	}
}
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for(i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if(a[j] < a[min_pos])
				min_pos=j;
		swap(a[min_pos], a[i]);
	}
}
void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j=i+1; j < n; j++)
			if(a[i]>a[j])
				swap(a[i], a[j]);
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if(a[j - 1] > a[j])
				swap(a[j], a[j-1]);
}
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i << j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if(i <= j) {
			swap(a[i], a[j]);
				i++; j--;
		}
	}
	if(left < j) QuickSort(a, left, j);
	if(i < right)
		QuickSort(a, i, right);
}
void Shift(int a[], int i, int n)
{
	int j=2*i + 1;
	if(i>=n)
		return;
	if(j + 1 < n)
		if (a[j] < a[j+1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift(a, j, n);
	}
}

void HeapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		Shift(a, i, n - 1);
		i--;
	}
	int right= n - 1;
	while(right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if(right > 0)
			Shift(a, 0, right);
	}
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i]!=x)
		i++;
	 if(i < n)
		 return i;
	 return -1;
}
int BinarySearch(int a[], int n, int x)
{
	int left = 0, right= n - 1, mid;
	while(left <= right)
	{
		mid = (left + right)/2;
		if(a[mid] == x) return mid;
		if(x>a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}

int main()
{
	int b[MAX];
	int ch, x, i;
	system("cls");
	cout << "-------- MENU --------\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Insertion Sort\n";
	cout << "4. Selection Sort\n";
	cout << "5. Interchange Sort\n";
	cout << "6. Bubble Sort\n";
	cout << "7. Quick Sort\n";
	cout << "8. Heap Sort\n";
	cout << "9. Tim kiem tuan tu\n";
	cout << "10. Tim kiem nhi phan\n";
	cout << "11. Thoat\n";
	do {
		cout << "Chon so de thuc hien: ";
		cin >> ch;
		switch(ch)
		{
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach hien tai: " << endl;
			output(a, n);
			break;
		case 3:
			CopyArray(a, b, n);
			SelectionSort(b, n);
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep:\n";
				output(b, n);
			}
			break;
		case 4:
			CopyArray(a, b, n);
			InsertionSort(b, n);
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep:\n";
				output(b, n);
			}
			break;
		case 5:
			CopyArray(a, b, n);
			BubbleSort(b, n);
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep:\n";
				output(b, n);
			}
			break;
		case 6:
			CopyArray(a, b, n);
			InterchangeSort(b, n);
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep:\n";
				output(b, n);
			}
			break;
		case 7: 
			CopyArray(a, b, n);
			QuickSort(b, 0, n);
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep:\n";
				output(b, n);
			}
			break;
		case 8:
			CopyArray(a, b, n);
			HeapSort(b, n);
			if(n < 100)
			{
				cout << "Danh sach sau khi sap xep:\n";
				output(b, n);
			}
			break;
		case 9:
			cout << "Nhap x = ";
			cin >> x;
			Search(a, n, x);
			break;
		case 10: 
			cout << "Nhap x = ";
			cin >> x;
		BinarySearch(a, n, x);
			break;
		case 11: 
			cout << "Chuong trinh ket thuc...\n";
			break;
		default:
			break;
		}
	} while(ch!=11);
	system("pause");
	return 0;
}