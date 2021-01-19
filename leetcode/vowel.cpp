// Ques
// Given an integer n, return the number of strings of length n 
//that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

// A string s is lexicographically sorted if for all valid i,
// s[i] is the same as or comes before s[i+1] in the alphabet.

//example
// Input: n = 2
// Output: 15
// Explanation: The 15 sorted strings that consist of vowels only are
// ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
// Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.

#include<bits/stdc++.h>
using namespace std ;
int countVowel(int n){
    return   (((n+1)*(n+2)*(n+3)*(n+4))/24);
}
int main(){
    int n;
    cin>> n;
    cout<< countVowel(n);
}