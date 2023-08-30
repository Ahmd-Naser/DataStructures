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
    int size ;

    void printRev(Node *node){
        if(node == NULL)
            return ;
        printRev(node->next);
        cout<<node->data<<' ';
    }

public:
    LinkedList(){
        head = NULL;
        size = 0;
    }

    int Size(){
        return size;
    }

    void Insert(int val){
        size++;
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
        size++;
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

    void Delete(int n){
        if(n>size)
            return;

        Node *temp1 = head;
        if(n == 1){
            head = temp1->next;
            delete temp1;
            return ;
        }
        for(int i=2;i<n;i++)
            temp1 = temp1->next;

        Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }

    void Reverse(){
        Node *current , *prev , *next;
        current = head;
        prev = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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