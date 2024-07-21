// implement Stack using linked list

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int x)
    {
        Node *t = new Node;
        if (t == NULL)
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            t->data = x;
            t->next = top;
            top = t;
        }
    }

    int pop()
    {
        int x = -1;
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            Node *t = top;
            top = top->next;
            x = t->data;
            delete t;
        }
        return x;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else
        {
            return top->data;
        }
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};
