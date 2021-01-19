#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;

vector<string> gss(string s){
    // write your code here

    if(s.length() == 0){
    vector<string>a;
    a.push_back("");
    return a;
    }
    
    vector<string> ans;
    string s1 = s.substr(1,s.length());
    vector<string> res1=gss(s1);
    char f = s[0];
   for(int i =0 ; i < res1.size() ; i++)
        ans.push_back(res1[i]);
   
   for(int i =0 ; i < res1.size() ; i++)
       ans.push_back(f+res1[i]);
            

    return ans;
   
}

int main(){
    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}