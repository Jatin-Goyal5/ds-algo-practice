#include<bits/stdc++.h>
using namespace std;

void visitAll(vector<vector<int>> graph,int x , int y,vector<vector<bool>> &visit){
    if(x<0 || y< 0 || x >=graph.size() || y >= graph[x].size()|| graph[x][y] || visit[x][y]){
        return;
    }
    visit[x][y] = true;
    visitAll(graph,x+1,y,visit);
    visitAll(graph,x-1,y,visit);
    visitAll(graph,x,y+1,visit);
    visitAll(graph,x,y-1,visit);
}

void visitVertex(vector<vector<int>> graph,vector<vector<bool>> &visit){
    int island =0;
    for(int i = 0 ; i < graph.size() ; i++){
        for(int j =0 ; j < graph[i].size() ; j++){
            if(!visit[i][j] && !graph[i][j]){
                visitAll(graph,i,j,visit); 
                island++;               
            }
        }
    }   
    cout<< island;
}
int main(){
    int m , n;
    cin>> m>> n;

    vector<vector<int>> graph(m,vector<int>(n));
    vector<vector<bool>> visit(m,vector<bool>(n));
    for(int i = 0 ; i < m ; i++){
        for(int j =0 ; j < n ; j++)
            cin>> graph[i][j];
    }
    visitVertex(graph,visit);


    return 0;
}