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

class Pair{
    public:
    int v;
    int lvl;
    Pair(int v , int lvl){
        this->v = v;
        this->lvl = lvl;
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



void bfsTraversal(vector<vector<Edge>> graph,int src, vector<bool> &visit, int t){
    queue<Pair> nbrq;
    nbrq.push(Pair(src,1));
    int inf =1;
    while(nbrq.size() > 0){
        Pair csrc = nbrq.front();
        if(csrc.lvl > t){
            break;
        }
        nbrq.pop();
        if(visit[csrc.v]){
            continue;
        }
        visit[csrc.v] = true;
        for(Edge e : graph[csrc.v]){
            if(visit[e.nbr] == false){
                nbrq.push(Pair(e.nbr,csrc.lvl+1));
                inf++;
            }
        }
    }
    cout<< inf;
    
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
    int t;
    cin>> t;


    vector<bool> visit(vt,false);

    
    bfsTraversal(graph, src,visit,t);

    // cout<<"true";
    return 0;
}