#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.length() == 0){
        cout<< asf<< endl;
        return;
    }
    for(int i =0 ; i < str.length(); i++){
        string ans = asf+str[i];
        string sub = str.substr(0,i)+ str.substr(i+1,str.length());
        printPermutations(sub,ans);
    }

}

int main(){
    string str;
    cin>>str;
    printPermutations(str,"");
    
}