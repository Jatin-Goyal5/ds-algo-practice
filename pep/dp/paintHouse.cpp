// 1. You are given N houses, each house can be painted with 3 different colours: red, blue or green
//   2. Cost of painting each house a certainc colour is different and is given as an N x 3 matrix to you
//   3. You need to find the minimum amount spent on painting all the houses such that no 2 adjacent houses have the same colour
//   4. Input and output is handled for you
//   5. It is a functional problem ,please do not modify main(

#include<iostream>
#include<vector>
using namespace std;

// -----------------------------------------------------
// This is a functional problem. Only this function has to be written.
// This function takes as input 2D array
// It should return the required output
int minCost(vector<vector<int>>& costs) {
    //Write your code here
    int r=costs[0][0], b= costs[0][1],g= costs[0][2];
//   cout<< r<<" "<<b<<" "<< g<< endl;
    for(int i =1 ; i < costs.size() ; i++){
        
        int cr= min(b,g)+costs[i][0];
        int cb= min(r,g)+costs[i][1];
        int cg= min(r,b)+costs[i][2];
        r=cr;
        g= cg;
        b= cb;
    //   cout<< r<<" "<<b<<" "<< g<< endl;
    }
    
    return min(r,min(b,g));
}

int main(int argc,char** argv) {
    int n ;
    cin>>n;
    vector<vector<int>> costs(n,vector<int>(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>costs[i][j];
        }
    }
    cout<<minCost(costs)<<endl;
}