#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<int> vi;

void target_sum(vi a, int target){
    vector<vi> dp(a.size()+1,vi(target+1));
    dp[0][0] =1;
    f(i,0,dp.size()){
        f(j,0,dp[0].size()){
            if(i == 0 && j == 0)
        }
    }

}


int main(){
    int n;
    cin>> n;
    vi a(n);
    f(i,0,n)
        cin>> a[i];
    int target = 0;
    cin>> target;
    

}