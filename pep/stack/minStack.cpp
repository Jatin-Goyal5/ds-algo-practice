#include<bits/stdc++.h>
using namespace std;
class customStack{
    public:
    vector<int> st;
    int m =INT_MAX;
   
    void push(int val){
        if(st.size()== 0){
            m = val;
            st.push_back(val);
        }
        else if(val <= m){
            st.push_back(val+(val-m));
            m = val;   
        }else{
            st.push_back(val);
        }
        
    }
    int pop(){
        if(st.size() == 0){
            return -1;
        }
        int k = st[st.size()-1];
        if(k < m){
            int trr = m;
            m = (m+m-k);
            st.pop_back();
            return trr;
        }else{
            st.pop_back();
            return k;    
        }
        
    }
    int min(){
        if(st.size() == 0){
            return -1;
        }
        return m;
    }
    
    int top(){
         if(st.size() == 0){
            return -1;
        }
        int k = st[st.size()-1];
        if(k > m){
            return k;
        }else{
            return m;
        }
    }
    
    int size(){
        return st.size();
    }
    
    void display(){
        for(int i = st.size()-1 ; i >= 0 ; i--)
            cout<< st[i]<< " ";
            cout<< endl;
    }
    
};
int main(){
    customStack stack = customStack();
    string s;
    cin>>s;
    while(s != "quit"){
        // cout<< s<< endl;
        if(s == "push"){
            int a;
            cin>> a;
            stack.push(a);
        }else if(s == "display"){
            stack.display();
        }
        else if(s == "pop"){
            int k = stack.pop();
            // int k = stack.top();
            if(k == -1){
                cout<<"Stack underflow"<<endl;    
            }else{
                cout<< k<< endl;
            }
        }else if(s == "size"){
            cout<< stack.size()<< endl;
        }else if(s == "top"){
            int k = stack.top();
            if(k == -1){
                cout<<"Stack underflow"<<endl;    
            }else{
                cout<< k<< endl;
            }
            
        }else if(s == "min"){
            int k = stack.min();
            if(k == -1){
                cout<<"Stack underflow"<<endl;    
            }else{
                cout<< k<< endl;
            }
            
        }
        cin>>s;
    }
    return 0;
}