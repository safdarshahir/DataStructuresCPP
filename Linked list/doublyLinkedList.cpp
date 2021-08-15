#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct Node* head;

struct Node* getNewNode(int data){

    Node* temp = new Node();

    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    return temp;



}

void insertAtHead(int data){

    struct Node* newNode = getNewNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
   
   newNode->data = data;
   head->prev = newNode;
   newNode->next = head;
   head = newNode;

}

void insertAtTail(int data){

    struct Node* newNode = getNewNode(data);
    struct Node* temp = head;
    if(head == NULL){
        head = newNode;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    newNode->data = data;
    newNode->prev = temp;
    temp->next = newNode;


}

void print(){
    Node* temp = head;
    cout<<"\noriginal list:";
    while(temp!=NULL){

        cout<<"\t"<<temp->data;
        temp = temp->next;


    }
}


void printReverse(){
    Node* temp = head;
    cout<<"\nreverse printing list:";
    // going to last node
    while(temp->next!=NULL){
        temp = temp->next;
    }

    while(temp!=NULL){

        cout<<"\t"<<temp->data;
        temp = temp->prev;


    }
}

int main(){

    head =NULL;
    insertAtHead(5);
    insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);

    print();
    printReverse();

    cout<<"\n"<<"linked list after insert at tail";
    insertAtTail(6);
    insertAtTail(7);
    insertAtTail(8);
    print();

    return 0;


}