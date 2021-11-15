#include<bits/stdc++.h>
using namespace std;
class customStack{
    public:
    int s;
    vector<int> st;
    
    customStack(int size){
        this->s = size;
    }
    void push(int val){
        if(st.size() >= s){
            cout<< "Stack overflow"<< endl;
            return;
        }
        st.push_back(val);
    }
    int pop(){
        if(st.size() == 0){
            // cout<< "Stack underflow"<< endl;
            return -1;
        }
        int k = st[st.size()-1];
        st.pop_back();
        return k;
    }
    
    int top(){
         if(st.size() == 0){
            return -1;
        }
        int k = st[st.size()-1];
        // st.pop_back();
        return k;
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
    int n;
    cin>> n;
    customStack stack = customStack(n);
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
            
        }
        cin>>s;
    }
    return 0;
}