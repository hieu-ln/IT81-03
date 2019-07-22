//Danh sach dac
#include <iostream>
using namespace std;

//Khai bao cau truc danh sach
#define MAX 100
struct PhanTu
{
	int power;
	int c;
};

PhanTu daThuc[MAX];
int n;

//Nhap vao 1 da thuc
void input(PhanTu daThuc[], int &n)
{
	cout << "Nhap so luong phan tu can: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao da thuc phan tu thu " << i << ":\n";
		cout << "Nhap c va power: ";
		cin >> daThuc[i].c >> daThuc[i].power;
	}
}

//Tim bac lon nhat cua 1 da thuc
int maxPower(PhanTu daThuc[], int n)
{
	int max = daThuc[0].power;
	for (int i = 1; i < n; i++)
		if (daThuc[i].power > max)
			{
				max = daThuc[i].power;
			}
	return max;
}

//Rut gon da thuc
void simplify(PhanTu daThuc[], int &n)
{
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j > i; j--)
			if (daThuc[i].power == daThuc[j].power)
			{
				daThuc[i].c += daThuc[j].c;
				for (int k = j; k < n - 1; k++)
					daThuc[k] = daThuc[k + 1];
				n--;
			}
}

//Xuat da thuc
void output(PhanTu daThuc[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (daThuc[i].c > 0)
			if (i == 0)
				cout << daThuc[i].c << "x^(" << daThuc[i].power << ")";
			else
				cout << " + " << daThuc[i].c << "x^(" << daThuc[i].power << ")";
		else
			if (i == 0)
				cout << " -" << -daThuc[i].c << "x^(" << daThuc[i].power << ")";
			else
				cout << " - " << -daThuc[i].c << "x^(" << daThuc[i].power << ")";
		
	}
	cout << endl;
}

//Cong 2 da thuc
void add(PhanTu a[], int na, PhanTu b[], int nb, PhanTu c[], int &nc)
{
	int count = 0;
	for (int i = 0; i < na; i++)
	{
		c[count].c = a[i].c;
		c[count].power = a[i].power;
		count++;
	}
	for (int j = 0; j < nb; j++)
	{
		c[count].c = b[j].c;
		c[count].power = b[j].power;
		count++;
	}
	nc = count;
	simplify(c, nc);
}

//Tru 2 da thuc
void subtract(PhanTu a[], int na, PhanTu b[], int nb, PhanTu c[], int &nc)
{
	int count = 0;
	for (int i = 0; i < na; i++)
	{
		c[count].c = a[i].c;
		c[count].power = a[i].power;
		count++;
	}
	for (int j = 0; j < nb; j++)
	{
		c[count].c = -b[j].c;
		c[count].power = b[j].power;
		count++;
	}
	nc = count;
	simplify(c, nc);
}

//Nhan 2 da thuc
void multiply(PhanTu a[], int na, PhanTu b[], int nb, PhanTu c[], int &nc)
{
	int count = 0;
	for (int i = 0; i < na; i++)
		for (int j = 0; j < nb; j++)
		{
			c[count].c = a[i].c * b[i].c;
			c[count].power = a[i].power + b[i].power;
			count++;
		}
	nc = count;
	simplify(c, nc);
}

//Chia 2 da thuc
void divide(PhanTu a[], int na, PhanTu b[], int nb, PhanTu c[], int &nc, PhanTu r[], int &nr)
{
	int count = 0, l = 0;
	int maxpa = maxPower(a, na), maxpb = maxPower(b, nb);
	int x, y, z;
	for (int i = 0; i < na; i++)
		r[i] = a[i];
	nr = na;
	int maxpr = maxpa;
	if (maxpa < maxpb)
	{
		c = 0;
	}
	else
	{
		if (maxpa == maxpb)
		{
			for (int i = 0; i < n; i++)
			{
				if (a[i].power == maxpa)
					x = a[i].c;
				if (b[i].power == maxpa)
					y = b[i].c;
			}
			c[count].c = x / y;
			c[count].power = maxpa;
			r = 0;
		}
		else
		{
			int k = 0;
			for (int i = k; i < nb; i++)
				if (a[i].power == maxpa)
				{
					c[count].c = a[i].c / b[i].c;
					c[count].power = a[i].power - b[i].power;
					for (int j = 0; j < nb; j++)
						if (r[j].power == maxpr && nr <= nb)
						{
							if (b[j].power == maxpr)
								r[j].c = r[j].c - c[j].c * b[j].c;
							l++;
						}
					k = k + nb;
					if (r[i].power < b[i].power)
						break;
					count++;
				}
		}
	}
	nr = l;
	nc = count;

}

int main()
{
	int choice;
	int n, n1, n2, n3 = 0;
	PhanTu daThuc1[MAX], daThuc2[MAX], daThuc3[MAX];
	cout << "1. Nhap 1 da thuc\n";
	cout << "2. Xuat 1 da thuc\n";
	cout << "3. Cong 2 da thuc\n";
	cout << "4. Tru 2 da thuc\n";
	cout << "5. Nhan 2 da thuc\n";
	cout << "6. Chia 2 da thuc\n";
	cout << "7. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			input(daThuc, n);
			break;
		case 2:
			cout << "Da thuc hien tai la: ";
			simplify(daThuc, n);
			output(daThuc, n);
			break;
		case 3: case 4: case 5: case 6:
			cout << "Nhap da thuc thu nhat:\n";
			input(daThuc1, n1);
			cout << "Nhap da thuc thu hai:\n";
			input(daThuc2, n2);
			if (choice == 3)
			{
				add(daThuc1, n1, daThuc2, n2, daThuc3, n3),
				cout << "Tong 2 da thu la: ";
				output(daThuc3, n3);
			}
			if (choice == 4)
			{
				subtract(daThuc1, n1, daThuc2, n2, daThuc3, n3),
				cout << "Hieu 2 da thu la: ";
				output(daThuc3, n3);
			}
			if (choice == 5)
			{
				multiply(daThuc1, n1, daThuc2, n2, daThuc3, n3);
				cout << "Tich 2 da thuc la: ";
				output(daThuc3, n3);
			}
			if (choice == 6)
			{
				PhanTu daThuc4[MAX];
				int n4;
				divide(daThuc1, n1, daThuc2, n2, daThuc3, n3, daThuc4, n4);
				if (n3 == 0)
					cout << "Thuong cua 2 da thuc la 0\n";
				else
					if (n4 == 0)
					{
						cout << "Thuong cua 2 da thuc la: ";
						output(daThuc3, n3);
						cout << " , khong co du\n";
					}
					else
					{
						cout << "Thuong cua 2 da thuc la: ";
						output(daThuc3, n3);
						cout << ", du: ";
						output(daThuc4, n4);
						cout << endl;
					}
			}
			
			break;
		case 7:
			cout << "Goodbye...!\n";
			break;
		default:
			break;
		}
	} while (choice != 7);
	return 0;
}