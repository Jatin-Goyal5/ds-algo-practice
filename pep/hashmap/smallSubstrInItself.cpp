#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1 ,s2="";
    cin>> s1;
    unordered_map<char , int> mp1,mp2;
    int val = s1.length()-1;
    vector<bool> a(26,false);
    for(char ch: s1){
        if(a[ch-'0']== false){
            a[ch-'0'] = true;
            mp1[ch]= 1;
            s2 += ch;
        }
     
    }
    int i = -1,j=-1, oi=-1 ,oj =-1 ,minlen =INT_MAX,src = 0,dst = s2.length();
    
    while( i < val){
        // acquire
        while(i < val && src < dst){
            i++;
            // cout<< "hello";
            mp2[s1[i]]++;
            if(mp1.find(s1[i]) != mp1.end())
            if(mp2[s1[i]] <= mp1[s1[i]]){
                src++;
            }
        }
        
        while( j < i && src == dst){
            int len = i-j;
            if(len < minlen){
                oi = i;
                oj = j;
                minlen = len;
            }
            j++;
            if(mp2[s1[j]] == 1){
                mp2.erase(s1[j]);
            }else{
                mp2[s1[j]]--;
            }
            if(mp1.find(s1[j]) != mp1.end())
            if(mp2[s1[j]] < mp1[s1[j]]){
                src--;
            }
        }
        
    }
   
    cout<< minlen<< endl;
    
    
    return 0;
}