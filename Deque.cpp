#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class Deque
{
    Node *head, *tail;
    int size;

public:
    Deque()
    {
        head = tail = NULL;
        size = 0;
    }
    bool empty()
    {
        return size == 0;
    }
    int Size()
    {
        return size;
    }

    int back()
    {
        return tail->data;
    }

    int front()
    {
        return head->data;
    }

    void push_back(int val)
    {
        Node *node = new Node(val);
        size++;

        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        tail->next = node;
        node->prev = tail;

        tail = tail->next;
    }

    void push_front(int val)
    {
        Node *node = new Node(val);
        size++;

        if (head == NULL)
        {
            head = tail = node;
            return;
        }

        node->next = head;
        head->prev = node;

        head = node;
    }

    void pop_back()
    {
        if (size == 0)
            return;

        size--;

        if (size == 0)
        {
            head = tail = NULL;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;

        tail->next = NULL;

        delete temp;
    }

    void pop_front()
    {
        if (size == 0)
            return;

        size--;

        if (size == 0)
        {
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = NULL;

        delete temp;
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Deque a;
    while (true)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            cin >> y;
            a.push_back(y);
        }
        else if (x == 2)
        {
            int y;
            cin >> y;
            a.push_front(y);
        }
        else if (x == 3)
        {
            a.pop_back();
        }
        else if (x == 4)
        {
            a.pop_front();
        }
        else if (x == 5)
            cout << a.back() << endl;
        else if (x == 6)
            cout << a.front();
        else
            a.print();
    }

    return 0;
}
