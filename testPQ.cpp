#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node *next;
		
		node(int value): data(value),next(NULL){} //initialising the values for the node data and address
};

class PQueue
{
	private:
		node *front;
		
		node *insertFront(int val) //adding node at the head/front
		{
			node *temp = new node(val);
			temp->next = front; //storing the front address in temp next
			front= temp; //temp becomes the new front with the old front linked at next
		}
		
	public:
		PQueue(): front(NULL){}
		
		bool empty() //returns true if queue is empty
		{
			return front==NULL;
		}
		
		void push(int d)
		{
			if(front==NULL || d > front->data) //checks if first element is intilialised or if first element is smaller than given value then it becomes the first element
			{
				insertFront(d);
			}
			else
			{
				node *cur = front;
				while(cur->next!=NULL && cur->next->data >=d) //traverse till it reaches the end of queue or till it reaches before element smaller than itself
				{
					cur=cur->next;
				}
				node *temp = new node(d);
				temp->next = cur->next; 
				cur->next=temp; //insert itself before the smaller element than itself or at the end
			}
		}
		
		void pop()
		{
			if(empty()) //checks if queue is empty or not
			{
				cout<<"Priority Queue Underflow. Cannot Pop."<<endl;
				return;
			}
			node*temp=front;
			front=front->next; //makes the next element as front 
			delete temp; //delete the front (not neccessary but u can print the pop value before deleting instead through the top method)
		}
		
		int top()
		{
			if(empty())
			{
				cout<<"Priority Queue is Empty."<<endl;
				return -1;
			}
			return front->data; //returns the top of the queue
		}
};

int main()
{
	PQueue p;
	int n;
	cout<<"Enter the no. of elements you want to push: ";
	cin>>n;
	cout<<"Enter the elements you want to push: "<<endl;
	int d;
	for(int i=0;i<n;i++)
	{
		cin>>d;
		p.push(d);
	}
	
	cout<<"Top of the queue: "<<p.top()<<endl;
	
	while(!p.empty())
	{
		cout<<"Popped: "<<p.top()<<endl;
		p.pop();
	}
}
