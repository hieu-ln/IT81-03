#include <iostream>
using namespace std;

#define COUNT 10
//Khai bao cau truc cay
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;

//Khoi tao cay nhi phan rong
void tree_empty()
{
	root = NULL;	
}

void print2DUtil(Node *p, int space)
{
	//Base case
	if (p == NULL)
		return;

	//Increase distance between levels
	space += COUNT;

	//Process right child first
	print2DUtil(p->right, space);

	//Print current node after space
	//count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;

	//Process left child
	print2DUtil(p->left, space);
}

//Wrapper over print2DUtil()
void process_tree()
{
	//Pass initial space count as 0
	print2DUtil(root, 0);
}

//Tim kiem mot phan tu trong cay
Node *search(Node *p, int x)
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

//Them mot phan tu vao cay
void insertNode(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
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

//Duyet cay theo thu tu NLR
void duyetNLR(Node *p)
{
	if (p != NULL)
	{
		cout << p->info << "\t";
		duyetNLR(p->left);
		duyetNLR(p->right);
	}
}

//Duyet cay theo thu tu LNR
void duyetLNR(Node *p)
{
	if (p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << "\t";
		duyetLNR(p->right);
	}
}

//Duyet cay theo thu tu LRN
void duyetLRN(Node *p)
{
	if (p != NULL)
	{
		duyetLRN(p->left);
		duyetLRN(p->right);
		cout << p->info << "\t";
	}
}

//Xoa mot nut trong cay
void searchStandFor(Node *&p, Node *&q)
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

int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->info == x)
	{
		Node *p = T;
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

int main()
{
	int x, choice = 0, i;
	Node *p;
	system("cls");
	cout << "----------	BAI TAP 1, CHUONG 4, CAY NHI PHAN TIM KIEM	--------\n";
	cout << "1. Khoi tao cay rong\n";
	cout << "2. Them 1 phan tu vao cay\n";
	cout << "3. Tim 1 phan tu trong cay\n";
	cout << "4. Xoa 1 nut trong cay\n";
	cout << "5. Duyet cay theo thu tu NLR\n";
	cout << "6. Duyet cay theo thu tu LNR\n";
	cout << "7. Duyet cay theo thu tu LNR\n";
	cout << "8. Xuat cay NPTK\n";
	cout << "9. Thoat\n";
	do {
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			tree_empty();
			cout << "Ban vua khoi tao cay NPTK rong thanh cong\n";
			break;
		case 2:
			cout << "Nhap phan tu can them: ";
			cin >> x;
			insertNode(root, x);
			cout << "Cay NPTK sau khi them: ";
			process_tree();
			break;
		case 3:
			cout << "Nhap phan tu can tim: ";
			cin >> x;
			p = search(root, x);
			if (p ==  NULL)
				cout << "Khong tim thay " << x << " trong cay NPTK\n";
			else
				cout << "Da tim thay " << x << "trong cay NPTK\n";
			break;
		case 4:
			cout << "Nhap phan tu can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if (i == 0)
				cout << "Khong the tim thay " << x << " de xoa\n";
			else
				cout << "Da xoa thanh cong phan tu " << x << " trong cay NPTK\n";
			cout << "Cay NPTK sau khi xoa: ";
			process_tree();
			break;
		case 5:
			cout << "Cay NPTK duyet theo NLR la: ";
			duyetNLR(root);
			break;
		case 6:
			cout << "Cay NPTK duyet theo LNR la: ";
			duyetLNR(root);
			break;
		case 7:
			cout << "Cay NPTK duyet theo LRN la: ";
			duyetLRN(root);
			break;
		case 8:
			cout << "Cay NPTK nhu sau: ";
			process_tree();
			break;
		case 9:
			cout << "Goodbye...!\n";
			break;
		default:
			break;
		}
	} while (choice != 9);
	return 0;
}