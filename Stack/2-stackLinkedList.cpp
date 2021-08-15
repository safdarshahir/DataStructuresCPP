#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};
struct Node* top = NULL;

void push(int data){

        // pushing data into linked list
        
        Node* temp = new Node();
        temp->data = data;
        temp->next = top;
        top = temp;
}

void pop(){

    Node* temp ;
    if(top ==NULL){
        return;
    }
    temp = top;
    top = top->next;
    free(temp);

}

void printstack(){
   
    // printing data in the linked list
    Node* temp = top;
    cout<<"\nStack:";
    while(temp != NULL){
        cout<<"\t"<<temp->data;
        temp = temp->next;
    }
}

void printTop(){
    
    cout<<"\nTop: "<<top->data;
}


int main(){



    push(5);
    printstack();
    push(4);
    printstack();
    push(3);
    printstack();
    push(2);
    printstack();
    pop();
    printstack();
    pop();
    printstack();

    printTop();




    return 0;
}