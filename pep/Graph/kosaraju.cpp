#include<bits/stdc++.h>
using namespace std;
static stack<int> st;

void dfs(vector<vector<int>> &graph ,vector<bool>& visit, int src){
    if(visit[src] == true){
        return;
    }
    visit[src] =true;
    for(int nbre : graph[src]){
        if(visit[nbre] == false){
            dfs(graph, visit, nbre);
        }
    }
    
    st.push(src);
}

void dfs2(vector<vector<int>> &graph ,vector<bool>& visit, int src){
    if(visit[src] == true){
        return;
    }
    visit[src] =true;
    for(int nbre : graph[src]){
        if(visit[nbre] == false){
            dfs2(graph, visit, nbre);
        }
    }
    
    // st.push(src);
}

int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<int>> graph(n,vector<int>());
    for(int i =0 ; i < m ; i++){
        int u,v;
        cin>> u>> v;
        u = u-1;
        v =v-1;
        graph[u].push_back(v);
        // graph[v].push_back(u);
    }
    
    // apply dfs
    
    vector<bool> visit(n,false);
    
    for(int i =0 ; i < n ; i++){
        if(!visit[i]){
            dfs(graph,visit,i);
        }
    }
    
    // reverse the edges
    vector<vector<int>> revGraph(n,vector<int>());
    for(int i =0 ; i < n ; i++){
        for(int nbr : graph[i]){
            revGraph[nbr].push_back(i);
        }
    }
    // cout<< "2";
    
    
    // now we apply dfs by travelling through stack
    vector<bool> revVisit(n,false);
    int count =0;
    while(st.size()){
        int e = st.top();
        st.pop();
        if(!revVisit[e]){
            dfs2(revGraph,revVisit,e);
            count++;
        }
    }
    
    cout<< count;
    
}