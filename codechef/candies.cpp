#include<bits/stdc++.h>
using namespace std;
void test(){
    int n,c;
    cin>> n >> c;
    int mina = INT_MAX, maxa =INT_MIN;
    for(int i =0 ; i < n ; i++)
    {
        int x;
        cin>> x;
        mina = min(mina,x);
        maxa = max(maxa,x);

    }

    if(maxa-mina < c){
        cout<<"YES"<< endl;
    }else
    {
        cout<< "NO"<< endl;
    }
    
    
}
int main(int argc ,char **argv){
    int t;
    cin>> t;
    while (t--)
    {
        test();
    }
    
    return 0;
}