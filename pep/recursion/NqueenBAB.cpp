#include<bits/stdc++.h>
using namespace std;
void permutate(int n, int qp,string asf,vector<vector<bool>> check,vector<bool>column,vector<bool> ldig, vector<bool> rdig){
    if(qp == n){
        cout<< asf<< endl;
        return;
    }

    for(int i =0 ; i < n ; i++){
        int right = qp+i;
        int left = qp-i + check.size()-1;
        if(!check[qp][i] && !ldig[left] && !rdig[right] && !column[i]){
            column[i] = true;
            check[qp][i] = true;
            ldig[left] = true;
            rdig[right] = true;
            permutate(n,qp+1,asf+to_string(qp)+"-"+to_string(i)+",",check,column,ldig,rdig);
            check[qp][i] = false;
            ldig[left] = false;
            rdig[right] = false;
            column[i] = false;
        }
        
            // check[i][qp] = false;
        
    }
   
}
int main(){
    int n;
    cin>> n;
    vector<vector<bool>> check(n,vector<bool>(n));
    vector<bool> ldig(2*n+1);
    vector<bool> rdig(2*n+1);
    vector<bool> column(n);
    permutate(n,0, "",check,column,ldig,rdig);
    return 0;
}