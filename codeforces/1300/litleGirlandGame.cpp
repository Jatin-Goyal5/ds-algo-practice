#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>> s;
    vector<int> freq(27);
    for(char ch :s ){
        freq[ch-'a']++;
    }
    // for(int i =0 ; i < 26 ; i++)
    //     cout<< freq[i];
    int count=0;
    for(int i =0 ; i < freq.size() ; i++){
        if(freq[i]%2 == 1){
            count++;
        }
    }
    if(count ==0){
        cout<<"First"<< endl;
        return 0;
    }
    if(count%2 == 0){
        cout<<"Second"<< endl;
    }else{
        cout<<"First"<< endl;
    }
    return 0;
}