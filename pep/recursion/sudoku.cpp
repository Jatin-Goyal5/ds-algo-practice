#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &sudoku , int i , int j, int op){
    for(int cr=0 ; cr < sudoku.size() ; cr++){
        if(sudoku[cr][j] == op)
            return false;
        if(sudoku[i][cr] == op)
            return false;
    }

    int ir = (i/3)*3;
    int ic = (j/3)*3;

    for(int  r = 0 ; r < 3 ; r++){
        for(int c =0 ; c < 3 ; c++)
            if(sudoku[ir+r][ic+c] == op)
                return false;
    }

    return true;
}

void helper(vector<vector<int>> &sudoku , int i , int j){
    if(j == sudoku.size()){
        i++;
        j=0;
    }
    if(i == sudoku.size())
    {
        return;
    }
    if(sudoku[i][j] == 0){
        for(int op = 1; op <=9 ; op++){
            if(isSafe(sudoku,i,j,op)){
                sudoku[i][j] = op;
                helper(sudoku,i,j+1);
                sudoku[i][j] = 0;
            }
        }
    }
}
int main(){
    int n =10;
    // cin>> n;
    vector<vector<int>> sudoku(n,vector<int>(n));
    for(int i =0 ; i < n ; i++){
        for(int j =0 ;j < n; j++)
            cin>> sudoku[i][j];
    }
    return 0;
}