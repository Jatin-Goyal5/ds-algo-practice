#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,double> p1 ,pair<int,double>p2){
    return p1.second>p2.second;
}
void knap(vector<int> v,vector<int> w, int tar){
    vector<pair<int,double>> dp;
    
    for(int i =0 ; i < w.size() ; i++){
        double cfrac= (double)v[i]/w[i];
        dp.push_back(make_pair(w[i],cfrac));
    }
    sort(dp.begin(),dp.end(),comp);
    int wt=0;
    double profit=0.0;
    for(int i =0 ; i < dp.size() ; i++){
        for(int j =0 ; j <dp[i].first ; j++ ){
            if(wt < tar){
                wt+=1;
                profit+= (double)dp[i].second;      
            }
        }
    }
   
    cout << fixed << setprecision(1)<<profit;
    
}
int main(){
    int n;
    cin>> n;
    vector<int> v(n),w(n);
    for(int i =0 ; i < n ; i++)
        cin>>v[i];
    for(int i =0 ; i < n ; i++)
        cin>>w[i];
    int tar;
    cin>>tar;
    knap(v,w,tar);
    return 0;
}