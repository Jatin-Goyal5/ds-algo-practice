#include<bits/stdc++.h>
using namespace std;
int solve(int v1, int v2 , char opr){
    if(opr == '+') {
            return v1+v2;
        }
        else if(opr == '/') {
            return v1/v2;
        }
        else if(opr == '*') {
            return v1*v2;
        }
        else if(opr == '-') {
            return v1-v2;
        }
        else {
            return 0;
        }
}

int precedence(char opr){
   if(opr == '+' || opr == '-') {
            return 1;
        }
        else if(opr == '*' || opr == '/') {
            return 2;
        }
        else {
            return 0;
        }  
}

int main(){
    string s;
    getline(cin,s);
    // cout<< s;
    stack<int> val;
    stack<char> operation;
    for(int i =0 ; i < s.length() ; i++){
        char ch = s[i];
        if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
            while(operation.size() > 0 && operation.top() != '(' && precedence(operation.top()) >= precedence(ch)){
                int b = val.top();
                val.pop();
                int a = val.top();
                val.pop();
                char op = operation.top();
                operation.pop();
                int nv = solve(a,b,op);
                val.push(nv);
            }
            operation.push(ch);
            
        }else if(ch == '('){
            operation.push(ch);
            
        }else if(ch == ')'){
            while(operation.top() != '('){
                int b = val.top();
                val.pop();
                int a = val.top();
                val.pop();
                char op = operation.top();
                operation.pop();
                int nv = solve(a,b,op);
                val.push(nv);
            }
            operation.pop();
        } 
    }
    
    while(operation.size()> 0){
        int b = val.top();
        val.pop();
        int a = val.top();
        val.pop();
        char op = operation.top();
        operation.pop();
        int nv = solve(a,b,op);
        val.push(nv);
    }
    cout<< val.top();
    
    return 0;
}