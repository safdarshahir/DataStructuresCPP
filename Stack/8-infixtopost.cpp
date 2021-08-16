#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isoperator(char c){

    if(c == '+' || c == '-' || c == '/'|| c == '*'|| c == '^'){
        return true;
    }
    else{
        return false;
    }
}

int precedence(char c){

    if(c == '^'){
        return 3;
    }
    if(c == '/' || c == '*'){
        return 2;
    }
    return 1;
}

bool checkPrecedence(char top,char exp){

    if(precedence(top)>=precedence(exp)){
        return true;

    }return false;

}

bool isopeningParenthesis(char c){
    if(c == '(') return true;
    return false;
}

string toPostfix(string s){

    stack<char> Stack;
    string result;
    for(int i = 0; i <s.length(); i++){

        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            
            result += s[i];
            continue;
        }
        else if(isoperator(s[i])){
            while (!Stack.empty() && !isopeningParenthesis(Stack.top()) && checkPrecedence(Stack.top(),s[i]))
            {
                result += Stack.top();
                Stack.pop();
            }
            
            Stack.push(s[i]);
        }
        else if(isopeningParenthesis(s[i])){
            Stack.push(s[i]);
        }
        else if(s[i]==')'){

            while (!Stack.empty() && !isopeningParenthesis(Stack.top()))
            {
                result += Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }

    }
    while(!Stack.empty()){
        result += Stack.top();
        Stack.pop();
    }

    return result;

}

int main(){

    string str;

    cout<<"\nEnter infix Expression:";
    getline(cin,str);

    cout<<"\nPostfix expression:"<<toPostfix(str);

    return 0;
    
}