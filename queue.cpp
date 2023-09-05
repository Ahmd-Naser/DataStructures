#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

	Node()
	{
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class Queue
{
	Node *head, *tail;
	int size;

public:
	Queue()
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
	void push(int val)
	{
		Node *node = new Node(val);
		size++;

		if (head == NULL)
		{
			head = tail = node;
			return;
		}

		tail->next = node;
		tail = node;
	}

	void pop()
	{
		if (size == 0)
			return;

		if (size == 1)
		{
			head = tail = NULL;
			size--;
			return;
		}

		Node *temp = head;
		head = head->next;

		delete temp;

		size--;
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

	// cout<<"queue"<<endl;
	Queue a;
	for (int i = 0;; i++)
	{

		// cout<<"1 for push \n 2 for pop \n 3 for print"<<endl;

		int x;
		cin >> x;
		// cout<<x+1<<endl;
		if (x == 1)
		{
			int y;
			cin >> y;
			a.push(y);
		}
		else if (x == 2)
		{
			a.pop();
		}
		else if (x == 3)
		{
			cout << "size : " << a.Size() << endl;
		}
		else if (x == 4)
		{

			cout << "the queue is " << (a.empty() ? "" : "not ") << "empty" << endl;
		}
		else
			a.print();
	}

	return 0;
}