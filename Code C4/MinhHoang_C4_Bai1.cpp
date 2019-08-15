#include <iostream>
using namespace std;

#define COUNT 20

//Cau 1.1: Khai bao cau truc cay nhi phan tim kiem
struct node
{
	int info;
	node* left;
	node* right;
};
node* root;
//Cau 1.2: Khoi tao cay rong
void tree_Empty()
{
	root = NULL;
}
//Cau 1.3: Them 1 phan tu vao cay
void insertNode(node*& p, int x)
{
	if (p == NULL)
	{
		p = new node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->info == x)
			return;
		else
			if (p->info > x)
				return insertNode(p->left, x);
			else
				return insertNode(p->right, x);
	}
}
//Cau 1.4: Tim 1 phan tu trong cay
node* search(node* p, int x)
{
	if (p != NULL)
	{
		if (p->info == x)
			return p;
		else
			if (x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}
//Cau 1.5: Xoa 1 phan tu trong cay
//Tim node the mang
void searchStandFor(node*& p, node*& q)
{
	if (q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
//Xoa
int Delete(node*& T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		node* p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
}
//Cau 1.6: Duyet cay theo NLR
void duyetNLR(node* p)
{
	if (p != NULL)
	{
		cout << p->info << " ";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}
//Cau 1.7: Duyet cay theo LNR
void duyetLNR(node* p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}
//Cau 1.8: Duyet cay theo LRN
void duyetLRN(node* p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << " ";
	}
}
//Ham xuat cay
void print2DUtil(node* p, int space)
{
	//Base case
	if (p == NULL)
		return;

	//Increase distance between levels
	space += COUNT;

	//Process right child first
	print2DUtil(p->right, space);

	//Prin current node after space
	//count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";

	//Process left child
	print2DUtil(p->left, space);
}
//Wrapper over print2DUtil
void process_Tree()
{
	//Pass initial space count as 0
	print2DUtil(root, 0);
}

int main()
{
	int choice = 0;
	int x, i;
	node* p;
	system("cls");
	cout << "-------- Bai tap chuong 4, cau 1, CAY NPTK --------\n";
	cout << "1. Khoi tao cay NPTK rong\n";
	cout << "2. Them 1 phan tu vao cay NPTK\n";
	cout << "3. Tim 1 phan tu trong cay NPTK\n";
	cout << "4. Xoa 1 phan tu trong cay NPTK\n";
	cout << "5. Duyet cay theo thu tu NLR\n";
	cout << "6. Duyet cay theo thu tu LNR\n";
	cout << "7. Duyet cay theo thu tu LRN\n";
	cout << "8. Xuat cay NPTK\n";
	cout << "9. Thoat\n";
	do {
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			tree_Empty();
			cout << "Khoi tao cay rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap gia tri can them: ";
			cin >> x;
			insertNode(root, x);
			cout << "Cay sau khi them:\n";
			process_Tree();
			break;
		case 3:
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			p = search(root, x);
			if (p == NULL)
				cout << "Khong tim thay gia tri " << x << " trong cay\n";
			else
				cout << "Tim thay " << x << " trong cay\n";
			break;
		case 4:
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong tim thay nhi phan de xoa\n";
			else
			{
				cout << "Xoa thanh cong\n";
				cout << "Cay sau khi xoa:\n";
				process_Tree();
			}
			break;
		case 5:
			cout << "Ket qua duyet theo NLR:\n";
			duyetNLR(root);
			break;
		case 6:
			cout << "Ket qua duyet theo LNR:\n";
			duyetLNR(root);
			break;
		case 7:
			cout << "Ket qua duyet theo LRN:\n";
			duyetLRN(root);
			break;
		case 8:
			cout << "Cay dang luu tru:\n";
			process_Tree();
			break;
		case 9:
			cout << "Tam biet\n";
			break;
		default:
			break;
		}
	} while (choice != 9);
	return 0;
}