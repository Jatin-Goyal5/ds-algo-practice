#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& a, int n) 
{
    // code here 
    stack<int> st;
for(int i =0 ; i < n ; i++)
    st.push(i);
while(st.size() >= 2){
    int f = st.top();
    st.pop();
    int s = st.top();
    st.pop();
    if(a[f][s]){
        st.push(s);
    }else{
        st.push(f);
    }
}
int c = st.top();
st.pop();
for(int i =0 ; i < a.size() ; i++){
    if(i != c){
        if(a[i][c] == 0 || a[c][i] ==1 ){
            // cout<< "none"<< endl;
            return -1;
        }
    }
}
return c;
}

int main(){
    int n;
    cin>> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i =0 ; i < n ; i++)
        for(int j =0 ; j < n ; j++)
            cin>> a[i][j];
    celebrity(a,n);
    return 0;
}