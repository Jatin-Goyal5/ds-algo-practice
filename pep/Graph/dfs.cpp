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
    Pair(int v, string psf){
        this->v= v;
        this->psf= psf;
    }
};

void dfs(vector<vector<Edge>> graph,int src , vector<bool> visit){
    stack<Pair> st;
    st.push(Pair(src,to_string(src)));
    while(st.size()> 0){
        Pair cv = st.top();
        st.pop();
        if(visit[cv.v])
            continue;
        visit[cv.v] = true;
        cout<< cv.v<< "@ "<< cv.psf<< endl;
        for(Edge e : graph[cv.v]){
            if(!visit[e.nbr])
                st.push(Pair(e.nbr,cv.psf+to_string(e.nbr)));
        }
    }
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
    int qsrc;
    cin>> qsrc;
    dfs(graph,qsrc,visit);
    
}