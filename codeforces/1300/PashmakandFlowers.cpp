#include<bits/stdc++.h>
#define int long long int 
using namespace std;

signed main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++)
        cin>> a[i];
    sort(a.begin(),a.end());
    int fcount =0;
    int scount =0;
     for(int i =0 ; i < a.size() ; i++){
            if(a[0] == a[i])
                fcount++;
            else
                break;
        }
        
        for(int i =a.size()-1 ; i >=0 ; i--){
            if(a[a.size()-1] == a[i])
                scount++;
            else
                break;
        }
    if(a[0] != a[a.size()-1]){
        
       
    cout<< a[a.size()-1]- a[0] << " "<< (fcount*scount);
    }else{
        cout<< a[a.size()-1]- a[0] << " "<< (n*(n-1))/2 ;
    }
    

    
    
    return 0;
}