#include<bits/stdc++.h>
using namespace std;

vector<int> par, disc, low,ap;
 int t,dfsc;
void articulation_point(vector<vector<int>> &graph, vector<bool> &visit, int src){
    visit[src] = true;
    disc[src] =low[src] = t;
    t++;
    for(int nbr: graph[src]){
        if(par[src] == nbr){
            
        }else if(visit[nbr] == false){
            par[nbr] = src;
            articulation_point(graph , visit , nbr);
            low[src] = min(low[src], low[nbr]);
            if(par[src] == -1){
                dfsc++;
                if(dfsc >= 2){
                ap[src] = 1;
                }
            }
            
            else if(disc[src] <= low[nbr]){
                ap[src] =1;
            }
        }else if(visit[nbr] == true){
            low[src] = min(disc[nbr],low[src]);
            
            
        }
    }
    
}
int main(){
    int vn, e;
    cin>> vn>>e;
    par = vector<int>(vn);
    disc = vector<int>(vn);
    low = vector<int>(vn);
    ap = vector<int>(vn);
    t =0;
    dfsc;
    vector<vector<int>> graph(vn,vector<int>());
    for(int i =0 ; i < e ; i++){
        int u ,v;
        cin>> u>> v;
        u = u-1;
        v = v-1;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visit(vn);
    
    par[0] =-1;
    int count =0;
    articulation_point(graph,visit,0);
    for(int i =0 ; i < ap.size() ; i++)
        if(ap[i] == 1 ){
            count++;
        }
    cout<< count<< endl;
}
