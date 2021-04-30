#include<bits/stdc++.h>
using namespace std;
class Edge{
    public:
    int src;
    int nbr;
    int wt;
    Edge(int src , int nbr , int wt){
        this->src = src;
        this->nbr = nbr;
        this->wt = wt;
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


void addEdge(int src , int nbr , int wt, vector<vector<Edge>>&v){
    Edge e1=  Edge(src,nbr ,wt);
    Edge e2=  Edge(nbr,src ,wt);
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
    
    cout<< "[";
    for(int i =0 ; i < component.size() ; i++){
        cout<< "[";
        for(int j =0 ; j < component[i].size() ; j++)
            if(j == component[i].size()-1)
                cout<< component[i][j];
            else
                cout<<component[i][j]<<", ";
        if(i == component.size()-1)
                cout<<"]";
        else
            cout<< "], ";
    }

    cout<< "]";

    

}
int main(){
    int vt, eg;
    cin>> vt>> eg;

    vector<vector<Edge>> graph(vt,vector<Edge>());

    for(int i =0 ; i < eg ; i++){
        int src, dest,wt;
        cin>> src>> dest>> wt;
        addEdge(src,dest,wt,graph);
    }
    

    vector<bool> visit(vt,false);

    
    display(graph,visit);
}