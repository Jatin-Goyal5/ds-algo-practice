#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,sx,sy ,ex,ey;
    cin>> t>>sx>> sy>> ex>> ey;
    string s;
    cin>>s;
    vector<int> dir(27);
    int sd=0 , w=0 , n =0,e =0;
    if(sx>ex){
        w = sx-ex;//move west;
    }
    if(sy >ey){
        sd= sy-ey;//move south
    }
    if(sy <ey){
        n= ey-sy;//move north
    }
    if(sx<ex){
        e= ex-sx;//move east;
    }
    
    int i =0;
    for(char ch : s){
        if(sd+n+w+e == 0){
            cout<< i;
            return 0;
        }
        if(ch == 'S' && sd >0){
            sd--;
        }else if(ch == 'N' && n >0){
            n--;
        }else if(ch == 'W'&& w >0){
            w--;
        }else if(ch == 'E'&& e >0){
            e--;
        }
        i++;
       
    }
    if(sd+n+w+e == 0){
            cout<< t;
            return 0;
        }
    
        cout<< "-1";
        
    
    return 0;
}