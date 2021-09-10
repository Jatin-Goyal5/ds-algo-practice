#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    unordered_map<int, int> mp;
    mp[0] =-1;
    int sum =0,maxlen =0;
    for(int i =0 ; i < n ; i++){
        int x;
        cin>> x;
        if(x ==0)
            x = -1;
        sum+= x;
        if(mp.find(sum) != mp.end()){
            int len = i -mp[sum];
            if(len > maxlen)
                maxlen= len;
        }else{
            mp[sum] = i;
        }
        
    }
    cout<< maxlen<< endl;
    return 0;
}