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
    int wt;
    string psf;
    Pair(int wt,string psf){
        this->wt = wt;
        this->psf = psf;
    }

   
};
bool operator<(const Pair& p1, const Pair& p2)
{
 
    
    return p1.wt > p2.wt;
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
    string spath;
    int spathwt = INT_MAX;
    string lpath;
    int lpathwt = INT_MIN;
    string cpath;
    int cpathwt = INT_MAX;
    string fpath;
    int fpathwt = INT_MIN;
    priority_queue<Pair> findk;
void multiSolver(vector<vector<Edge>> graph ,int src , int dest,string ansf,int wt,int criteria,int kth,vector<bool> &visit){
    if(src == dest){
        Pair p = Pair(wt,ansf);
        if(wt > lpathwt){
            lpath = ansf;
            lpathwt = wt;
        }
        if(wt < spathwt){
            spath = ansf;
            spathwt = wt;
        }

        if(wt <cpathwt && wt >criteria){
            cpathwt = wt;
            cpath = ansf;
        }
        if(wt >fpathwt && wt <criteria){
            fpathwt = wt;
            fpath = ansf;
        }
        if(findk.size() <kth ){
            
            findk.push(p);
        }else if(findk.top().wt < wt){
            findk.pop();
            findk.push(p);            
        }
        
        // cout<< ansf<< endl;
    }

    visit[src] = true;
    for(Edge edge : graph[src]){
        string nnbr = to_string(edge.nbr);
        if(visit[edge.nbr]== false){    
            multiSolver(graph,edge.nbr,dest,ansf+nnbr,wt+edge.wt,criteria,kth,visit);
        }
    }
    visit[src] = false;
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
    int criteria;
    cin>> criteria;

    int kth;
    cin>> kth;

    
    // cout<< hasPath(graph,0,6,visit);
    multiSolver(graph,qsrc,qdest,to_string(qsrc)+"",0,criteria,kth,visit);
    cout<<"Smallest Path = " <<spath << "@"<<spathwt<< endl;
    cout<<"Largest Path = " <<lpath << "@"<<lpathwt<< endl;
    cout<<"Just Larger Path than "<<criteria<<" = "<< cpath<< "@"<<cpathwt<< endl;
    cout<<"Just Smaller Path than "<<criteria<<" = "<<fpath<<"@"<< fpathwt<< endl;
    cout<< kth<<"th largest path = "<<findk.top().psf<<"@"<<findk.top().wt;
}

