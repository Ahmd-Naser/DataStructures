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

class LinkedList{
    Node *head;

    void printRev(Node *node){
        if(node == NULL)
            return ;
        printRev(node->next);
        cout<<node->data<<' ';
    }

public:
    LinkedList(){
        head = NULL;
    }

    void Insert(int val){
        if(head == NULL){
            head = new Node(val);
            return;
        }
        Node *temp = head ;
        Node *node = new Node(val);

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = node;
    }

    void insertAtBeginning(int val){
        if(head == NULL){
            head = new Node(val);
            return;
        }

        Node *node = new Node(val);

        node->next = head;
        head = node;
    }

    void print(){
        Node *temp = head ;
        while(temp != NULL) {
            cout<< temp->data<<' ';
            temp = temp->next;
        }
        cout<<'\n';
    }

    void printReverse(){
        printRev(head);
        cout<<'\n';
    }


};


int main(){

    LinkedList l;

    l.Insert(1);
    l.Insert(2);
    l.Insert(3);

    l.print();
    l.printReverse();

    return 0;
}