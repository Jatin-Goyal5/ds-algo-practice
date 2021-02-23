#include<bits/stdc++.h>
using namespace std;
int count(int n){
    if(n == 0 ){
        return 0;
    }
    int a =1,b=1;
    for(int i =1 ; i <n; i++)
    {
        int c=a+b;
        a=b;
        b = c;
    }
    return a+b;
}
int main(){
    int n;
    cin>> n;
    cout<< count(n);
    
}