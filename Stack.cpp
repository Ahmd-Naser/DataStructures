#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node{
public :
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
    Node *head;
    int size ;

public:
    Stack(){
        head = NULL;
        size = 0;
    }

    int top(){
        return head->data;
    }

    int Size(){
        return size;
    }

    bool empty(){
        return size == 0;
    }

    void push(int val){
        size++;
        if(head == NULL){
            head = new Node(val);
            return;
        }

        Node *node = new Node(val);

        node->next = head;
        head = node;
    }

    void pop(){
        if(size == 0)
            return;

        size--;
        Node *temp1 = head;
        head = temp1->next;
        delete temp1;

    }

};


int main(){

    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);


    return 0;
}