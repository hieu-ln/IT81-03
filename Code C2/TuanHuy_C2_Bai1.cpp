#include <iostream>
#include <stdio.h>
using namespace std;
#define max 100
int a[max];
int n;

void input(int a[], int &n)
{
	cout<<"nhap so luong phan tu " ;
	cin >>n;
	cout<<"nhap vao cac phan tu cua danh sach ";
		for( int i=0; i < n;i++)
		{
			cout<< "a[ "<<i<<"]" << endl;
			cin >> a[i];
		} 

}
void output(int a[],int n)
{
	for ( int i=0 ; i < n;i++)
		cout<<a[i] <<"\t" << endl;
	cout<<endl;
}

int search(int a[], int&n, int x)
{
	int i=0;

	while( i < n && a[i] != n )
	{
		i++;
		if( i==n )
			return -1;
	}
	return 1;
}
int insert_last ( int a[], int&n, int x)
{
	if(n<max )
	{
		a[n]=x;
		n++;
		return 1;
	}
	return 0;
}
int delete_last(int a[] , int &n )
{
	if (n > 0)
	{
		n--;
	return 1;
	}
	return 0;
}
int Delete( int a[] , int &n , int i)
{
	if( i>=0 && i < n)
	{
		for ( int j = 0 ; j < n - 1 ; j++ )
		{
			a[j] = a[j+ 1];
		}
		n--;
		return 1;
	}
	return 0;
}
int searchAnhDelete( int a[] , int &n, int x )
{
	for ( int i=0 ; i < n ; i++ )
	{
		if (a[i]==x )
			Delete(a,n,i);
		return 1;
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x,i;
	system("Cls");
	cout<<"----Bai tap chuong 1 -----"  << endl;
	cout<<"1.nhap danh sach " << endl;
	cout<<"2,xuat danh sach" << endl;
	cout<<"3.tim phan tu co gia tri x trong danh sach "<< endl;
	cout<<"4.them phan tu cuoi danh sach" << endl;
	cout<<"5.xoa phan tu cuoi danh sach" << endl;
	cout<<"6.xoa phan tu tai vi tri i " << endl;
	cout<<"7.tim phan tu gia tri x va xoa neu co " << endl;
	cout<<"8.thoat " << endl;
	do{
		cout<<"vui long chon so de thuc hien " << endl;
		cin >> choice;
		switch(choice)
		{
			case 1:
				input(a,n);
				cout<<"ban vua nhap danh sach thanh cong\n " ;
				break;
			case 2:
				cout<<"danh sach da nhap la \n";
				output(a,n);
				break;
			case 3:
				cout<<"vui long nhap x can tim ";
				cin >> x;
				i = search(a,n,x);
				if ( i == -1)
					cout<< " khong tim thay phan tu " << endl;
				else
					cout<< " tim thay phan tu tai vi tri i=" << i << endl;
				break;
			case 4:
				cout<<"vui long nhap x can them vao cuoi danh sach \n " ;
				cin >> x;
				i=insert_last(a,n,x );
				if ( i==0 )
				{
					cout << "danh sach da day khong the them " << endl;
				}
				else
					cout<<"da them phan tu x=" << i << " vao cuoi danh sach " << endl;
					cout<< " danh sach sau khi them la " << endl;
					output(a,n);
					break;
			case 5:
				i=delete_last(a,n);
				if ( i > 0 )
				{
					cout<< " xoa thanh cong \n " ;
					cout<<"danh sach sau khi xoa \n ";
					output(a,n);
				}
				else
					cout<< " khong the xoa " << endl;
				break;
			case 6:
				cout<<"vui long nhap vi tri can xoa " << endl;
				cin >> x;
				if ( i == 1)
				{
					cout<< " xoa thanh cong phan tu co gia tri x=" << x <<endl;
					cout<<"danh sach sau khi xoa" <<endl;
					output(a,n);
				}
				else
					cout<<"khong the xoa" << endl;
				break;
			case 7:
				cout <<"vui long nhap sia tri can xoa x ";
				cin>>x;
				i=searchAnhDelete(a,n,x);
				if ( i == 1)
				{
					cout<< " xoa thanh cong x=" << x << endl;
					cout<<"danh sach sau khi xoa" << endl;
					output(a,n);
				}
				else
					cout<<"khong the xoa";
				break;
			case 8:
				cout<<"goodbye" << endl;
				break;
			default:
				break;
		}
	}while(choice !=8 );
		system("pause");
		return 0;
}

















	
		