#include<bits/stdc++.h>
#define f(i,a,b) for(int i =a ; i < b ; i++)
#define fr(i,a,b) for(int i = a; i>=b ; i--)
using namespace std;
typedef vector<int> vi;

int max_array(vi a, int i ){
    if(a.size()-1 == i){
        return INT_MIN;
    }
    
    int max1= max_array(a,i+1);
    return max(max1,a[i]);

}

int main(){
    int t;
    cin>> t;
    vi a(t);
    f(i,0,t)
        cin>> a[i];

    cout<< max_array(a,0);
    
    return 0;
}