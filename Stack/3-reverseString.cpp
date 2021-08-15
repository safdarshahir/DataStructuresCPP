#include<iostream>
#include<string>
#include <stack>
using namespace std;

void reverse(string &c){

    stack<char> s;

    for(int i=0;c[i]!='\0';i++){

        s.push(c[i]);

    }

      for(int i=0;c[i]!='\0';i++){
        c[i] = s.top();
        s.pop();
        
    }


}

int main(){

    string c;
    cout<<"Enter a string:";
    getline(cin,c);
    reverse(c);
    cout<<"Reversed String:"<<c;

    return 0;
}