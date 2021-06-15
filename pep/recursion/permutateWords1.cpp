#include<bits/stdc++.h>
using namespace std;

void permutate(string s, string asf ,unordered_map<char, int> mp, int lc){
    for(int i =lc+1 ; i < s.length() ; i++){
        if(mp[s[i]]){
            permutate(s,asf+s[i],mp,i);
        }
    }
}
int main(){
    string s;
    cin>> s;
    unordered_map<char,int> mp;
    for(char ch : s){
        mp[ch]++;
    }
    return 0;
    
}