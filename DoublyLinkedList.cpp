#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Node{
public :
    int data;
    Node *next;
    Node *prev;

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList{
    Node *head;
    int size;

    bool valid(int n){
        return n>=1 && n<=size;
    }

public :

    DoublyLinkedList(){
        head = NULL;
        size = 0;
    }

    void Insert(int val){
        Node *newNode = new Node(val);
        size++;
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void InsertAtHead(int val){
        Node *newNode = new Node(val);
        size++;
        if(head == NULL){
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    void print(){
        Node *temp = head ;
        while(temp != NULL) {
            cout<< temp->data<<' ';
            temp = temp->next;
        }
        cout<<'\n';
    }

    void ReversePrint(){
        Node *temp = head;
        if(temp == NULL)
            return;
        while(temp->next != NULL)
            temp = temp->next;

        while (temp != NULL){
            cout<<temp->data<<' ';
            temp = temp->prev;
        }
        cout<<'\n';
    }

    void Delete(int n) {
        if(!valid(n))
            return ;

        size--;

        if(n == 1) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;

        for(int i=1;i<n;i++){
            temp = temp->next;
        }

        Node *prev = temp->prev;
        Node *next = temp->next;

        prev->next = next;
        next->prev = prev;

        delete temp;

    }
};


int main(){

    return 0;
}