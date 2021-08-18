#include<iostream>
#define MAX_SIZE 5

using namespace std;


int QUEUE[MAX_SIZE];
int front = -1,rear = -1;


bool isEmpty(){
    return (front == -1 && rear == -1);
}

int printfront(){

    
    if(isEmpty()){
        cout<<"\nQueue Empty.";
        return -1;
    }
    return QUEUE[front];
    
}
void enqueue(int data){

    if ((rear+1)%MAX_SIZE == front)
    {
        cout<<"Queue Full.";
        return;
    }
    else if (isEmpty()){
        front =0;
        rear = 0;

    }
    else{
        rear= (rear+1)%MAX_SIZE;
    }
    QUEUE[rear]=data;
    
   
    
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
    
        front = (front+1)%MAX_SIZE;

    }


}

int main(){

    char ch;
    int data;
    while(1)
    {
 

     cout<<"\n1.enqueue\n2.dequeue\n3.Print front\n4.Exit\nenter choice:";
     cin>>ch;
     switch(ch){
        case '1':
                    cout<<"Enter data:";
                    cin>>data;
                    enqueue(data);
                    break;
        case '2':dequeue();
                    break;
        case '3':   cout<<printfront();
                    break;
        default:    exit(0);
     }
    }
    

}



