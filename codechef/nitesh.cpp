#include<bits/stdc++.h>
// #define int long long unsigned int
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    int s=0;
    for(int i =0 ; i < n ; i++){
        cin>> a[i];
        s+= a[i];
    }

    for(int i =2 ; i <= n ; i++){
        int csum =0;
        for(int j =0 ; j <= n-i ; j++){
            
            int maxno = INT_MIN;
            for(int k =0 ; k < i && j+k < n; k++){
                maxno=max(maxno,a[j+k]);
            }
            // cout<< maxno << " ";
            csum+=maxno;
        }
        // cout<< endl;
        s += (csum*i);
    }
    cout<< s;
    return 0;
}