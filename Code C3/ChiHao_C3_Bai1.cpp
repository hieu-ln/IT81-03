#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

//khai bao cau truc danh sach
#define MAX 2000
int a[MAX];
int n;


//Nhap danh sach tu dong, ngau nhien
void init(int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da duoc nhap ngau nhien nhu sau:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//Nhap danh sach
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//Xuat danh sach
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//Ham hoan doi 2 so nguyen
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void CopyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}

//sap xep danh sach theo thu tu tang dan bang thuat toan InsertionSort
void insertionSort(int a[], int n)
{
	int x, j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > x)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

//Sap xep danh sach theo thu tu tang dan bang thuat toan SelectionSort
void selectionSort(int a[], int n)
{
	int  min_idx;
	for (int i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}

//Sap xep danh sach theo thu tu tang dan bang thuat toan InterchangeSort
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}

//Sap xep danh sach theo thu tu tang dan bang thuat toan BubbleSort
void bubbleSort(int a[], int n)
{
	bool haveSwap = false;
	for (int i = 0; i < n; i++)
	{
		haveSwap = false;
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		if (haveSwap == false)
			break;
	}
}

//Sap xep danh sach theo thu tu tang dan bang thuat toan QuickSort
void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left, j = right;
	while (i < j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (j > left)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

//Sap xep danh sach theo thu tu tang dan bang thuat toan HeapSort
void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j , n);
	}
}

void HeapSort(int a[], int n)
{
	int i = n / 2 - 1;
	while (i >= 0)
	{
		shift(a, i , n);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if (right > 0)
			shift(a, 0, right);
	}
}

//Tim kim kiem phan tu trong danh sach co thu tu (pp tim kiem tuan tu)
void searchSequence(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		cout << "Khong tim thay\n";
	else
		cout << "Tim thay tai vi tri: " << i << endl;
}

//Tim kim kiem phan tu trong danh sach co thu tu (pp tim kiem nhi phan)
int searchBinary(int a[], int l , int r, int x)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] > x)
			return searchBinary(a, l, mid - 1, x);
		return searchBinary(a, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	int choice, x, i;
	int b[MAX];
	clock_t start;
	double duration;
	system("cls");
	cout << "	---------	BAI TAP 1,  CHUONG 3, XEP THU TU va TIM KIEM	--------\n";
	cout << "0. Khoi tao danh sach ngau nhien\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Xep thu tu danh sach bang SELECTION SORT\n";
	cout << "4. Xep thu tu danh sach bang INSERTION SORT\n";
	cout << "5. Xep thu tu danh sach bang BUBBLE SORT\n";
	cout << "6. Xep thu tu danh sach bang INTERCHANGE SORT\n";
	cout << "7. Xep thu tu danh sach bang QUICK SORT\n";
	cout << "8. Xep thu tu danh sach bang HEAP SORT\n";
	cout << "9. Tim kiem phan tu x bang TIM KIEM TUAN TU\n";
	cout << "10. Tim kiem phan tu x bang TIM KIEM NHI PHAN\n";
	cout << "11. Thoat\n";
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach la:\n";
			output(a, n);
			break;
		case 3:
			CopyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu bang SELECTION SORT la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << " Microseconds\n";
			break;
		case 4:
			CopyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu bang INSERTION SORT la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << " Microseconds\n";
			break;
		case 5:
			CopyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu bang BUBBLE SORT la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << " Microseconds\n";
			break;
		case 6:
			CopyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu bang INTERCHANGE SORT la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << " Microseconds\n";
			break;
		case 7:
			CopyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu bang QUICK SORT la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QUICK SORT: " << duration * 1000000 << " Microseconds\n";
			break;
		case 8:
			CopyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Danh sach sau khi xep thu tu bang HEAP SORT la:\n";
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HEAP SORT: " << duration * 1000000 << " Microseconds\n";
			break;
		case 9:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			searchSequence(a, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "\nThoi gian tim kirm TUAN TU la: " << duration * 1000000 << " Microseconds\n";
			break;
		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchBinary(b, 0, n, x);
			duration = (clock() - start) / (double) CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x = " << x << " trong day!\n";
			else
				cout << "Tim thay x = " << x << " tai vi tri i = " << i << endl;
			if (duration > 0)
				cout << "\nThoi gian tim kirm NHI PHAN la: " << duration * 1000000 << " Microseconds\n";
			break;
		case 11:
			cout << "Goodbye!\n";
			break;
		default:
			break;
		}
	} while (choice != 11);
	return 0;
}