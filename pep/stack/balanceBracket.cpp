#include<bits/stdc++.h>
using namespace std;


void balance(string s){
    //algo
    // if open bracket simply push in stack
    // if closing bracket check stack is empty or top has not its pair then print false and return
    // otherwise pop it and continue because stack top must have its pair on its top  


    stack<char> st;
    
    for(int i = 0 ; i < s.length() ; i++){
        char ch = s[i];
        if(ch == '{' || ch == '(' || ch == '['){
            st.push(ch);        
        }else if (ch == ')') {
            if (st.size() == 0 || st.top() != '(') {
                cout<< "false"<< endl;
                return;
            }
            else {
                st.pop();
            }
        } else if (ch == '}') {
            if (st.size() == 0 || st.top() != '{') {
                cout<< "false"<< endl;
                return;
            }
            else {
                st.pop();
            }
        } else if (ch == ']') {
            if (st.size() == 0 || st.top() != '[') {
                cout<< "false"<< endl;
                return;
            }
            else {
                st.pop();
            }
        }
        
    
    }
    
    if(st.size() == 0){
        cout<< "true"<< endl;
    }else{
        // cout<<"@^@";
        cout<< "false"<< endl;
    }
    
}

int main(){
    string s;
    // cin>> s;
    getline(cin,s);
    balance(s);
    return 0;
    
}