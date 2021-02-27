// 1. You are given a string str of digits. (will never start with a 0)
// 2. You are required to encode the str as per following rules
//     1 -> a
//     2 -> b
//     3 -> c
//     ..
//     25 -> y
//     26 -> z
// 3. You are required to calculate and print the count of encodings for the string str.

//      For 123 -> there are 3 encodings. abc, aw, lc
//      For 993 -> there is 1 encoding. iic 
//      For 013 -> This is an invalid input. A string starting with 0 will not be passed.
//      For 103 -> there is 1 encoding. jc
//      For 303 -> there are 0 encodings. But such a string maybe passed. In this case 
//      print 0.

#include<bits/stdc++.h>
using namespace std;
void solve(string s){
    vector<int> dp(s.length());
    //cout<< s.substr(0,2);
    dp[0] =1;
   
    for(int i =1 ; i < dp.size(); i++){
         if(s[i] == '0' && s[i-1] == '0'){
            dp[i] =0;
            
        }else if(s[i] == '0' && s[i-1] != '0'){
            if(s[i-1] == '1' || s[i-1] == '2'){
                dp[i] = i >= 2? dp[i-2]:1;    
            }else{
                dp[i]= 0;
            }
            
        }else if(s[i] != '0' && s[i-1] == '0'){
            dp[i] = dp[i-1];
        }else{
            dp[i] =dp[i-1];
            char c= s[i];
            char l =s[i-1];
             auto c3 = std::string(1,l)+c;
           
        
            int cond =stoi(c3);
            // cout<< cond<<" ";
            if(cond <= 26){
                dp[i] += (i >= 2 ? dp[i-2]:1);
               
            }
            
            
        }
    }
    cout<< dp[s.length()-1];
    
}

int main(){
    string s;
    cin>> s;
    solve(s);
    
    return 0;
}