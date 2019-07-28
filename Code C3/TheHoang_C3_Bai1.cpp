#include <iostream>
#include <ctime>
#include <stdio.h>
using namespace std;

#define MAX 5000
int a[MAX];
int n;

void init(int a[], int& n)
{
	cout << "Nhap so luong phan tu cua danh sach: ";
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da duoc tao ngau nhien nhu sau:\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
void input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}
void coppyArray(int a[], int b[], int n)
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}
void insertionSort(int a[], int n)
{
	int x, i, j;
	for (i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void selectionSort(int a[], int n)
{
	int min_pos, i, j;
	for (i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
}
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}
void quickSort(int a[], int l, int r)
{
	int x = a[(l + r) / 2];
	int i = l;
	int j = r;
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
	if (l < j)
		quickSort(a, l, j);
	if (i < r)
		quickSort(a, i, r);
}
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
		shift(a, j, n);
	}
}
void heapSort(int a[], int n)
{
	int i = n / 2;
	while (i >= 0)
	{
		shift(a, i, n);
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
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i < n)
		return  i;
	return -1;
}
int binarySearch(int a[], int n, int x)
{
	int l, r, mid;
	l = 0, r = n - 1;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (a[mid] == x)
			return mid;
		if (x > a[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

int main()
{
	int choice, x, i;
	int b[MAX];
	clock_t start;
	double duration;
	cout << "<-------- BAI TAP 1, CHUONG 3 -------->\n";
	cout << "1. Khoi tao danh sach ngau nhien\n";
	cout << "2. Nhap danh sach\n";
	cout << "3. Xuat danh sach\n";
	cout << "4. Selection Sort\n";
	cout << "5. Insertion Sort\n";
	cout << "6. Bublle Sort\n";
	cout << "7. Interchange Sort\n";
	cout << "8. Quick Sort\n";
	cout << "9. Heap Sort\n";
	cout << "10. Tim kiem tuan tu\n";
	cout << "11. Tim kiem nhi phan\n";
	cout << "12. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(a, n);
			break;
		case 2:
			cout << "Nhap gia so phan tu can dung: ";
			cin >> n;
			input(a, n);
			break;
		case 3:
			output(a, n);
			break;
		case 4:
			coppyArray(a, b, n);
			start = clock();
			selectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach sau khi sap xep voi Selection Sort la:\n";
			output(b, n);
			if (duration > 0)
				cout << "Thoi gian Selection Sort: " << duration * 1000000 << " microsecond\n";
			break;
		case 5:
			coppyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach sau khi sap xep voi Insertion Sort la:\n";
			output(b, n);
			if (duration > 0)
				cout << "Thoi gian Insertion Sort: " << duration * 1000000 << " microsecond\n";
			break;
		case 6:
			coppyArray(a, b, n);
			start = clock();
			bubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach sau khi sap xep voi Bubble Sort la:\n";
			output(b, n);
			if (duration > 0)
				cout << "Thoi gian Bubble Sort: " << duration * 1000000 << " microsecond\n";
			break;
		case 7:
			coppyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach sau khi sap xep voi Interchange Sort la:\n";
			output(b, n);
			if (duration > 0)
				cout << "Thoi gian Interchange Sort: " << duration * 1000000 << " microsecond\n";
			break;
		case 8:
			coppyArray(a, b, n);
			start = clock();
			quickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach sau khi sap xep voi Quick Sort la:\n";
			output(b, n);
			if (duration > 0)
				cout << "Thoi gian Quick Sort: " << duration * 1000000 << " microsecond\n";
			break;
		case 9:
			coppyArray(a, b, n);
			start = clock();
			heapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << "Danh sach sau khi sap xep voi Heap Sort la:\n";
			output(b, n);
			if (duration > 0)
				cout << "Thoi gian Heap Sort: " << duration * 1000000 << " microsecond\n";
			break;
		case 10:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = search(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << x << " khong ton tai trong danh sach\n";
			else
				cout << x << " o vi tri a[" << i << "] trong danh sach\n";
			if (duration > 0)
				cout << "\nThoi gian tim kiem tuan tu: " << duration * 1000000 << " microsecond\n";
			break;
		case 11:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			start = clock();
			i = binarySearch(b, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << x << " khong ton tai trong danh sach\n";
			else
				cout << x << " o vi tri a[" << i << "] trong danh sach\n";
			if (duration > 0)
				cout << "Thoi gian tim kiem nhi phan: " << duration * 1000000 << " microsecond\n";
			break;
		case 12:
			cout << "Tam biet\n";
		default:
			break;
		}
	} while (choice != 12);
	return 0;
	}