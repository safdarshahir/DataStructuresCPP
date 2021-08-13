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


void del(Node** head,int pos){

        //deleting  data from linked list

        Node* temp1 = *head;
        if(pos == 1){
            *head = temp1->next;
            delete temp1;
            return;

        }
        for(int i=0;i<pos-2;i++){
            temp1 = temp1->next;
        }

        Node* temp = temp1->next;
        temp1->next = temp->next;
        delete temp;
        
}

void print(Node* temp){
   
    // printing data in the linked list

    while(temp != NULL){
        cout<<"\t"<<temp->data;
        temp = temp->next;
    }
}
int main(){

    struct Node* head = NULL; //empty linked list in othe beginning
    int data,pos;
    char ch;

    do
    {
        cout<<"Enter data and position:";
        cin>>data>>pos;

        cout<<"\n";
        
        insert(&head,data,pos);
        cout<<"Current state of Linked list:";
        print(head);

        cout<<"\n";
        cout<<"continue:";
        cin>>ch;


    } while (ch != 'n');
    
    // calling deletion operation 
    cout<<"Enter position to delete:";
    cin>>pos;
    del(&head,pos);
    cout<<"Linked list after deletion operation";
    print(head);

    return 0;
}