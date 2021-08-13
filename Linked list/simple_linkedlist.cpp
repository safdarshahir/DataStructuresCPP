#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};
struct Node* head;

Node* insert(Node** head,int data){

        // inserting data into linked list
        
        Node* temp = new Node();
        temp->data = data;
        temp->next = *head;
        *head = temp;
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
    int data;
    char ch;
    do
    {
        cout<<"Enter data:";
        cin>>data;
        cout<<"\n";
        
        insert(&head,data);
        cout<<"Current state of Linked list:";
        print(head);

        cout<<"\n";
        cout<<"continue:";
        cin>>ch;


    } while (ch != 'n');
    
   

    return 0;
}