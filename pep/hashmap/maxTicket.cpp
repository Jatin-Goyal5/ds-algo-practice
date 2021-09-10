#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++)
        cin>> a[i];
    sort(a.begin() ,a.end());
    vector<int> len(n,1);
    int maxlen =0;
    for(int i =1 ; i < n; i++){
        if(a[i]== a[i-1]+1 || a[i] == a[i-1])
            len[i] += len[i-1];
        if(len[i] > maxlen)
            maxlen = len[i];
    }
    cout<< maxlen;
    return 0;
}