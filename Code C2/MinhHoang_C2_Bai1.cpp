#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void input(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i + 1 << "] = ";
		cin >> a[i];
	}
}
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << endl;
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
int insert_last(int a[], int& n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}
int delete_last(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	else
		return 0;
}
int Delete(int a[], int& n, int i)
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
int searchAndDelete(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
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
	cout << "-------- BAI TAP 1, CHUONG 2, DANH SACH DAC --------\n";
	cout << "1. Nhap danh sach\n2. Xuat danh sach\n3. Tim phan tu co gia tri x trong danh sach\n4. Them phan tu vao cuoi danh sach\n5. Xoa phan tu cuoi danh sach\n6. Xoa phan tu tai vi tri i\n7. Tim phan tu co gia tri x va xoa neu co\n8. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Nhap so luong phan tu can dung: ";
			cin >> n;
			input(a, n);
			cout << "Ban da nhap danh sach thanh cong\n";
			break;
		case 2:
			cout << "Danh sach dang luu tru:\n";
			output(a, n);
			break;
		case 3:
			cout << "Nhap gia tri x can tim: ";
			cin >> x;
			if (search(a, n, x) == -1)
				cout << "Khong tim thay " << x << " trong mang\n";
			else
				cout << x << " o vi tri thu " << search(a, n, x) << " trong mang\n";
			break;
		case 4:
			cout << "Nhap gia tri x can chen vao cuoi danh sach: ";
			cin >> x;
			if (insert_last(a, n, x) == 0)
				cout << "Danh sach da day, khong the them";
			else
			{
				cout << "Da them phan tu " << x << " vao cuoi danh sach\n";
				cout << "Danh sach sau khi them:\n";
				output(a, n);
			}
			break;
		case 5:
			if (delete_last(a, n) > 0)
			{
				cout << "Xoa thanh cong\n";
				cout << "Danh sach sau khi xoa phan tu cuoi la:\n";
				output(a, n);
			}
			else
				cout << "Danh sach dang rong, khong co phan tu nao\n";
			break;
		case 6:
			cout << "Nhap vi tri can xoa i = ";
			cin >> i;
			if (Delete(a, n, i) == 1)
			{
				cout << "Xoa thanh cong";
				cout << "Danh sach sau khi xoa la:\n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa\n";
			break;
		case 7:
			cout << "Nhap gia tri can xoa x = ";
			cin >> x;
			if (searchAndDelete(a, n, x) == 1)
			{
				cout << "Xoa thanh cong phan tu " << x << endl;;
				cout << "Danh sach sau khi xoa la:\n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa\n";
			break;
		case 8:
			cout << "Tam biet\n";
			break;
		default:
			break;
		}
	} while (choice != 8);
	return 0;
}