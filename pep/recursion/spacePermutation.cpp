//input -> abc

// output 
//a b c
//a bc 
//ab c 
//abc


#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void helper(string s , int index , string asf){
    if(index == s.length()){
        res.push_back(asf);
        // cout<< asf<< endl;
        return ;
    }
    // agar string empty hai toh space cahiye hi nahi shuru mai 
    if(asf != ""){
        helper(s,index+1,asf+" "+s[index]); // asf+" "+B
    }
    helper(s,index+1, asf+s[index]);        //asf+B;
}


void permutation(string S){
    // Code Here
    string asf ="";
    helper(S,0,asf);
    sort(res.begin(),res.end());
  
}
int main(){
    string s;
    cin>> s;
    permutation(s);
    for(string i : res){
        cout<< i<< endl;
    }

    return 0;

}