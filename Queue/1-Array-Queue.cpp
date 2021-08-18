#include<iostream>
#define MAX_SIZE 10

using namespace std;


int QUEUE[MAX_SIZE];
int front = -1,rear = -1;


bool isEmpty(){
    return (front == -1 && rear == -1);
}

void printQueue(){

    
    if(isEmpty()){
        cout<<"\nQueue Empty.";
        return;
    }
    cout<<"\nQueue:";
    for(int i = front; i <= rear; i++){
        cout<<"\t"<<QUEUE[i];
    }
}
void enqueue(int data){

    if (rear == MAX_SIZE-1)
    {
        cout<<"Queue Full.";
        return;
    }
    else if (isEmpty()){
        front =0;
        rear = 0;

    }
    else{
        rear++;
    }

    QUEUE[rear] = data;
    cout<<"\nqueue after enqueue:";
    printQueue();
    
}

void dequeue(){

    if(isEmpty()){
        cout<<"Queue Empty.";
        return;
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
    front++;

    }
    cout<<"\nqueue after dequeue:";
    printQueue();

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



