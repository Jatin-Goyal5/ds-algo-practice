#include<bits/stdc++.h>
using namespace std;
long count(int n){
    if(n == 0 ){
        return 0;
    }
    long a =1,b=1;
    for(int i =1 ; i <n; i++)
    {
        long c=a+b;
        a=b;
        b = c;
    }
    long ans = a+b;
    return ans*ans;
}
int main(){
    int n;
    cin>> n;
    cout<< count(n);
    
}