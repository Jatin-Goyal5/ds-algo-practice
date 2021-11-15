#include<bits/stdc++.h>
using namespace std;
int operation(char opr,int v1,int v2) {
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
int main(){
    string s;
    getline(cin,s);
    stack<int> st;
    stack<string> infix,pre;
    for(char ch : s){
        if(ch == '*' || ch == '-' || ch == '+' || ch == '/'){
            int f = st.top();
            st.pop();
            int s = st.top();
            st.pop();
            
            st.push(operation(ch,s,f));
            string in2 = infix.top();
            infix.pop();
            string in1 = infix.top();
            infix.pop();
            string inf = "("+in1+ch+in2+")";
            infix.push(inf);
            
            string pre2 = pre.top();
            pre.pop();
            string pre1 = pre.top();
            pre.pop();
            string p ;
            p+=ch;
            p+=pre1+pre2;
            pre.push(p);
            
        }else if(ch >= '0' && ch <='9'){
            int nv = ch-'0';
            st.push(nv);
            string str= "";
            str+= ch;
            infix.push(str);
            pre.push(str);
        }
    }
    cout<< st.top()<< endl;
    cout<< infix.top()<<endl;
    cout<< pre.top()<< endl;
    
    return 0;
}