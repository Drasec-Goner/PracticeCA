#include<iostream>
#define MAXSIZE 5
using namespace std;

class Stack
{
	public:
		int top;
		int st[MAXSIZE];
		Stack() //intialising top as -1
		{
			top=-1;
		}
		
		void push(int);
		int pop();
		void topElement();
		bool empty();
};

bool Stack::empty() //checks if stack is empty or not
{
	return top==-1;
}

void Stack::push(int d)
{
	if(top==MAXSIZE-1) //checks if stack is full or not
	{
		cout<<"Stack Overflow."<<endl;
	}
	else
	{
		top++; //increment the value to insert into stack
		st[top]=d;
	}
}

int Stack::pop()
{
	if(empty()) //checks if stack is empty or not
	{
		cout<<"Stack Underflow. Cannot Pop."<<endl;
		return -1;
	}
	else
	{
		return st[top--];
	}
}

void Stack::topElement()
{
	if(empty())
	{
		cout<<"Stack is Empty."<<endl;
	}
	cout<<"Top of Stack: "<<st[top]<<endl; //returns the top element of stack
}

int main()
{
	Stack s;
	int n;
	cout<<"Enter the no. of elements you want to insert: ";
	cin>>n;
	int d;
	cout<<"Enter the elements you want to insert: "<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		s.push(d);
	}
	s.topElement();
	while(!s.empty()) //loop goes on until stack empty
	{
		cout<<"Popped: "<<s.pop()<<endl;
	}
}
