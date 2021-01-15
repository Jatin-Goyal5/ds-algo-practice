#include<bits/stdc++.h>
using namespace std;
int nques(int n){
    int fv =0;
    int ans=0;
    while (n)
    {
        int r= n%10;
        fv++;
        ans = ans+ fv*pow(10,r-1);
        n /=10;        
    }
    cout<< ans;
    
}
int main(){
    int n;
    cin>> n;
    int temp =n;
    int cod =0;
    while (temp!=0)
    {
        temp /=10;
        cod++;
    }

    int mpow = pow(10,cod-1);
    int ans=0;
    int p=1;
    while (n!=0)
    {
        int r= n%10;
        n /= 10;
        if(p==1){
            ans = ans +r*mpow;
        }else if(p == mpow){
            ans= ans+r;
        }else
        {
            ans = ans +r*p;
        }
        
        p *= 10;
    }
    cout<< ans;
    return 0;
    
}