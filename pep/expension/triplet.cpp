#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>> a >> b>> c;
    int sa = pow(a,2);
    int sb = pow(b,2);
    int sc = pow(c,2);

    if(sa+sb == sc){
        cout<< "true";
    }else if(sb+sc == sa)
        cout<< "true";
    else if(sc+sa == sb)
        cout<< "true";
    else
        cout<< "false";
    return 0;
    

}