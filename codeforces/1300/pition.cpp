#include<bits/stdc++.h>
using namespace std;

void test(int n){
    cout<< "real"<<" ";
int a=__gcd(100,n);
cout<<100/a<< endl;

}

int main(){
    int t;
    cin>> t;
    while(t--){
        int k;
        cin>> k;
        bool check = false;
       
        for(int i =1 ; i <=100 ; i++){
            if(100%i ==0 && 100/i == k){
                cout<< i << endl;
                check =true;
                break;
            }
        }
        if(!check){
            cout<< "100"<< endl;
        }
        test(k);
    }
    return 0;
}