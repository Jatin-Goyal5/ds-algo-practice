#include<bits/stdc++.h>
using namespace std;

bool isSafe( int i , int j, vector<vector<int>> m ){
    if(i >=0 && j >= 0 && i < m.size() && j < m.size() && m[i][j] == 1 )
        return true;
    return false;
}

void helper(int r , int c , vector<vector<int>> m , string asf , vector<string> &res){
    if(r  == m.size()-1 &&c == m.size()-1 &&m[r][c] == 1){
        
        res.push_back(asf);
        
        
        return;
    }
    
    
    if(isSafe(r,c,m)){
        m[r][c] = 0;
        helper(r+1,c,m ,asf+"D",res);
    
        helper(r,c-1,m ,asf+"L",res);    
        helper(r,c+1,m ,asf+"R",res);
        
        
        helper(r-1,c,m ,asf+"U",res);
        m[r][c] =1;
    }
    // cout<< "hello"<< endl;
    
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    
    // Your code goes here
    // cout<< n<< m.size();
    vector<string> res;
    helper(0,0,m,"",res);
    return res;
    
}

int main(){
    int n;
    cin>> n;
    vector<vector<int>> m(n,vector<int>(n));
    for(int i =0 ; i < n ; i++)
        for(int j =0 ; j < n ; j++)
            cin>> m[i][j];

    vector<string> res = findPath(m,n); 
    for(int i =0 ; i < res.size() ; i++){
        cout<< res[i]<< endl;
    }       
}