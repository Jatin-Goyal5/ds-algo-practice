#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<int> vi;

vi all_indices(vi a, int x ,int i){
    if(i == a.size()){
         vector<int> v;
        return v;
    }

    vi ans;
    if(a[i] == x){
        
        ans= all_indices(a,x,i+1); 
            
        ans.push_back(i);
        return ans;
    }else{
        ans = all_indices(a,x,i+1);
        return ans;
    }
    
    


}

int main(){
    int t;
    cin>> t;
    vi a(t);
    f(i,0,t)
        cin>> a[i];
    int x;
    cin>> x;

    vi ans = all_indices(a,x,0);
    fr(i,ans.size()-1,0){
        cout<< ans[i]<< " ";
    }
    
    return 0;
}