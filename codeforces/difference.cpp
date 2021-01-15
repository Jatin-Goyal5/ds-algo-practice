#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<int> vi;
int main(){
    int t;
    cin>> t;
    while (t--)
    {
        int n;
        cin>> n;
        vi a(n);  
        f(i,0,n)
            cin>> a[i];
        vi d(51);
        for(int i=0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                d[a[j]-a[i]]++;
            }
        }  
        int c=0;
        for(int i =0 ; i < d.size() ; i++){
            //cout<< d[i];
            if(d[i] > 0)
                c+= d[i]-1;
        }
        cout<< ((n*(n-1))/2)-c<< endl;
    }
    

    return 0;
}