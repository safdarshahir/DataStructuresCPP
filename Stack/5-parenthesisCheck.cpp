#include <iostream>
#include <stack>

using namespace std;

bool checkParenthesis(string &S){

    stack<char> stk;
    char x;
    for(int i=0;S[i]!='\0';i++){

        if(S[i]=='(' || S[i]=='[' || S[i]=='{'){
            stk.push(S[i]);
            continue;
        }

        if(stk.empty()){
            return false;
        }
        
        switch(S[i]){

            case ')':
                x= stk.top();
                stk.pop();
                if(x=='{'||x=='[')
                    return false;
                break;
            case '}':
                x= stk.top();
                stk.pop();
                if(x=='('||x=='[')
                    return false;
                break;
            case ']':
                x= stk.top();
                stk.pop();
                if(x=='{'||x=='(')
                    return false;
                break;
        }

    }

    return stk.empty();
}

int main(){

    string S;
    cout<<"Enter a String:";
    getline(cin,S);
    if(checkParenthesis(S)){
        cout<<"\nParenthesis are balanced.";
    }
    else{
        cout<<"\nParenthesis are not balanced.";
    }
    return 0;
}