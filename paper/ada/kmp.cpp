#include <bits/stdc++.h>
using namespace std;
void longestpalindrome(char* pat, int M, int* lps);
void Kmp(char* str2, char* str1)
{
    int M = strlen(str2);
    int N = strlen(str1);
    int lps[M];
    longestpalindrome(str2, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        if (str2[j] == str1[i]) {
        j++;
        i++;
        }
        if (j == M) {
        cout<<" pattern found at index "<< i - j;
        j = lps[j - 1];
        }
        else if (i < N && str2[j] != str1[i]) {
            if (j != 0)
        j = lps[j - 1];
        else
        i = i + 1;
        }
    }
}
void longestpalindrome(char* str2, int M, int* lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (str2[i] == str2[len]) {
        len++;
        lps[i] = len;
        i++;
        }
        else{
        if (len != 0) {
            len = lps[len - 1];
        }
        else{
            lps[i] = 0;
            i++;
        }
        }
    }
}
int main()
{
char str1[] = "ABABDABACDABABCABAB";
char str2[] = "ABABCABAB";
Kmp(str2, str1);
return 0;
}