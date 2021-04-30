#include<bits/stdc++.h>
#define int long long int 
using namespace std;

signed main(){
    int a,b ,n;
    cin>> a>> b>>n;
    for(int i =0 ; i < 10 ; i++){
        int nno = a*10+i;
        if(nno%b == 0){
            string ans = to_string(nno);
            string zeroes;
            for(int j =0; j < n-1 ; j++){
                   zeroes += "0";
            }
            
            cout<< ans+zeroes;
            return 0;
        }
    }
    cout<<"-1";
    // if(a%b)
    return 0;
}