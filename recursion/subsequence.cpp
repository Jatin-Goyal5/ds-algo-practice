#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<string> vi;

vi subsequence(string s , int p){
    if(p == s.length()-1){
        vi v;
        v.push_back("");
        return v;
    }else if(p > s.length())
    {
        vi v;
        return v;
    
    }

    vi ans;
    ans = subsequence(s,p+1);
    for(int i =0 ; i < ans.size() ; i++){
        ans.push_back(ans[i]);
        ans.push_back(s[p]+ans[i]);
    }

    return ans;
    
}


int main(){
    string s;
    cin>> s;

    vi ans =subsequence(s,0);
    for(int i =0 ;  i< ans.size() ; i++)
        cout<< ans[i]<<" ";


    return 0;
}
