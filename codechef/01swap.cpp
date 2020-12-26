#include<bits/stdc++.h>
using namespace std;

void test(){
    int n;
    cin>>n;
    string s,p;
    cin>> s;
    cin>> p;
    int s0 =0, s1 =0, p0 =0 , p1 =0;
    for(int i =0 ; i < s.length() ; i++){
        if(s[i] == '0')
            s0++;
        if(s[i] == '1')
            s1++;
        if(p[i] == '0')
            p0++;
        if(p[i] == '1')
            p1++;
        
    }

    if(s0 == p0 && s1 == p1){
        cout<< "YES" << endl;
    }else
    {
        cout<<"NO"<< endl;
    }
    
}
int main(){
    int t=1;
    cin>> t;
    while (t--)
    {
        test();
        
    }

    return 0;
}