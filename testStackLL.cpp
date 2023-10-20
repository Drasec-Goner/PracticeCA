#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
};

class Stack
{
	public:
		node *top;
		bool isEmpty()
		{
			return top==NULL;
		}
		
		void push(int);
		int pop();
		int topElement();
		
};

void Stack::push(int d)
{
	node *temp = new node;
	temp->data =d;
	temp->next = top;
	top=temp;
}

int Stack::pop()
{
	if(isEmpty())
	{
		cout<<"Stack Underflow. Cannot Pop."<<endl;
		return -1;
	}
	int val = top->data;
	node *temp = top;
	top = top->next;
	delete temp;
	
	return val;
}

int Stack::topElement()
{
	if(isEmpty())
	{
		cout<<"Stack is Empty."<<endl;
		return -1;
	}
	return top->data;
}

int main()
{
	Stack s;
	int n;
	cout<<"Enter the no. of element you want to push: ";
	cin>>n;
	int d;
	cout<<"Enter the elements you want to push: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		s.push(d);
	}
	
	cout<<"Top of Stack: "<<s.topElement()<<endl;
	while(!s.isEmpty())
	{
		cout<<"Popped: "<<s.pop()<<endl;
	}
}
