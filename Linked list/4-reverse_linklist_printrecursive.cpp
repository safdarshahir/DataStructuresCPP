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


void reversePrint(Node* head){

    //reversing Linked list
    if(head == NULL){
        return;
    }
    reversePrint(head->next);
    cout<<"\t"<<head->data;
    
}

int main(){

    struct Node* head = NULL; //empty linked list in othe beginning

    insert(&head,1,1);
    insert(&head,2,2);
    insert(&head,3,3);
    insert(&head,4,4);
    insert(&head,5,5);
       
    
    // calling reverse operation 
    reversePrint(head);


    return 0;
}