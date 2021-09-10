#include<bits/stdc++.h>
using namespace std ;
int main(int argc ,char **argv){
    string s="";
    getline(cin,s);
    stack<char> st;
    for(char i : s){
        if(i ==')'){
            if(st.top() == '('){
                cout<< "true"<< endl;
                return 0;
            }else{
                while(st.top() != '('){
                    st.pop();
                }
                st.pop(); 
            }
        }else{
        st.push(i);
        }
    }
    cout<< "false"<< endl;
    return 0;
}