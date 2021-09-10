// khan's algorithm
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<int>> graph(n,vector<int>());
    vector<int> indegree(n);
    for(int i =0 ; i < m ; i++){
        int u ,v;
        cin>> u>> v;
        graph[v].push_back(u);
        indegree[u]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i =0 ; i < indegree.size() ; i++)
    {
        if(!indegree[i])
            q.push(i);
    }

    while(q.size()){
        int count = q.size();
        while(count--){
            int rem = q.front();
            if(!indegree[rem]){
                ans.push_back(rem);
            }
            q.pop();
            for(int nbr : graph[rem]){
                indegree[nbr]--;
                if(!indegree[nbr])
                {
                    q.push(nbr);
                }
            }
        }
       
        // cout<< rem;

    }

    for(int i :indegree){
        if(i != 0){
            cout<< "-1";
            return 0;
        }
    }
    for(int i :ans){
        cout<< i << " ";
    }
    // for(int i = ans.size()-1 ; i>= 0 ; i--){
    //     cout<< ans[i] << " ";
    // }
    
    return 0;
}