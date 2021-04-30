#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector <int> freq(100001);
    vector<int> index(100001);
    vector<int> ans(100001),check(100001);
    int size=0;

    for(int i =1 ; i <= n ; i++){
        int x;
        cin>> x;
        freq[x]++;
        if(index[x] ){
        if(freq[x]== 2){
            ans[x] = i-index[x];
            // cout<< ans[x];
        } 
         if(ans[x]+index[x] != i){
                check[x] =1;
          }
        
        }
        index[x]=i;

    }
    for(int i = 1 ; i < check.size() ; ++i){
        if(!check[i] && freq[i]){
            size++;
        }
    } 
    cout<< size<< endl;
    for(int i = 1 ; i < check.size() ; ++i){
        if(!check[i] && freq[i]){
            cout<< i<< " "<< ans[i]<< endl;
        }
    }   
//     8
//     1 2 1 3 1 2 1 5
//     1 i
    return 0;
}