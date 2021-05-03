#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int nbr;
    
    Edge(int src , int nbr){
        this->src = src;
        this->nbr = nbr;
      
    }
};

void hasPath(vector<vector<Edge>>v ,int src , int dest, vector<bool>&visit){
    // if(src == dest){
    //     return true;
    // }
    visit[src] = true;
    for(Edge e:v[src]){
        if(visit[e.nbr]== false){
            hasPath(v,e.nbr,dest,visit);
            cout<< e.nbr;
           
        }
    }

}


void addEdge(int src , int nbr , vector<vector<Edge>>&v){
    Edge e1=  Edge(src,nbr);
    Edge e2=  Edge(nbr,src);
    v[src].push_back(e1);
    // v[nbr].push_back(e2);
}

void getall(vector<vector<Edge>> graph, int src, vector<int> &cl,vector<bool> &visit){
    cl.push_back(src);
    visit[src] = true;
    for(Edge e : graph[src]){
        if(visit[e.nbr]== false){
            getall(graph,e.nbr,cl,visit);

        }   
    }
    
}

void display(vector<vector<Edge>> graph, vector<bool> visit){
    vector<vector<int>>component;
    for(int v=0; v < graph.size();v++) {
        if(graph[v].size()&& !visit[v]){
            vector<int> cl;
            getall(graph,v,cl,visit);
            component.push_back(cl);
        }
    }

    int pair =0;
    for(int i =0 ; i < component.size()-1 ; i++){
        for(int j = i+1 ; j < component.size() ; j++)
        pair += component[i].size()*component[j].size();       
    }   
    cout<< pair;

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
    

    vector<bool> visit(vt,false);

    
    display(graph,visit);
}