#include <iostream>
using namespace std;
//cau 1.1
#define MAX 100
int a[MAX];
int n;
//cau 1.2
void input(int a[], int& n)
{
	cout << "Nhap so luong phan tu can dung: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}
//cau 1.3
void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "	";
	cout << endl;
}
//cau 1.4
int Search(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	return i;
}
//cau 1.5
int inSert_last (int a[], int& n, int x)
{
	if (n < MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	return 0;
}
//cau 1.6
int Delete_last(int a[], int& n)
{
	if (n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}
//cau 1.7
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
// cau 1.8
int SearchAndDelete(int a[], int& n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	return 0;
}
//menu
void menu()
{
	cout << "--------MENU--------";
	cout << "1. Nhap danh sach\n ";
	cout << "2. Xuat danh sach\n ";
	cout << "3. Tim mot phan tu trong danh sach\n ";
	cout << "4. Them mot phan tu cuoi danh sach\n ";
	cout << "5. Xoa phan tu cuoi dnh sach\n ";
	cout << "6. Xoa phan tu tai vi tri thu i \n";
	cout << "7. Tim va xoa phan tu\n ";
	cout << "8. Thoat\n ";
}
int main()
{
	int x, i;
	int choice = 0;
	system("cls");
	menu();
	do {
		cout << "Vui long chon de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(a, n);
			cout << "Ban vua nhap danh sach thanh cong\n";
			break;
		case 2:
			cout << "Danh sach vua nhap la: \n";
			output(a, n);
			break;
		case 3:
			cout << "Vui long nhap x can tim: ";
			cin >> x;
			i = Search(a, n, x);
			if (i == 0)
				cout << "Khong tim thay phan tu co gia tri " << x << endl;
			else
				cout << "Tim thay tai vi tri i = " << i << endl;
			break;
		case 4:
			cout << "Vui long nhap x can them vao cuoi DS: ";
			cin >> x;
			i = inSert_last(a, n, x);
			if (i == 0)
				cout << "Danh sach da day, khong the them!\n";
			else
			{
				cout << "Da them phan tu x = " << x << " vao cuoi DS!\n" << endl;
				cout << "Danh sach sau khi them la:\n";
				output(a, n);
			}
			break;
		case 5:
			i = Delete_last(a, n);
			if (i == 0)
				cout << "Danh sach dang rong, khong co phan tu nao!!" << endl;
			else
			{
				cout << "Xoa thanh cong !" << endl;
				cout << "Danh sach sau khi xoa la:\n";
				output(a, n);
			}
			break;
		case 6:
			cout << "Nhap vao vi tri can xoa i = ";
			cin >> i;
			i = Delete(a, n, i);
			if (i == 1)
			{
				cout << "Xoa thanh cong !" << endl;
				cout << "Danh sach sau khi xoa la:\n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu de xoa!!" << endl;
			break;
		case 7:
			cout << "Vui long nhap gia tri can xoa x = ";
			cin >> x;
			i = SearchAndDelete(a, n, x);
			if (i == 1)
			{
				cout << "Xoa thanh cong !" << endl;
				cout << "Danh sach sau khi xoa la:\n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu de xoa!!" << endl;
			break;
		case 8:
			cout << "Goodbye!!!\n";
			break;
		default:
			break;
		}
	} while (choice < 8);
	system("pause");
	return 0;
}