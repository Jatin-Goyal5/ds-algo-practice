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
    int aq;
    int ws;
    Pair(int v , int aq, int ws){
        this->v = v;
        this->aq = aq;
        this->ws = ws;
    }
};

bool operator <(Pair p1 ,Pair p2){
    return p1.ws > p2.ws;
}

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




void bfsTraversal(vector<vector<Edge>> graph, vector<bool> &visit){
   priority_queue<Pair> npq;
   npq.push(Pair(0, -1 , 0));
   while (npq.size()> 0)
   {
       Pair cv = npq.top();
       npq.pop();
       if(visit[cv.v]){
           continue;
       }
       if(cv.aq != -1)
            cout<< "["<<cv.v << "-"<< cv.aq<< "@"<< cv.ws<<"]"<< endl;
       visit[cv.v] = true;
       for(Edge e : graph[cv.v]){
           if(!visit[e.nbr]){
               npq.push(Pair(e.nbr,cv.v , e.wt));
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

    vector<bool> visit(vt,false);

    
    bfsTraversal(graph,visit);

    // cout<<"true";
    return 0;
}