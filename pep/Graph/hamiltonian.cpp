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
    v[nbr].push_back(e2);
}



void isConnected(vector<vector<Edge>> graph,int src,string psf,int osrc, vector<bool> &visit){
    if(psf.length() == graph.size()){
        cout<< psf;
        for(Edge e : graph[src]){
        if(e.nbr== osrc){
                cout<<"*"<< endl;
                return;
            }      
        }
        cout<<"."<< endl;
        return;
    }
    visit[src] = true;
    for(Edge e : graph[src]){
        if(visit[e.nbr]== false){
            isConnected(graph,e.nbr,psf+to_string(e.nbr),osrc,visit);
            visit[e.nbr] = false;

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

    int src;
    cin>> src;    

    vector<bool> visit(vt,false);

    
    isConnected(graph, src, to_string(src)+"",src,visit);

    // cout<<"true";
    return 0;
}