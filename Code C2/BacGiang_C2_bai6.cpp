#include <iostream>
using namespace std;

//khai bao cau truc stack
#define max 100
int a[max];
int sp;

//tao stack rong
void init(int a[], int &sp)
{
    sp=-1;
}

//xet stack rong
int isEmpty(int a[], int sp)
{
    if(sp == -1)
        return 1;
    else
        return 0; //tai sao khong dung else
}

//xet stack day
int isFull(int a[], int sp)
{
    if(sp == max-1)
        return 1;
    else
        return 0;
}

//them phan tu vao stack
int push(int a[], int &sp, int x)
{
    if(sp != max-1)
    {
        a[++sp] = x;
        return 1;
    }
    else
        return 0;
}

//lay/xoa phan tu stack
int pop(int a[], int &sp, int &x)
{
    if (sp != -1)
    {
        x = a[sp--];
        return 1;
    }
    else
        return 0;
}

//chuyen he 10 sang he 2
void convertDectoBin(int d)
{
    int du;
    while(d != 0)
    {
        du = d % 2;
        push(a, sp, du);
        d = d/2;
    }
}

//in ra he 2
void printBin()
{
    int x;
    while(sp != -1)
    {
        pop(a, sp, x);
        cout<<x;
    }
}

int menu()
{
    int chon;
    cout << "--------MENU--------\n" << "1. Khoi tao stack\n" << "2. Xet rong\n" << "3. Xet day\n" << "4. Them stack\n" << "5. Xoa stack\n" << "6. Chuyen he 10 sang he 2\n" << "0. Thoat\n" << "---------------\n" << "Ban chon so: ";
    cin>>chon;
    return chon;
}

int main()
{
    int x, chon;
    do
    {
        chon = menu();
        switch(chon)
        {
        case 1:
            init(a, sp);
            cout << "da khoi tao stack\n";
            break;
        case 2:
            int k;
            k = isEmpty(a, sp);
            if(k == 1)
                cout << "danh sach rong\n";
            else
                cout << "danh sach khong rong\n";
            break;
        case 3:
            int m;
            m = isFull(a, sp);
            if(m == 1)
                cout << "danh sach day\n";
            else
                cout << "danh sach chua day\n";
            break;
        case 4:
            cout << "nhap gia tri can them: ";
            cin >> x;
            int n;
            n= push(a, sp, x);
            if(n == 1)
                cout << "them thanh cong\n";
            else
                cout<<"them khong thanh cong\n";
            break;
        case 5:
            int p;
            p= pop(a, sp, x);
            if (p == 1)
                cout << "xoa thanh cong\n";
            else
                cout << "xoa khong thanh cong\n";
            break;
        case 6:
            int d;
            cout << "nhap so he 10: ";
            cin >> d;
            convertDectoBin(d);
            cout << "he 2: ";
            printBin();
            cout<<endl;
            break;
        }
    }
    while (chon != 0);
	return 0;
}
