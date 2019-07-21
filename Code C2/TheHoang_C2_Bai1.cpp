#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;
void input(int a[], int &n)
{
	do {
		cout << "Nhap so luong phan tu: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap so luong phan tu tu 1 den " << MAX << endl;
	} while (n <= 0 || n > MAX);
	cout << "Nhap danh sach phan tu:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
	cout << endl;
}
int search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}
int insert_last(int a[], int &n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}
int delete_last(int a[], int &n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
int Delete(int a[], int &n, int i)
{
	if (i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}
int search_delete(int a[], int &n, int x)
{
	for (int i =  0; i < n; i++)
	{
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout << "---------	BAI TAP 1, CHUONG 1, DANH SACH DAC	----------\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Tim mot phan tu vao cuoi danh sach\n";
	cout << "4. Them mot phan tu vao cuoi danh sach\n";
	cout << "5. Xoa phan tu cuoi danh sach\n";
	cout << "6. Xoa phan tu tai vi tri i\n";
	cout << "7. Tim mot phan tu trong danh sach va xoa neu co\n";
	cout << "8. Thoat\n";
	do {
		cout << " Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				input(a, n);
				cout << "Danh sach vua nhap thanh cong\n";
				break;
			}
		case 2:
			{
				cout << "Danh sach vua nhap la: ";
				output(a, n);
				break;
			}
		case 3:
			{
				cout << "Vui long nhap x can tim: ";
				cin >> x;
				i = search(a, n, x);
				if (i == -1)
					cout << "Tim khong thay phan tu co gia tri: " << x << endl;
				else
					cout << "Tim thay tai vi tri i = " << i << endl;
				break;
			}
		case 4:
			{
				cout << "Vui long nhap x can them vao cuoi danh sach: ";
				cin >> x;
				i = insert_last(a, n, x);
				if (i == 0)
					cout << "Danh sach da day, khong the them " << x << "!\n";
				else
				{
					cout << "Da them phan tu x = " << x << " vao cuoi danh sach !\n";
					cout << "Danh sach sau khi them la:\n";
					output(a, n);
				}
				break;
			}
		case 5:
			{
				i = delete_last(a, n);
				if (i > 0)
				{
					cout << "Xoa thanh cong!\n";
					cout << "Danh sach sau khi xoa phan tu cuoi la:\n";
					output(a, n);
				}
				else
					cout << "Danh sach dang trong, khong co phan tu nao!\n";
				break;
			}
		case 6:
			{
				cout << "Vui  long nhap vi tri can xoa i = ";
				cin >> i;
				i = Delete(a, n, i);
				if (i == 1)
				{
					cout << "Xoa thanh cong !\n";
					cout << "Danh sach sau khi xoa la:\n";
					output(a, n);
				}
				else
					cout << "Khong co phan tu nao de xoa!\n";
				break;
			}
		case 7:
			{
				cout << "Vui long nhap gia tri can xoa x =";
				cin >> x;
				i = search_delete(a, n, x);
				if (i == 1)
				{
					cout << "Xoa thanh cong phan tu co gia tri x = " << x << endl;
					cout << "Danh sach sau khi xoa la: \n";
					output(a, n);
				}
				else
					cout << "Khong co phan tu nao de xoa\n";
				break;
			}
		case 8:
			{
			cout << "Goodbye!\n";
			break;
			}
		default:
			break;
		}
	} while (choice != 8);
	system("pause");
	return 0;
}