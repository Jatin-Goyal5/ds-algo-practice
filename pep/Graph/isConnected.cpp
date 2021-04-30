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



void isConnected(vector<vector<Edge>> graph,int src, vector<bool> &visit){
    visit[src] = true;
    for(Edge e : graph[src]){
        if(visit[e.nbr]== false){
            isConnected(graph,e.nbr,visit);

        }   
    }
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

    
    isConnected(graph,0,visit);

    for(int i =0 ; i < visit.size() ; i++){
        if(visit[i] == false){
            cout<< "false";
            return 0;
        }
    }

    cout<<"true";
    return 0;
}