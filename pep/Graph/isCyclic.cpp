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



bool bfsTraversal(vector<vector<Edge>> graph,int src, vector<bool> &visit){
    queue<Pair> nbrq;
    nbrq.push(Pair(src,to_string(src)));
    while(nbrq.size() > 0){
        Pair cv = nbrq.front();
        nbrq.pop();
        if(visit[cv.v]){
            cout<<"Graph -> " <<cv.psf<< endl;
            return true;
        }
        visit[cv.v] = true;

        for(Edge e : graph[cv.v]){
            if(visit[e.nbr] == false){
                nbrq.push(Pair(e.nbr,cv.psf+to_string(e.nbr)));
            }
        }
    }
    return false;    
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
        if(check){
            check = true;
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