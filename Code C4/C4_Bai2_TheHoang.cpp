//Chuong 4 - bai 2
#include <iostream>
#include <stack>
using namespace std;

//2.1 Khai bao cau truc cay NPTK
struct node
{
	int info;
	node *left;
	node *right;
};
node *createnode(int x)
{
	node *p = new node();
	p->info = x;
	p->left = p->right = NULL;
	return p;
}
//2.4 Tim 1 phan tu trong cay
node *tim(node *root, int x)
{
	if(root == NULL)
		return NULL;
	node *p = root;
	while(p != NULL)
	{
		if(p->info > x)
			p = p->left;
		else
			p = p->right;
	}
	return p;
}
//2.3 Them 1 phan tu vao cay
void insertnode(node *root, int x)
{
	node *k = createnode(x);
	if(root == NULL)
	{
		root = k;
		return;
	}
	else
	{
		node *h = tim(root,x);
		if(h != NULL)
			if(h->info > x)
				h->left = k;
			else
				h->right = k;
	}
}
int leftof(const int value, const node *root)
{
	return value < root->info;
}
int rightof(const int value, const node *root)
{
	return value > root->info;
}
int leftmostvalue(const node*root)
{
	while(root->left != NULL)
		root = root->left;
	return root->info;
}

//2.5 Xoa 1 nut trong cay
node *xoa(node *root, int value)
{
	if(root == NULL)
		return root;
	if(leftof(value,root))
		root->left = xoa(root->left, value);
	else
		if(rightof(value,root))
			root->right = xoa(root->right,value);
		else
		{
			if(root->left == NULL)
			{
				node *newroot = root->right;
				free(root);
				return newroot;
			}
			if(root->right == NULL)
			{
				node *newroot = root->left;
				free(root);
				return newroot;
			}
			root->info = leftmostvalue(root->right);
			root->right = xoa(root->right,root->info);
		}
		return root;
}
//2.7 Duyet cay LNR
void inOrder(struct node *root)
{
	stack<node *> s;
	node *curr = root;
	while(curr != NULL || s.empty() == false)
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->info << " ";
		curr = curr->right;
	}
}
void createtree(node *root, int a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		insertnode(root,a[i]);
	}
}
//2.6 Duyet cay NLR
void preorder(struct node *root)
{
	if(root == NULL)
		return;
	stack<node *>nodestack;
	nodestack.push(root);
	while(nodestack.empty() == false)
	{
		struct node *temp_node = nodestack.top();
		cout << temp_node->info << " ";
		nodestack.pop();
		if(temp_node->right)
			nodestack.push(temp_node->right);
		if(temp_node->left)
			nodestack.push(temp_node->left);
	}
}

//2.8 Duyet cay LRN
void postorder(node *root)
{
	stack<node*> stk;
	stk.push(root);
	stack<int> out;
	while(!stk.empty())
	{
		node *curr = stk.top();
		stk.pop();
		out.push(curr->info);
		if(curr->left)
			stk.push(curr->left);
		if(curr->right)
			stk.push(curr->right);
	}
	while(!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}

int main()
{
	node *root = NULL;
	int a[] = {41,6,36,46,15,54,47,11,14,49,47};
	int n = 11;
	createtree(root,a,n);
	insertnode(root,24);
	printf("Duyet LNR: ");
	inOrder(root);
	printf("Duyet NLR: ");
	preorder(root);
	printf("Duyet LRN: ");
	postorder(root);
	printf("\nXoa node: 24");
	root = xoa(root,24);
	printf("Duyet LNR: ");
	inOrder(root);
	printf("Duyet NLR: ");
	preorder(root);
	printf("Duyet LRN: ");
	postorder(root); 
	return 0;
}