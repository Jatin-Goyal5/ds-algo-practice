// 1. You are given a string str.
// 2. You are required to calculate and print the count of subsequences of the nature a+b+c+.
// For abbc -> there are 3 subsequences. abc, abc, abbc
// For abcabc -> there are 7 subsequences. abc, abc, abbc, aabc, abcc, abc, abc.

#include<bits/stdc++.h>
using namespace std;
void sub(string s){
    int a=0;
    int ab =0;
    int abc=0;
    
    for(int i =0 ; i < s.length() ; i++){
        if(s[i] == 'a'){
            a= (2*a)+1;
        }else if(s[i] == 'b'){
            ab = (2*ab)+a;
        }else if(s[i] == 'c'){
            abc = (2*abc)+ab;
        }
    }
    cout<< abc;
}
int main(){
    string s;
    cin>> s;
    sub(s);
    return 0;
}