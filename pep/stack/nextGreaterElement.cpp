#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreater(vector<int> a){
    int n = a.size();
    vector<int> ans(n);
    ans[n-1] =-1;    
    stack<int> st;
    st.push(a[n-1]);
    for(int i = ans.size()-2 ; i >=0 ; i--){
        while(st.size() > 0 && st.top() <= a[i]){
            st.pop();
        }
        if(st.size()== 0){
            ans[i] = -1;
        }else{
            ans[i] = st.top();
        }
        st.push(a[i]);
    }
   
    return ans;

}
int main(int argc ,char **argv){
    int n;
    cin>> n;
   vector<int> arr(n);
    for(int i=0 ; i < n ;i++){
        cin>> arr[i];
    }

 
vector<int> ans = nextGreater(arr);
    for(int i =0 ; i < n ; i++)
        cout<< ans[i]<< endl;
    return 0;
}