#include <iostream>
using namespace std;

struct Node{

    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty(){
    return (front == NULL && rear == NULL);
}
void enqueue(int data){

    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if(front == NULL && rear == NULL){
        front= rear= temp;
        return;
    }

    rear->next = temp;
    rear = temp;

}

void dequeue(){


    Node* temp = front;
    if(front == NULL){
        return;

    }
    else if (front == rear){
        front = rear = NULL;
        }

else{
     front = front->next;
}   
   
    delete(temp);
}

int main(){

    char ch;
    int data;
    while(1)
    {
 

     cout<<"\n1.enqueue\n2.dequeue\n3.Exit\nenter choice:";
     cin>>ch;
     switch(ch){
        case '1':
                    cout<<"Enter data:";
                    cin>>data;
                    enqueue(data);
                    break;
        case '2':dequeue();
                    break;
        default:    exit(0);
     }
    }
    

}