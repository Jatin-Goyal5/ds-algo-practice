#include<bits/stdc++.h>

using namespace std;

int  main(){

int x,n ,m;
cin>> x>> n >> m;

    if(m > n){
        cout<<"NO";
        return 0;
    }else{
        if(x%2 == 0){
            if(m%2==0){
                cout<<"YES";
                return 0;
            }else{
                cout<< "NO";
                return 0;
            }
        }else{
            cout<<"YES";
            return 0;
        }
    }
}

