#include<bits/stdc++.h>
using namespace std;
int precedence(char ch){
    if(ch == '+' || ch == '-'){
        return 1;
    }else if(ch == '*' || ch == '/'){
        return 2;
    }
    return 0;
}
string solvePre(string s1 ,string s2 , char ch){
    string c= "";
    c+= ch;
    // cout<< c+s1+s2<< " ";
    return c+s1+s2;
}
string solvePost(string s1 ,string s2 , char ch){
    string c;
    c+= ch;
    return s1+s2+c;
}
int main(){
    string s;
    getline(cin,s);
    stack<string> pre,post;
    stack<char> operation;
    for(int i =0 ; i < s.length() ; i++){
        char ch = s[i];
        if(ch == '*' || ch == '/' || ch == '+' || ch == '-'){
            while(operation.size() > 0 && operation.top() != '(' && precedence(operation.top()) >= precedence(ch)){
                             string pr2= pre.top();
                pre.pop();
                string pr1= pre.top();
                pre.pop();
                char op = operation.top();
                operation.pop();
                string npre = solvePre(pr1,pr2,op);
                pre.push(npre);
                
                string po2= post.top();
                post.pop();
                string po1= post.top();
                post.pop();
                string npos = solvePost(po1,po2,op);
                post.push(npos);
            }
            operation.push(ch);
            
        }else if(ch == '('){
            operation.push(ch);
            
        }else if(ch == ')'){
            while(operation.top() != '('){
                             string pr2= pre.top();
                pre.pop();
                string pr1= pre.top();
                pre.pop();
                char op = operation.top();
                operation.pop();
                string npre = solvePre(pr1,pr2,op);
                pre.push(npre);
                
                string po2= post.top();
                post.pop();
                string po1= post.top();
                post.pop();
                string npos = solvePost(po1,po2,op);
                post.push(npos);
            }
            operation.pop();
        }else if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            string str="";
            str+= ch;
                pre.push(str);
                post.push(str);
            }
    }
    
    while(operation.size()> 0){
                string pr2= pre.top();
                pre.pop();
                string pr1= pre.top();
                pre.pop();
                char op = operation.top();
                operation.pop();
                string npre = solvePre(pr1,pr2,op);
                pre.push(npre);
                
                 string po2= post.top();
                post.pop();
                string po1= post.top();
                post.pop();
                string npos = solvePost(po1,po2,op);
                post.push(npos);
    }
            cout<< post.top()<< endl;
            cout<< pre.top();
    return 0;
}