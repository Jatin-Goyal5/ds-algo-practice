
// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers, representing n elements.
// 3. You are required to find the maximum sum of a subsequence with no adjacent elements.
#include<bits/stdc++.h>
using namespace std;
int profit(vector<int> a){
    
    int inc= a[0];
    int exc= 0;
    for(int i =1 ; i < a.size() ; i++){
        int ninc = exc+a[i];
        int nexc = max(inc,exc);
        inc = ninc;
        exc= nexc;
    }
    
    return max(exc,inc);
}
int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    for(int i =0 ; i < a.size() ; i++)
        cin>> a[i];
        
       cout<< profit(a);
    
    return 0;
}