#include<iostream>
using namespace std;

class node
{
	public:
		node *left;
		int data;
		node *right;
};
node *root; //global variable
class BST
{
	public:
		BST()
		{
			root =NULL;
		}
		
		void insert(int);
		void inorder(node *);
		void preorder(node *);
		void postorder(node *);
		node * deleteNode(node *, int);
		node * minnode(node *);
		int height(node *);
};

int BST::height(node *p)
{
	if(p==NULL) //if tree has no node
	{
		return -1;
	}
	int l=height(p->left); //checks the height of left subtree
	int r=height(p->right); //checks the height of right subtree
	
	return (r<l)? (l+1) : (r+1); //checks which subtree height is larger and returns it as its height
}

node * BST::minnode(node *p)
{
	node *cur = new node;
	cur=p;
	while(cur->left!=NULL) //traversing to the left most node of the subtree
	{
		cur=cur->left;
	}
	return cur; //returning the leftmost subtree node
}

node * BST::deleteNode(node *rt, int key)
{
	if(rt==NULL)
	{
		cout<<"Element not found"<<endl;
		return NULL;
	}
	else
	{
		if(key > rt->data)
		{
			rt->right=deleteNode(rt->right,key);
		}
		else if(key < rt->data)
		{
			rt->left = deleteNode(rt->left, key);
		}
		else // when reached the destination
		{
			if(rt->left==NULL) //check if right node has element
			{
				node *temp = rt->right;
				delete rt;
				return temp;
			}
			else if(rt->right==NULL) //check if left node has element
			{
				node *temp = rt->left;
				delete rt;
				return temp;
			}
			else if(rt->left==NULL && rt->right==NULL) // check if node has no child
			{
				delete rt;
				return NULL;
			}
			node *temp = minnode(rt->right); //get the smallest node in right side of tree
			rt->data=temp->data; //replace that node with the smallest right subtree node
			rt->right = deleteNode(rt->right, temp->data); // delete the smallest node
		}
		return rt;
	}
}

void BST::insert(int d)
{
	node *temp =new node;
	temp->data = d;
	temp->left = NULL;
	temp->right = NULL;
	
	if(root==NULL) //inserting first element
	{
		root=temp;
	}
	else //inserting element when root is initialised
	{
		node *pre = NULL;
		node *cur = root;
		while(cur!=NULL) // traversing to the leaf node
		{
			pre=cur;
			if(d > cur->data)
				cur = cur->right;
			else
				cur = cur->left;
		}
		if(d > pre->data) //linking the leaf node
			pre->right=temp;
		else
			pre->left=temp;
	}	
}

void BST::inorder(node *p)
{
	if(p!=NULL) // left-root-right
	{
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

void BST::preorder(node *p)
{
	if(p!=NULL) //root-left-right
	{
		cout<<p->data<<" ";
		preorder(p->left);
		preorder(p->right);
	}
}

void BST::postorder(node *p)
{
	if(p!=NULL) //left-right-root
	{
		postorder(p->left);
		postorder(p->right);
		cout<<p->data<<" ";
	}
}

int main()
{
	BST b;
	int n;
	cout<<"Enter the no of nodes you want to insert: ";
	cin>>n;
	cout<<"\nEnter the data elements: "<<endl;
	for(int i=0;i<n;i++)
	{
		int t;
		cin>>t;
		b.insert(t);
	}
	cout<<"\nInorder: ";
	b.inorder(root);
	cout<<"\nPreorder: ";
	b.preorder(root);
	cout<<"\nPostorder: ";
	b.postorder(root);
	int d;
	cout<<"\nHeight of tree: "<<b.height(root);
	cout<<"\nEnter the element you want to delete: ";
	cin>>d;
	b.deleteNode(root, d);
	cout<<"\nAfter deletion: ";
	b.preorder(root);
	cout<<"\nHeight of tree:"<<b.height(root);
}
