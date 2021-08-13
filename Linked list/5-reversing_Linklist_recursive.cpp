#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
struct Node* head;

void insert(Node** head,int data,int pos){

        // inserting data into linked list
        
        Node* temp = new Node();
        temp->data = data;
        temp->next = NULL;
        if(pos ==1){
            temp->next = *head;
            *head = temp;
            return;
        }

        Node* temp1 = *head;
        for(int i=0;i<pos-2;i++){
            temp1 = temp1->next;
        }
        temp->next = temp1->next;
        temp1->next = temp;
        
}


void reversePrint(Node* p){

    //reversing Linked list
    if(p->next == NULL){
        head = p;
        return;
    }
    reversePrint(p->next);
    
    p->next->next = p;
    p->next = NULL;
    
}

void print(Node* temp){
   
    // printing data in the linked list

    while(temp != NULL){
        cout<<"\t"<<temp->data;
        temp = temp->next;
    }
}

int main(){

    head = NULL; //empty linked list in othe beginning

    insert(&head,1,1);
    insert(&head,2,2);
    insert(&head,3,3);
    insert(&head,4,4);
    insert(&head,5,5);
       
    
    // calling reverse operation 
    reversePrint(head);
    cout<<"Linked list after reverse operation";
    print(head);
    


    return 0;
}