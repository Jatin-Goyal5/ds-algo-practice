// Topological sort -> A permutation of vertices for a directed acyclic graph is called topological sort if 
//                     for all directed edges uv, u appears before v in the graph

// dfs traversal


#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int nbr;
    // int wt;
    Edge(int src , int nbr ){
        this->src = src;
        this->nbr = nbr;
        // this->wt = wt;
    }
};

void addEdge(int src , int nbr , vector<vector<Edge>>&v){
    Edge e1=  Edge(src,nbr );
    Edge e2=  Edge(nbr,src);
    v[src].push_back(e1);
    // v[nbr].push_back(e2);
}

// void display(vector<vector<Edge>> graph){
//     for(int v=0; v < graph.size();v++) {
//            cout<<v << " -> ";
//             for(int e=0; e < graph[v].size();e++) {
//                 Edge edge = graph[v].at(e);
//                 cout<<(edge.src)<<" - "<< edge.nbr <<" @ "<<edge.wt <<" , ";
//             }
//             cout<< endl;
//         }

// }
void topologicalHelper(vector<vector<Edge>> graph,int src,vector<int>&res , vector<bool>&visit){
    if(visit[src]){
        return;
    }
    visit[src] = true;

    for(Edge e :graph[src]){
        if(!visit[e.nbr]){
            topologicalHelper(graph,e.nbr,res,visit);
        }
    }
     res.push_back(src);
}
void topological(vector<vector<Edge>> graph ){
    vector<bool> visit(graph.size(),false);
    vector<int> res;
    for(int i =0 ; i < graph.size() ; i++){
        topologicalHelper(graph,i,res,visit);
    }
    for(int i =res.size()-1 ; i>=0 ; i--){
        cout<< res[i]<< endl;
    }
}
int main(){
    int vt, eg;
    cin>> vt>> eg;

    vector<vector<Edge>> graph(vt,vector<Edge>());

    for(int i =0 ; i < eg ; i++){
        int src, dest;
        cin>> src>> dest;
        addEdge(src,dest,graph);
    }    
    
    topological(graph);
}