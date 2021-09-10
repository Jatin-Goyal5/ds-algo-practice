#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    unordered_map<int,int> mp;
    int count = 0;
    int sum =0;
    for(int i =0 ; i < n ; i++){
        int x;
        cin>> x;
        sum += x;
        if(mp.find(sum) != mp.end()){
            count+= mp[sum];
        }
        mp[sum]++;
    }
    cout<< count;
    return 0;
}