#include <iostream>
using namespace std;

//Khai bao cau truc STACK
#define MAX 100
int a[MAX];
int sp;

//Khoi tao STACK rong
void init(int a[], int &sp)
{
    sp=-1;
}

//Kiem tra STACK rong
int isEmpty(int a[], int sp)
{
    if(sp == -1)
        return 1;
   return 0;
}

//Kiem tra STACk day
int isFull(int a[], int sp)
{
    if(sp == MAX - 1)
        return 1;
	return 0;
}

//Them mot phan tu vao STACK
int Push(int a[], int &sp, int x)
{
    if(sp != MAX - 1)
    {
        a[++sp] = x;
        return 1;
    }
    return 0;
}

//Xoa mot phan tu trong STACk
int Pop(int a[], int &sp, int &x)
{
    if (sp != -1)
    {
        x = a[sp--];
        return 1;
    }
    return 0;
}

//Doi tu he thap phan sang he nhi phan
void decimalToBinary(int x)
{
    int r;
    while(x != 0)
    {
        r = x % 2;
        Push(a, sp, r);
        x = x / 2;
    }
}

//Xuat he nhi phan
void outBinary()
{
    int x;
    while(sp != -1)
    {
        Pop(a, sp, x);
        cout << x;
    }
}

int main()
{
    int i, choice, x;
	system("cls");
	cout << "--------	BAI TAP 6, CHUONG 2, STACK (NGAN XEP, LKD)	--------\n";
	cout << "1. Khoi tao stack rong\n";
	cout << "2. Kiem tra stack rong\n";
	cout << "3. Kiem tra stack day\n";
	cout << "4. Them 1 phan tu vao stack\n";
	cout << "5. Xoa 1 phan tu trong stack\n";
	cout << "6. Doi tu he thap phan sang he nhi phan\n";
	cout << "7. Thoat\n";
    do
    {
        cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
        switch(choice)
        {
        case 1:
            init(a, sp);
            cout << "Khoi tao stack rong thanh cong!\n";
            break;
        case 2:
            i = isEmpty(a, sp);
            if(i == 1)
                cout << "Danh sach rong!\n";
            else
                cout << "Danh sach khong rong!\n";
            break;
        case 3:
            i = isFull(a, sp);
            if(i == 1)
                cout << "Danh sach da day!\n";
            else
                cout << "Danh sach chua day\n";
            break;
        case 4:
            cout << "Nhap gia tri can them: ";
            cin >> x;
            i = Push(a, sp, x);
            if(i == 1)
                cout << "Them thanh cong\n";
            else
                cout<<"Them khong thanh cong\n";
            break;
        case 5:
           i = Pop(a, sp, x);
            if (i == 1)
                cout << "Xoa thanh cong\n";
            else
                cout << "Xoa khong thanh cong\n";
            break;
        case 6:
            cout << "Nhap 1 so he thap phan: ";
            cin >> x;
            decimalToBinary(x);
            cout << x << " doi sang he nhi phan la: ";
			outBinary();
            cout << endl;
            break;
		case 7:
			cout << "Goodbye...!\n";
			break;
		default:
			break;
        }
    }	while (choice != 7);
	return 0;
}