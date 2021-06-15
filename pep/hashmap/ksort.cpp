// 1. You are given a number n, representing the size of array a.
// 2. You are given n numbers, representing elements of array a.
// 3. The array is nearly sorted. Every element is at-max displaced k spots left or right to it's position in the sorted array. Hence it is being called k-sorted array.
// 4. You are required to sort and print the sorted array.

// Note -> You can use at-max k extra space and nlogk time complexity.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> a(n);
    for(int i=0 ; i < n ; i++)  
        cin>> a[i];
        
    int k;
    cin>> k;
    vector<int> res;
    priority_queue<int,vector<int>,greater<int>> helper;
    for(int i =0 ; i < k+1 ; i++){
        helper.push(a[i]);
    }
    res.push_back(helper.top());
    helper.pop();
    for(int i =k+1 ; i < a.size() ; i++){
        helper.push(a[i]);
        res.push_back(helper.top());
        helper.pop();
    }
    while(helper.size()>0){
        res.push_back(helper.top());
        helper.pop();
    }
    for(int i =0 ; i < res.size() ; i++)
    {
        cout<< res[i]<< endl;
    }
    return 0;
}