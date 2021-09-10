#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int u,v,wt;
    Edge(int u , int v, int wt)
    {
        this->u= u;
        this->v =v;
        this->wt = wt;   
    }
};

void bellmanford(vector<vector<Edge>> &graph,int src){

    vector<Edge> traverse;
    for(int i =0 ; i < graph.size() ; i++){
        for(int j =0 ; j < graph[i].size() ; j++){
            Edge e = graph[i][j];
            // in case of undirected graph
            if(i < e.v){
                traverse.push_back(e);
            }
        }
    }  
    // cout<< "ans"<< endl; 
    vector<int> cost(graph.size(),INT_MAX);
    cost[src] = 0; 
    for(int i =0 ; i < cost.size() ; i++)
    for(Edge e :traverse){
        if(cost[e.u] + e.wt < cost[e.v]){
            cost[e.v] = cost[e.u]+e.wt;
        }
    }
    for(int i =1 ; i <graph.size() ; i++ ){
        cout<< cost[i]<<" ";
    }
}
int main(){
    int n,m;
    cin>> n>> m;
    vector<vector<Edge>> graph(n,vector<Edge>());
    for(int i =0 ;i < m ;i++){
        int u,v,wt;
        cin>> u>> v>> wt;
        u--;
        v--;
        graph[u].push_back(Edge(u,v,wt));
        graph[v].push_back(Edge(v,u,wt));
    }
    bellmanford(graph,0);
    return 0;
}