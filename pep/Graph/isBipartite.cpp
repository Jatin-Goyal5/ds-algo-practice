// every non - cyclic graph is bipartite
// and also if a graph is cyclic but have even size cycle then it also a bipartite
// odd cyclic graph is not bipartite

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
    Pair(int v , string psf){
        this->v = v;
        this->psf = psf;
    }
};

void addEdge(int src , int nbr , int wt, vector<vector<Edge>>&v){
    Edge e1=  Edge(src,nbr ,wt);
    Edge e2=  Edge(nbr,src ,wt);
    v[src].push_back(e1);
    v[nbr].push_back(e2);
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


bool bfsTraversal(vector<vector<Edge>> graph,int src, vector<bool> &visit){
    queue<Pair> nbrq;
    nbrq.push(Pair(src,to_string(src)));
    while(nbrq.size() > 0){
        //remove
        Pair cv = nbrq.front();
        nbrq.pop();

        // check if current vertex is already visited 
        // if visited then there is cycle 
        if(visit[cv.v]){
            // check cycle is odd or even
            // if odd then not bipartite
            // if even then bipartite
            if((cv.psf).length()%2 == 1 ){
                return false;
            }else{
                 return true;
            }
           
        }
        // mark
        visit[cv.v] = true;
        //add
        for(Edge e : graph[cv.v]){
            if(visit[e.nbr] == false){
                nbrq.push(Pair(e.nbr,cv.psf+to_string(e.nbr)));
            }
        }
    }
    return true;    
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
    
    bool check = false;
    for(int i =0 ; i < vt ; i++){
        vector<bool> visit(vt,false);
        check =bfsTraversal(graph,i,visit); 
        if(!check){
            check = false ;
            break;
        }
    }
        
    if(check)
        cout<< "true";
    else
        cout<<"false";

    // cout<<"true";
    return 0;
}