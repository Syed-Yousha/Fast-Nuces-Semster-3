#include<iostream>
#include<string>
using namespace std;

class Stack
{
public:
    int top;
    int max;
    char *a;

    Stack(int m)
    {
        top = -1;
        max = m;
        a = new char[m];
    }

    bool push(char x)
    {
        if (top >= (max - 1))
        {
            cout << "\nStack overflow";
            return false;
        }
        else
        {
            a[++top] = x;
            cout << endl;
            cout << x << " pushed into stack\n";
            return true;
        }
    }

    char pop()
    {
        if (top < 0)
        {
            cout << "\nStack underflow";
            return 0;
        }
        else
        {
            char x = a[top];
            top--;
            cout << endl;
            cout << x << " is popped";
            return x;
        }
    }

    char peek()
    {
        if (top < 0)
        {
            cout << "\nStack is empty";
            return 0;
        }
        else
        {
            char x = a[top];
            return x;
        }
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    bool isFull()
    {
        return (top == max - 1);
    }

    ~Stack()
    {
        delete[] a;
    }
};

int getPrecedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{
    string postfix = "";
    Stack s(infix.length());

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalpha(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                char op = s.pop();
                postfix += op;
            }

            if (s.peek() == '(')
            {
                s.pop();
            }
        }
        else
        {
            while (!s.isEmpty() && getPrecedence(c) <= getPrecedence(s.peek()))
            {
                char op = s.pop();
                postfix += op;
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        char op = s.pop();
        postfix += op;
    }

    return postfix;
}
//k226007

int main()
{
    string infix = "a+b*(c-d)/e";
    string postfix = infixToPostfix(infix);
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}

