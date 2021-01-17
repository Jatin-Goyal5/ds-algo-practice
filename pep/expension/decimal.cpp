#include<bits/stdc++.h>
using namespace std;
string digit(int n1,int n2,int b){
    string ans ="";
    int ca=0;
    while(n1 >0 || n2 > 0 || ca>0){
        int r1 = n1%10;
        int r2 = n2%10;
        int s = r1+r2+ca;
        //cout<< s-b;
        if(s >= b){
            int k = s-b;
           ans =to_string(k)+ans; 
           ca =1;
        }else{
            ans = to_string(s)+ans;
            ca =0;
        }
        n1 /=10;
        n2 /=10;
        
    }
   