#include<iostream>
#define MAXSIZE 50
using namespace std;

class Stack
{
private:
    int top;
    char s[MAXSIZE];
public:
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == MAXSIZE - 1)
            return true;
        else
            return false;
    }
    void push(char ch)
    {
        if (isFull())
        {
            cout << "Stack Overflow." << endl;
        }
        else
        {
            top++;
            s[top] = ch;
        }
    }
    char pop()
    {
        char t = '\0';
        if (isEmpty())
        {
            cout << "Stack Underflow." << endl;
        }
        else
        {
            t = s[top];
            top--;
        }
        return t;
    }
    char getTop()
    {
        char t = '\0';
        if (isEmpty())
        {
            cout << "Stack is Empty";
        }
        else
        {
            t = s[top];
            return t;
        }
    }
    int ICP(char ch)
    {
        switch (ch)
        {
        case '(': //highest priority when inserting
            return 4;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        }
    }
    int ISP(char ch)
    {
        switch (ch)
        {
        case '(': //lowest priority when popping
            return 0;
        case '+': 
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '#': //to make it remain as stack marker
            return -1;
        }
    }

    void Infix_To_Postfix(char infix[50])
    {
        Stack s;
        int i = 0;
        char ch, x;
        s.push('#'); //make it as stack marker
        while (infix[i] != '\0') //until expression is finished
        {
            ch = infix[i];
            i++;
            if (ch >= 'a' && ch <= 'z') //pop any operand it comes across
                cout << ch;
            else if (ch == ')') // pop all operators in the ()
            {
                while (s.getTop() != '(')
                {
                    x = s.pop();
                    cout << x;
                }
                s.pop(); //pop the '('
            }
            else
            {
                while (ICP(ch) <= ISP(s.getTop())) // lower or equal precedence operator needs to be pushed in
                {
                    x = s.pop(); //pop all higher or equal precedence operator
                    cout << x;
                }
                s.push(ch); // push the that lower precendence operator in the stack
            }
        }
        while (!s.isEmpty()) // pop all remaining operator in the stack 
        {
            x = s.pop();
            if (x != '#') //pop until '#'
            {
                cout << x;
            }
        }
    }
};

int main()
{
    Stack s;
    char in[50];
    cout << "Enter the infix expression: ";
    cin.getline(in,50); //take whole expression in an char array
	cout << "Resulting Postfix expression: ";
    s.Infix_To_Postfix(in);
    return 0;
}

