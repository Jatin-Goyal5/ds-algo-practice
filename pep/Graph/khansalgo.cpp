#include<bits/stdc++.h>
using namespace std;


vector<int> khan(vector<vector<int>> &graph , vector<int> indegree){
    
}

bool canFinish(int n, vector<vector<int>>& query) {
    vector<int> indegree(n);
    vector<vector<int>> graph(n, vector<int>());
    for(int i =0 ; i < query.size() ; i++){
        int x = query[i][0];
        int y = query[i][1];
        indegree[y]++;
        graph[y].push_back(x);
    }
    
    vector<int> ans = khan(graph,indegree);
    
    if(ans.size()==0)
        return false;
    return true;
    
}

int main(){
    
    return 0;
}
