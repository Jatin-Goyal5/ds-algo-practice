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
    string psf;
    int pw;
    Pair(int v , string psf,int pw){
        this->v = v;
        this->psf = psf;
        this->pw = pw;
    }
};

bool operator <(Pair p1 ,Pair p2){
    return p1.pw>p2.pw;
}
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



void bfsTraversal(vector<vector<Edge>> graph,int src){
    vector<bool> visit(graph.size(),false);
    priority_queue<Pair> nbrq;
    nbrq.push(Pair(src,to_string(src),0));

    while(nbrq.size() > 0){
        Pair csrc = nbrq.top();
        nbrq.pop();
        if(visit[csrc.v]){
            continue;
        }
        visit[csrc.v] = true;

        cout<< csrc.v <<" via "<< csrc.psf<<" @ "<< csrc.pw<< endl; 
        
        for(Edge e : graph[csrc.v]){
            if(visit[e.nbr] == false){
                nbrq.push(Pair(e.nbr,csrc.psf+to_string(e.nbr),csrc.pw+ e.wt));
                // cout<< csrc.psf<< " ";

            }
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

    
    bfsTraversal(graph, src);

    // cout<<"true";
    return 0;
}