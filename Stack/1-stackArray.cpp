#include <iostream>
#define MAX_SIZE 101
using namespace std;

int stack[MAX_SIZE];
int top = -1;


void push(int data){
    if(top == MAX_SIZE-1){
        cout<<"Stack overflow";
        return;
    }
    cout<<"\nPushing: "<<data;
    stack[++top] = data;
}

void pop(){
    if(top == -1){
        cout<<"\nStack underflow";
        return;
    }
    cout<<"\nPopping: "<<stack[top--];

}

void printTop(){

    cout<<"\n Current Top: "<<stack[top];

}

void printstack(){

    cout<<"\n Stack: "<<stack[top];
    for(int i =0;i<top;i++){
        cout<<"\t"<<stack[i];
    }
    

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


}