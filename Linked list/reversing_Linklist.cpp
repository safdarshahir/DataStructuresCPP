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


void reverse(Node** head){

        //reversing Linked list

        struct Node* current,*next,*prev;
        current = *head;
        prev = NULL;

        while(current != NULL){
            
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        }

        *head = prev;


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
    
    // calling reverse operation 
    reverse(&head);
    cout<<"Linked list after reverse operation";
    print(head);

    return 0;
}