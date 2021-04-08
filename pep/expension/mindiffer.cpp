#include<bits/stdc++.h>
using namespace std;
void ans(vector<int> a, vector<int> b){
     int sum= 0 ;
    for (int i=0; i<a.size(); i++)
        sum = sum + abs(a[i]-b[i]);

    // cout<< sum;
    int minans= INT_MAX;
    for(int i =0 ; i < a.size() ; i++){
        for(int j =0 ; j < a.size() ; j++){
            int res = abs((sum-a[i])-a[j]);
            minans = min(minans,res);
            // cout<< res;
        }
    }
    cout<< minans;
}
int main(){
    int n;
    cin>> n;
    vector<int> a(n),b(n);
    for(int i =0 ; i < n ; i++){
        cin>> a[i];
    }
    for(int i =0 ; i < n ; i++){
        cin>> b[i];
    }
    ans(a,b);
    return 0;
}