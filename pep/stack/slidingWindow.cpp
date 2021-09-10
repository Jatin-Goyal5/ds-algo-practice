#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++)
        cin>> a[i];
    int k;
    cin>> k;
    stack<int> st;
    st.push(a.size()-1);
    vector<int> ngi(n);
    ngi[n-1] = a.size();
    for(int i = a.size()-2 ; i >= 0 ; i--){
        while(st.size() > 0 && a[i] >= a[st.top()]){
            st.pop();
        } 
        if(st.size() == 0){
            ngi[i] = n;
        }else{
            ngi[i] = st.top();
        }
        st.push(i);
    }
    
    int j =0;
    for(int i =0 ; i <= a.size()-k ; i++){
        if(j < i){
            j =i;
        }
        while(ngi[j] < i+k ){
            j = ngi[j];
        }
        cout<< a[j]<<endl;
    }
    return 0;
}