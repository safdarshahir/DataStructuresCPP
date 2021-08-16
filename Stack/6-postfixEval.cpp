#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isoperator(char c){

    if(c == '+' || c == '-' || c == '/'|| c == '*'){
        return true;
    }
    else{
        return false;
    }
}

int eval(int op1, int op2,char c){

    switch(c){
        case '+': return op1+op2; 
        case '-': return op1-op2;
        case '/': return op1/op2;
        case '*': return op1*op2;
    
    }
} 

int posteval(string s){

    stack<char> Stack;

    for(int i = 0; i < s.length();i++){

        if(!isoperator(s[i])){
            Stack.push((s[i]-'0'));
            continue;
        }

        int op2 = Stack.top();
        Stack.pop();

        int op1 = Stack.top();
        Stack.pop();
        
        Stack.push(eval(op1,op2,s[i]));

    }

    return Stack.top();

}

int main(){

    string str;

    cout<<"\nEnter postfix Expression:";
    getline(cin,str);

    cout<<"\nPostfix evaluation:"<<posteval(str);

    return 0;
    
}