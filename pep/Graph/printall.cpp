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

void printAll(vector<vector<Edge>> graph ,int src , int dest,string ansf,vector<bool> &visit){
    if(src == dest){
        cout<< ansf<< endl;
    }

    visit[src] = true;
    for(Edge edge : graph[src]){
        string nnbr = to_string(edge.nbr);
        if(visit[edge.nbr]== false){    
            printAll(graph,edge.nbr,dest,ansf+nnbr,visit);
        }
    }
    visit[src] = false;
}

void addEdge(int src , int nbr , int wt, vector<vector<Edge>>&v){
    Edge e1=  Edge(src,nbr ,wt);
    Edge e2=  Edge(nbr,src ,wt);
    v[src].push_back(e1);
    v[nbr].push_back(e2);
}

void display(vector<vector<Edge>> graph){
    for(int v=0; v < graph.size();v++) {
           cout<<v << " -> ";
            for(int e=0; e < graph[v].size();e++) {
                Edge edge = graph[v].at(e);
                cout<<(edge.src)<<" - "<< edge.nbr <<" @ "<<edge.wt <<" , ";
            }
            cout<< endl;
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
    int qsrc ,qdest;
    cin>> qsrc>> qdest;
    
    // cout<< hasPath(graph,0,6,visit);
    printAll(graph,qsrc,qdest,"",visit);
}

